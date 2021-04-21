#ifndef _ALICE_
#define _ALICE_


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
storage _AlicefnOpenStorage( string, string ) ;
void _AlicefnCloseStorage( storage ) ;
string _AlicefnGetData( storage, string ) ;


/* <] - Alice - [> */
typedef struct _alice_functions{
     storage ( *fnOpen )( string, string ) ;
     void ( *fnClose )( storage ) ;
     string ( *fnGet )( storage, string ) ;
}AliceFunctions ;

#define BIRTH_ALICE {\
     _AlicefnOpenStorage,\
     _AlicefnCloseStorage,\
     _AlicefnGetData\
}

static AliceFunctions Alice ;

AliceFunctions callAlice( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataAlice{
     storage seq ;
     FILE* fp[ALICE_MAX_STORAGES] ;
     char type[ALICE_MAX_STORAGES][5] ;
}_MyDataAlice ;

#define INIT_ALICE_MYDATA {\
     0,\
     { NULL },\
     { { NL } }\
}


//--< Free Definitions >--//


#endif
