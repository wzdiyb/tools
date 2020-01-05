macro createStringBruteforcing location
{
	 mov [location+0],'B'
	 mov [location+1],'r'
	 mov [location+2],'u'
	 mov [location+3],'t'
	 mov [location+4],'e'
	 mov [location+5],'f'
	 mov [location+6],'o'
	 mov [location+7],'r'
	 mov [location+8],'c'
	 mov [location+9],'i'
	 mov [location+10],'n'
	 mov [location+11],'g'
	 mov [location+12],' '
	 mov [location+13],'K'
	 mov [location+14],'e'
	 mov [location+15],'y'
	 mov [location+16],0
}

macro createStringSettingPermissions location
{
	 mov [location+0],'S'
	 mov [location+1],'e'
	 mov [location+2],'t'
	 mov [location+3],'t'
	 mov [location+4],'i'
	 mov [location+5],'n'
	 mov [location+6],'g'
	 mov [location+7],' '
	 mov [location+8],'S'
	 mov [location+9],'e'
	 mov [location+10],'c'
	 mov [location+11],'t'
	 mov [location+12],'i'
	 mov [location+13],'o'
	 mov [location+14],'n'
	 mov [location+15],' '
	 mov [location+16],'P'
	 mov [location+17],'e'
	 mov [location+18],'r'
	 mov [location+19],'m'
	 mov [location+20],'i'
	 mov [location+21],'s'
	 mov [location+22],'s'
	 mov [location+23],'i'
	 mov [location+24],'o'
	 mov [location+25],'n'
	 mov [location+26],'s'
	 mov [location+27],0
}

macro createStringOrdinal location
{
	 mov [location+0],'O'
	 mov [location+1],'r'
	 mov [location+2],'d'
	 mov [location+3],'i'
	 mov [location+4],'n'
	 mov [location+5],'a'
	 mov [location+6],'l'
	 mov [location+7],':'
	 mov [location+8],' '
	 mov [location+9],0
}

macro createStringName location
{
	 mov [location+0],'N'
	 mov [location+1],'a'
	 mov [location+2],'m'
	 mov [location+3],'e'
	 mov [location+4],':'
	 mov [location+5],' '
	 mov [location+6],0
}

macro createStringProcessImportDirectory location
{
	 mov [location+0],'P'
	 mov [location+1],'r'
	 mov [location+2],'o'
	 mov [location+3],'c'
	 mov [location+4],'e'
	 mov [location+5],'s'
	 mov [location+6],'s'
	 mov [location+7],'i'
	 mov [location+8],'n'
	 mov [location+9],'g'
	 mov [location+10],' '
	 mov [location+11],'I'
	 mov [location+12],'m'
	 mov [location+13],'p'
	 mov [location+14],'o'
	 mov [location+15],'r'
	 mov [location+16],'t'
	 mov [location+17],' '
	 mov [location+18],'D'
	 mov [location+19],'i'
	 mov [location+20],'r'
	 mov [location+21],'e'
	 mov [location+22],'c'
	 mov [location+23],'t'
	 mov [location+24],'o'
	 mov [location+25],'r'
	 mov [location+26],'y'
	 mov [location+27],':'
	 mov [location+28],0
}

macro createStringFoundImportTable location
{
	 mov [location+0],'I'
	 mov [location+1],'m'
	 mov [location+2],'p'
	 mov [location+3],'o'
	 mov [location+4],'r'
	 mov [location+5],'t'
	 mov [location+6],' '
	 mov [location+7],'T'
	 mov [location+8],'a'
	 mov [location+9],'b'
	 mov [location+10],'l'
	 mov [location+11],'e'
	 mov [location+12],':'
	 mov [location+13],0
}

macro createStringLoadingFilesAPIs location
{
	 mov [location+0],'L'
	 mov [location+1],'o'
	 mov [location+2],'a'
	 mov [location+3],'d'
	 mov [location+4],'i'
	 mov [location+5],'n'
	 mov [location+6],'g'
	 mov [location+7],' '
	 mov [location+8],'A'
	 mov [location+9],'P'
	 mov [location+10],'I'
	 mov [location+11],'s'
	 mov [location+12],0
}

