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
* attack.h                                                                     *
*                                                                              *
* AUTHOR                                                                       *
* noptrix@nullsecurity.net                                                     *
*                                                                              *
*******************************************************************************/


#ifndef ATTACK_H
#define ATTACK_H


/*******************************************************************************
 * INCLUDES
 ******************************************************************************/


/* sys includes */


/* own includes */
#include "opts.h"
#include "http.h"


/*******************************************************************************
 * MACROS
 ******************************************************************************/


/* hit line */
#define __HIT(log) \
  if (log == stderr) {\
    CLOG(log, BGREEN"\r[*] "CNORM"%ld - %6.0lf%c %s\n", code, bytes, suf, \
         job->url); \
  } \
  else {\
    CLOG(log, "[*] %ld - %6.0lf%c %s\n", code, bytes, suf, job->url); \
  }

/* status line */
#define PERCENT (double) (curjob * 100) / (double) job->num_jobs
#define __STATUS \
  CLOG(stderr, "\r"BBLUE"[+]"CNORM" scanning %lu / %lu (%.2f%%)", curjob, \
       job->num_jobs, PERCENT)


/*******************************************************************************
 * VARS, EXT VARS, TYPEDEFS
 ******************************************************************************/


/* our attack job */
typedef struct {
  unsigned int delay;
  wildcard_T wcard;
  FILE *logfile;
  unsigned char smart;
  size_t num_ex_codes;
  size_t num_jobs;
  long int *http_ex_codes;
  unsigned char rand_ua;
  const char *url;
  CURL *eh;
  CURLSH *sh;
  CURLcode *res;
} job_T;


/*******************************************************************************
 * FUNCTION PROTOTYPES
 ******************************************************************************/


/* init and launch attack */
void launch_attack(opts_T *);


#endif

