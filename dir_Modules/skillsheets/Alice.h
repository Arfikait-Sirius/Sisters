#ifndef _ALICE_
#define _ALICE_


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "./commons/sisdef.h"
#include "./commons/sisset.h"
#include "./commons/sismsg.h"


//--< Prototype Declarations >--//
pochette _AlicefnCreate( void ) ;
void _AlicefnPutString( pochette, string, string ) ;
string _AlicefnGetString( pochette, string ) ;
string _AlicefnToString( pochette ) ;


/* <] - Alice - [> */
typedef struct _alice_functions{
     pochette ( *fnCreate )( void ) ;
     void ( *fnPutString )( pochette, string, string ) ;
     string ( *fnGetString )( pochette, string ) ;
     string ( *fnToString )( pochette ) ;
} AliceFunctions ;

#define BIRTH_ALICE {\
     _AlicefnCreate,\
     _AlicefnPutString,\
     _AlicefnGetString,\
     _AlicefnToString\
}

static AliceFunctions Alice ;

AliceFunctions callAlice( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataAlice{
     int seq ;
     int curr[ALICE_MAX_POCHETTES] ;
     pochettes poc[ALICE_MAX_POCHETTE_ENTRY][ALICE_MAX_POCHETTES] ;
     string str[ALICE_MAX_POCHETTES] ;
} _MyDataAlice ;

#define INIT_ALICE_MYDATA {\
     0,\
     { 0 },\
     { { 0 } },\
     { NULL }\
}


//--< Free Definitions >--//


#endif
