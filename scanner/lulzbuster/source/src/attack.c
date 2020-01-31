/*******************************************************************************
*                ____                     _ __                                 *
*     ___  __ __/ / /__ ___ ______ ______(_) /___ __                           *
*    / _ \/ // / / (_-</ -_) __/ // / __/ / __/ // /                           *
*   /_//_/\_,_/_/_/___/\__/\__/\_,_/_/ /_/\__/\_, /                            *
*                                            /___/ team                        *
*                                                                              *
* lulzbuster                                                                   *
* A very fast and smart web-dir/file enumeration tool written in C.            *
*                                                                              *
* FILE                                                                         *
* attack.c                                                                     *
*                                                                              *
* AUTHOR                                                                       *
* noptrix@nullsecurity.net                                                     *
*                                                                              *
*******************************************************************************/


/* sys includes */
#include <unistd.h>


/* own includes */
#include "attack.h"
#include "log.h"
#include "wrapper.h"
#include "thpool.h"
#include "log.h"
#include "error.h"
#include "lulzbuster.h"
#include "misc.h"


/* static function prototypes */
static void *attack(job_T *);


/* attack worker thread */
static void *attack(job_T *job)
{
  curl_off_t real_size = 0, size = 0;
  register double bytes = 0;
  static size_t curjob = 0;
  register size_t i = 0;
  long code = 0;
  char suf = 'B';

  if (curjob % 337 == 0) {
    __STATUS;
  }
  curjob++;

  /* overwrite default UA with random ones if requested */
  if (job->rand_ua == ON) {
    curl_easy_setopt(job->eh, CURLOPT_USERAGENT, get_rand_useragent());
  }

  /* make http request */
  if (job->delay != 0) {
    sleep(job->delay);
  }
  do_req(job->url, job->eh, job->sh);

  /* get needed infos from http response */
  curl_easy_getinfo(job->eh, CURLINFO_RESPONSE_CODE, &code);
  curl_easy_getinfo(job->eh, CURLINFO_SIZE_DOWNLOAD_T, &size);

  /* convert sizes */
  real_size = size;
  bytes = size >= KBYTE ? size = (double) size / KBYTE, suf = 'K' : size;
  bytes = size >= MBYTE ? size = (double) size / MBYTE, suf = 'M' : size;
  bytes = size >= GBYTE ? size = (double) size / GBYTE, suf = 'G' : size;

  /* print shit we are interested in. exclude given status codes.
   * TODO: this shit slows down our attack. we need to find another way... */
  for (i = 0; i < job->num_ex_codes; ++i) {
    if (code == job->http_ex_codes[i]) {
      curl_easy_cleanup(job->eh);
      return NULL;
    }
  }

  if (code != 0 && code != HTTP_NOT_FOUND) {
    /* do smart checks */
    if (job->smart == TRUE) {
      /* return NULL if equal to our initial wildcard-probe size */
      if (code == job->wcard.resp_code) {
        if (real_size == job->wcard.resp_size) {
          curl_easy_cleanup(job->eh);
          return NULL;
        }
      }
    }
    /* found hit! */
    __HIT(job->logfile);
  }

  /* destroy easy handler */
  curl_easy_cleanup(job->eh);

  return NULL;
}


/* start scanning */
void launch_attack(opts_T *opts)
{
  register size_t i = 0;
  job_T **job = NULL;
  threadpool thpool = NULL;
  FILE *logfile = stderr;

  /* alloc buf for job structs and create/init threadpool */
  job = xcalloc(opts->num_attack_urls, sizeof(*job));
  thpool = thpool_init(opts->threads);

  /* init phtread locks */
  if (init_locks() == FALSE) {
    free(job);
    thpool_destroy(thpool);
    free_lulzbuster(opts);
    __EXIT_FAILURE;
  }

  /* set !stderr logfile */
  if (opts->logfile) {
    logfile = fopen(opts->logfile, "a+");
    if (!logfile) {
      free(job);
      thpool_destroy(thpool);
      free_lulzbuster(opts);
      err(E_OLOG);
    }
  }

  /* initiate needed opts, add attacker threads to pool and fire shit */
  for (i = 0; i < opts->num_attack_urls; ++i) {
    job[i] = xcalloc(1, sizeof(job_T));
    job[i]->delay = opts->delay;
    job[i]->wcard = opts->wcard;
    job[i]->logfile = logfile;
    job[i]->smart = opts->smart;
    job[i]->num_jobs = opts->num_attack_urls;
    job[i]->http_ex_codes = opts->http_ex_codes;
    job[i]->num_ex_codes = opts->num_http_ex_codes;
    job[i]->rand_ua = opts->rand_ua;
    job[i]->url = opts->attack_urls[i];
    job[i]->eh = curl_easy_duphandle(opts->curl->eh);
    job[i]->sh = opts->curl->sh;
    thpool_add_work(thpool, (void *) attack, (void *) job[i]);
  }

  /* wait for threads to finish, destroy thpool afterwards and destroy locks */
  thpool_wait(thpool);
  thpool_destroy(thpool);
  kill_locks();

  /* free job */
  for (i = 0; i < opts->num_attack_urls; ++i) {
    free(job[i]);
  }
  free(job);
  if (opts->logfile) {
    if (!fclose(logfile)) {
      err(W_CLOG);
    }
  }
  SLOG("\n");

  return;
}

