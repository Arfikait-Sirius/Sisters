#ifndef _DOROTHY_
#define _DOROTHY_


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Specifications/sisdef.h"
#include "../../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
file _DorothyfnOpen( string ) ;
void _DorothyfnCloseFile( file ) ;
string _DorothyfnReadLine( file ) ;
void _DorothyfnWriteLine( file, string ) ;
void _DorothyfnRenameFile( file, string ) ;
int _DorothyfnDelete( string ) ;
file _DorothyfnOpenParse( string ) ;
void _DorothyfnCloseParse( file ) ;
int _DorothyfnGetFileLength( file ) ;
int _DorothyfnGetFileLine( file ) ;
void _DorothyfnCopyFile( string, string ) ;

bool _isNotFileEnd( file ) ;
bool _DorothyisError( file ) ;

static string sfnExtractFilePath( string ) ;


/* <] - Dorothy - [> */
typedef struct _dorothy_functions{
     file ( *fnOpen )( string ) ;
     void ( *fnClose )( file ) ;
     string ( *fnReadLine )( file ) ;
     void ( *fnWriteLine )( file, string ) ;
     void ( *fnRenameFile )( file, string ) ;
     int ( *fnDelete )( string ) ;
     file ( *fnOpenParse )( string ) ;
     void ( *fnCloseParse )( file ) ;
     int ( *fnGetLength )( file ) ;
     int ( *fnGetLine )( file ) ;
     void ( *fnCopy )( string, string ) ;

     bool ( *isNotFileEnd )( file ) ;
     bool ( *isError )( file ) ;
}DorothyFunctions ;

#define BIRTH_DOROTHY {\
     _DorothyfnOpen,\
     _DorothyfnCloseFile,\
     _DorothyfnReadLine,\
     _DorothyfnWriteLine,\
     _DorothyfnRenameFile,\
     _DorothyfnDelete,\
     _DorothyfnOpenParse,\
     _DorothyfnCloseParse,\
     _DorothyfnGetFileLength,\
     _DorothyfnGetFileLine,\
     _DorothyfnCopyFile,\
     \
     _isNotFileEnd,\
     _DorothyisError\
}

static DorothyFunctions Dorothy ;

DorothyFunctions callDorothy( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataDorothy{
     file fileSeq ;
     int parseSeq ;
     FILE* fp[DOROTHY_MAX_FILE_COUNT] ;
     char fname[DOROTHY_MAX_FILE_COUNT][80] ;
     char readStr[DOROTHY_MAX_FILE_COUNT][DOROTHY_READ_BUFSIZE] ;
     char stat[DOROTHY_MAX_FILE_COUNT] ;
     bool error[DOROTHY_MAX_FILE_COUNT] ;
     char tmpPath[DOROTHY_MAX_FILE_COUNT][MAX_LENGTH] ;
     char* path[DOROTHY_MAX_FILE_COUNT] ;
     int parseStat[DOROTHY_MAX_FILE_COUNT] ;
     int parseLen[DOROTHY_MAX_FILE_COUNT] ;
     int parseLine[DOROTHY_MAX_FILE_COUNT] ;
}_MyDataDorothy ;

#define INIT_DOROTHY_MYDATA {\
     0,\
     0,\
     { NULL },\
     { { NL } },\
     { { NL } },\
     { NL },\
     { false },\
     { { NL } },\
     { NULL },\
     { NL },\
     { 0 },\
     { 0 }\
}


//--< Free Definitions >--//
#define FILE_ERROR -1
#define NO_CHANGE  -1

#define FILE_STAT_BEGINNING 0
#define FILE_STAT_READING   1
#define FILE_STAT_WRITING   2
#define FILE_STAT_END       3

#define FILE_PARSE_START 0
#define FILE_PARSE_END 1

#define READ 0
#define WRITE 1
#define WRONG 2


#endif
