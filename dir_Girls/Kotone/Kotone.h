#ifndef _KOTONE_
#define _KOTONE_


//--< Sisters ID >--//
#define Kotone_ID 6


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"

#define LIST_TOP 0


//--< Prototype Declarations >--//
int mfnKotone( int, char*[] ) ;

int _fnCreateList( char, char ) ;
void _fnAppendPList( int, void*, char ) ;
char _fnGetPListAsChr( int, int ) ;
char* _fnGetPListAsStr( int, int ) ;
int _fnGetPListAsInt( int, int ) ;

bool _isNotExistList( int, char ) ;
bool _isNextPListTypeChr( int ) ;
bool _isNextPListTypeStr( int ) ;
bool _isNextPListTypeInt( int ) ;


/* <] - Kotone - [> */
typedef struct _kotone_functions{
     int ( *fnCreateList )( char, char ) ;
     void ( *fnAppendPList )( int, void*, char ) ;
     char ( *fnGetPListAsChr )( int, int ) ;
     char* ( *fnGetPListAsStr )( int, int ) ;
     int ( *fnGetPListAsInt )( int, int ) ;

     bool ( *isNextPListTypeChr )( int ) ;
     bool ( *isNextPListTypeStr )( int ) ;
     bool ( *isNextPListTypeInt )( int ) ;
}KotoneFunctions ;

#define BIRTH_KOTONE {\
     _fnCreateList,\
     _fnAppendPList,\
     _fnGetPListAsChr,\
     _fnGetPListAsStr,\
     _fnGetPListAsInt,\
     \
     _isNextPListTypeChr,\
     _isNextPListTypeStr,\
     _isNextPListTypeInt\
}

static KotoneFunctions _Kotone = BIRTH_KOTONE ;
static KotoneFunctions* Kotone = &_Kotone ;

//--< Mydata Declaration >--//
typedef struct myDataKotone{
     int listSeq ;
     char existList[MAX_LIST_COUNT] ;
     char valueChr ;
     char valueStr[MAX_LENGTH] ;
     int valueInt ;
     char chrList[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     char strList[MAX_LIST_COUNT][MAX_LIST_SIZE][MAX_LENGTH] ;
     int intList[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     void* PList[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     char PListType[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     int PListIndex[MAX_LIST_COUNT] ;
     int chrListIndex[MAX_LIST_COUNT] ;
     int strListIndex[MAX_LIST_COUNT] ;
     int intListIndex[MAX_LIST_COUNT] ;
     int PListIndexAccess[MAX_LIST_COUNT] ;
}_MyDataKotone ;

#define INIT_KOTONE_MYDATA {\
     0,\
     { NL },\
	NL,\
	{ NL },\
	0,\
	{ { NL } },\
	{ { { NL } } },\
	{ { NL } },\
	{ { NULL } },\
	{ { NL } },\
	{ LIST_TOP },\
	{ LIST_TOP },\
	{ LIST_TOP },\
	{ LIST_TOP },\
	{ LIST_TOP }\
}


//--< Free Definitions >--//

#endif
