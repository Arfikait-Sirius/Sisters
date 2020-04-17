#ifndef _DOROTHY_
#define _DOROTHY_


//--< Sisters ID >--//
#define Dorothy_ID 4


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"
#include "../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
int _fnOpenRead( string ) ;
int _fnOpenWrite( string ) ;
void _fnCloseFile( int ) ;
string _fnReadLine( int ) ;
void _fnWriteLine( int, string ) ;
void _fnRenameFile( int, string ) ;
int _fnDelete( string ) ;
int _fnOpenParse( string ) ;
void _fnCloseParse( int ) ;
int _fnGetFileLength( int ) ;
int _fnGetFileLine( int ) ;
void _fnCopyFile( string, string ) ;

char _isNotFileEnd( int ) ;
char _isExistError( int ) ;

static string sfnExtractFilePath( string ) ;


/* <] - Dorothy - [> */
typedef struct _dorothy_functions{
	int ( *fnOpenRead )( string ) ;
	int ( *fnOpenWrite )( string ) ;
	void ( *fnClose )( int ) ;
	string ( *fnReadLine )( int ) ;
	void ( *fnWriteLine )( int, string ) ;
	void ( *fnRenameFile )( int, string ) ;
	int ( *fnDelete )( string ) ;
	int ( *fnOpenParse )( string ) ;
	void ( *fnCloseParse )( int ) ;
	int ( *fnGetLength )( int ) ;
	int ( *fnGetLine )( int ) ;
	void ( *fnCopy )( string, string ) ;

	char ( *isNotFileEnd )( int ) ;
	char ( *isExistError )( int ) ;
}DorothyFunctions ;

#define BIRTH_DOROTHY {\
	_fnOpenRead,\
	_fnOpenWrite,\
	_fnCloseFile,\
	_fnReadLine,\
	_fnWriteLine,\
	_fnRenameFile,\
	_fnDelete,\
	_fnOpenParse,\
	_fnCloseParse,\
	_fnGetFileLength,\
	_fnGetFileLine,\
	_fnCopyFile,\
	\
	_isNotFileEnd,\
	_isExistError\
}

static DorothyFunctions Dorothy ;

DorothyFunctions callDorothy( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataDorothy{
	int fileSeq ;
	int parseSeq ;
	FILE* fp[MAX_FILE_COUNT] ;
	char fname[MAX_FILE_COUNT][80] ;
	char readStr[MAX_FILE_COUNT][READ_BUFSIZE] ;
	char stat[MAX_FILE_COUNT] ;
	char error[MAX_FILE_COUNT] ;
	char tmpPath[MAX_FILE_COUNT][MAX_LENGTH] ;
	char* path[MAX_FILE_COUNT] ;
	int parseStat[MAX_FILE_COUNT] ;
	int parseLen[MAX_FILE_COUNT] ;
	int parseLine[MAX_FILE_COUNT] ;
}_MyDataDorothy ;

#define INIT_DOROTHY_MYDATA {\
	0,\
	0,\
	{ NULL },\
	{ { NL } },\
	{ { NL } },\
	{ NL },\
	{ FALSE },\
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
