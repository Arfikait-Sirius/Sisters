#ifndef _KOTONE_
#define _KOTONE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "./commons/sisdef.h"
#include "./commons/sisset.h"
#include "./commons/sismsg.h"


//--< Prototype Declarations >--//
list _KotonefnCreate( void ) ;
void _KotonefnAdd( list, string ) ;
string _KotonefnGet( list, int ) ;
void _KotonefnRemove( list, int ) ;

bool _KotonelvCalled( void ) ;
void _KotonelvFree( void ) ;


/* <] - Kotone - [> */
typedef struct _kotone_functions{
     list ( *fnCreate )( void ) ;
     void ( *fnAdd )( list, string ) ;
     string ( *fnGet )( list, int ) ;
}KotoneFunctions ;

#define BIRTH_KOTONE {\
     _KotonefnCreate,\
     _KotonefnAdd,\
     _KotonefnGet\
}

static KotoneFunctions Kotone ;

KotoneFunctions callKotone( void ) ;


//--< Mydata Declaration >--//
typedef struct listData{
     struct listData* prev ;
     struct listData* next ;
     string data ;
}_ListData ;

typedef struct myDataKotone{
     bool isKotone ;
     list seq ;
     int myIndex[KOTONE_MAX_LIST_COUNT] ;
     _ListData myList[KOTONE_MAX_LIST_COUNT][KOTONE_MAX_LIST_SIZE] ;
}_MyDataKotone ;

#define INIT_KOTONE_MYDATA {\
     false,\
     0,\
     { 0 },\
     {\
          {\
               NULL,\
               NULL,\
               NULL\
          }\
     }\
}


//--< Free Definitions >--//


#endif
