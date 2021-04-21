#ifndef _DOROTHY_
#define _DOROTHY_


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "../../dir_Modules/skillsheets/commons/siscmn.h"
#include "../../dir_Modules/skillsheets/commons/sisdef.h"
#include "../../dir_Modules/skillsheets/commons/sisset.h"
#include "../../dir_Modules/skillsheets/commons/sismsg.h"


//--< Prototype Declarations >--//
file _DorothyfnOpen( string ) ;
void _DorothyfnClose( file ) ;
string _DorothyfnReadLine( file ) ;
void _DorothyfnWriteLine( file, string ) ;
void _DorothyfnRename( file, string ) ;
int _DorothyfnDelete( string ) ;
file _DorothyfnOpenParse( string ) ;
void _DorothyfnCloseParse( file ) ;
int _DorothyfnGetLength( file ) ;
int _DorothyfnGetNumberOfLines( file ) ;
void _DorothyfnCopy( string, string ) ;

bool _DorothyisNotEnd( file ) ;
bool _DorothyisError( file ) ;

static string sfnExtractFilePath( string ) ;


/* <] - Dorothy - [> */
typedef struct _dorothy_functions{
     file ( *fnOpen )( string ) ;
     void ( *fnClose )( file ) ;
     string ( *fnReadLine )( file ) ;
     void ( *fnWriteLine )( file, string ) ;
     void ( *fnRename )( file, string ) ;
     int ( *fnDelete )( string ) ;
     file ( *fnOpenParse )( string ) ;
     void ( *fnCloseParse )( file ) ;
     int ( *fnGetLength )( file ) ;
     int ( *fnGetNumberOfLines )( file ) ;
     void ( *fnCopy )( string, string ) ;

     bool ( *isNotEnd )( file ) ;
     bool ( *isError )( file ) ;
}DorothyFunctions ;

#define BIRTH_DOROTHY {\
     _DorothyfnOpen,\
     _DorothyfnClose,\
     _DorothyfnReadLine,\
     _DorothyfnWriteLine,\
     _DorothyfnRename,\
     _DorothyfnDelete,\
     _DorothyfnOpenParse,\
     _DorothyfnCloseParse,\
     _DorothyfnGetLength,\
     _DorothyfnGetNumberOfLines,\
     _DorothyfnCopy,\
     \
     _DorothyisNotEnd,\
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
