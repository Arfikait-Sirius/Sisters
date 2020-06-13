#ifndef _KOTONE_
#define _KOTONE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"


//--< Prototype Declarations >--//
int _fnCreateList( mode ) ;


/* <] - Kotone - [> */
typedef struct _kotone_functions{
     int ( *fnCreateList )( mode ) ;
}KotoneFunctions ;

#define BIRTH_KOTONE {\
     _fnCreateList\
}

static KotoneFunctions Kotone ;

KotoneFunctions callKotone( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataKotone{
     int seq ;
     pointer plist[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     char clist[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     string slist[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     int ilist[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     int index[MAX_LIST_COUNT * 4] ;
}_MyDataKotone ;

#define INIT_KOTONE_MYDATA {\
	1,\
     { { NULL } },\
     { { NL } },\
     { { NULL } },\
     { { NL } },\
     { 0 }\
}


//--< Free Definitions >--//
#define TMP_LIST 0
#define LIST_TOP 0


#endif