macro createStringMappingFileInMemory location
{
	 mov [location+0],'M'
	 mov [location+1],'a'
	 mov [location+2],'p'
	 mov [location+3],'p'
	 mov [location+4],'i'
	 mov [location+5],'n'
	 mov [location+6],'g'
	 mov [location+7],' '
	 mov [location+8],'F'
	 mov [location+9],'i'
	 mov [location+10],'l'
	 mov [location+11],'e'
	 mov [location+12],' '
	 mov [location+13],'i'
	 mov [location+14],'n'
	 mov [location+15],'t'
	 mov [location+16],'o'
	 mov [location+17],' '
	 mov [location+18],'M'
	 mov [location+19],'e'
	 mov [location+20],'m'
	 mov [location+21],'o'
	 mov [location+22],'r'
	 mov [location+23],'y'
	 mov [location+24],0
}

macro createStringLoaded location
{
	 mov [location+0],'L'
	 mov [location+1],'o'
	 mov [location+2],'a'
	 mov [location+3],'d'
	 mov [location+4],'e'
	 mov [location+5],'d'
	 mov [location+6],' '
	 mov [location+7],0
}

macro createStringLoadedPEHeader location
{
	 mov [location+0],'S'
	 mov [location+1],'e'
	 mov [location+2],'t'
	 mov [location+3],' '
	 mov [location+4],'I'
	 mov [location+5],'m'
	 mov [location+6],'a'
	 mov [location+7],'g'
	 mov [location+8],'e'
	 mov [location+9],' '
	 mov [location+10],'w'
	 mov [location+11],'r'
	 mov [location+12],'i'
	 mov [location+13],'t'
	 mov [location+14],'a'
	 mov [location+15],'b'
	 mov [location+16],'l'
	 mov [location+17],'e'
	 mov [location+18],':'
	 mov [location+19],0
}

macro createStringVerifyPE location
{
	 mov [location+0],'V'
	 mov [location+1],'e'
	 mov [location+2],'r'
	 mov [location+3],'i'
	 mov [location+4],'f'
	 mov [location+5],'y'
	 mov [location+6],'i'
	 mov [location+7],'n'
	 mov [location+8],'g'
	 mov [location+9],' '
	 mov [location+10],'P'
	 mov [location+11],'E'
	 mov [location+12],0
}

macro createStringVerifyChecksum location
{
	 mov [location+0],'V'
	 mov [location+1],'e'
	 mov [location+2],'r'
	 mov [location+3],'i'
	 mov [location+4],'f'
	 mov [location+5],'y'
	 mov [location+6],'i'
	 mov [location+7],'n'
	 mov [location+8],'g'
	 mov [location+9],' '
	 mov [location+10],'C'
	 mov [location+11],'h'
	 mov [location+12],'e'
	 mov [location+13],'c'
	 mov [location+14],'k'
	 mov [location+15],'s'
	 mov [location+16],'u'
	 mov [location+17],'m'
	 mov [location+18],0
}

macro createStringDone location
{
	 mov [location+0],'D'
	 mov [location+1],'o'
	 mov [location+2],'n'
	 mov [location+3],'e'
	 mov [location+4],0
}

macro createStringError location
{
	 mov [location+0],'E'
	 mov [location+1],'r'
	 mov [location+2],'r'
	 mov [location+3],'o'
	 mov [location+4],'r'
	 mov [location+5],0
}

macro createStringStartingHyperion location
{
	 mov [location+00],'H'
	 mov [location+01],'y'
	 mov [location+02],'p'
	 mov [location+03],'e'
	 mov [location+04],'r'
	 mov [location+05],'i'
	 mov [location+06],'o'
	 mov [location+07],'n'
	 mov [location+08],' '
	 mov [location+09],'L'
	 mov [location+10],'o'
	 mov [location+11],'g'
	 mov [location+12],'f'
	 mov [location+13],'i'
	 mov [location+14],'l'
	 mov [location+15],'e'
	 mov [location+16],13
	 mov [location+17],10
	 mov [location+18],0
}

macro createStringStartingHyperionLines location
{
	 mov [location+00],'-'
	 mov [location+01],'-'
	 mov [location+02],'-'
	 mov [location+03],'-'
	 mov [location+04],'-'
	 mov [location+05],'-'
	 mov [location+06],'-'
	 mov [location+07],'-'
	 mov [location+08],'-'
	 mov [location+09],'-'
	 mov [location+10],'-'
	 mov [location+11],'-'
	 mov [location+12],'-'
	 mov [location+13],'-'
	 mov [location+14],'-'
	 mov [location+15],'-'
	 mov [location+16],13
	 mov [location+17],10
	 mov [location+18],0
}

macro createStringLogTxt location
{
	 mov [location+0],'l'
	 mov [location+1],'o'
	 mov [location+2],'g'
	 mov [location+3],'.'
	 mov [location+4],'t'
	 mov [location+5],'x'
	 mov [location+6],'t'
	 mov [location+7],0
}
