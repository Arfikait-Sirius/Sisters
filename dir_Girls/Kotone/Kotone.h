#ifndef _KOTONE_
#define _KOTONE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"
#include "../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
list _KotonefnCreateList( mode ) ;
void _KotonefnAddList( list, string ) ;
stack _KotonefnCreateStack( mode ) ;
void _KotonefnPushStack( stack, string ) ;


/* <] - Kotone - [> */
typedef struct _kotone_functions{
     list ( *fnCreateList )( mode ) ;
     void ( *fnAddList )( list, string ) ;
     stack ( *fnCreateStack )( mode ) ;
     void ( *fnPushStack )( stack, string ) ;
}KotoneFunctions ;

#define BIRTH_KOTONE {\
     _KotonefnCreateList,\
     _KotonefnAddList,\
     _KotonefnCreateStack,\
     _KotonefnPushStack\
}

static KotoneFunctions Kotone ;

KotoneFunctions callKotone( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataKotone{
     list listSeq ;
     stack stackSeq ;
     string myList[MAX_LIST_COUNT][MAX_LIST_SIZE] ;
     string myStack[MAX_STACK_COUNT][MAX_STACK_SIZE] ;
     int listIndex[MAX_LIST_COUNT] ;
     int stackIndex[MAX_STACK_COUNT] ;
}_MyDataKotone ;

#define INIT_KOTONE_MYDATA {\
     1,\
     1,\
     { { NULL } },\
     { { NULL } },\
     { 0 },\
     { 0 }\
}


//--< Free Definitions >--//


#endif
