#ifndef _RACHEL_
#define _RACHEL_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"
#include "../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
schema _fnOpenSchema( string ) ;
void _fnChangeSchema( schema ) ;
string _fnGetData( string ) ;
void _fnCloseSchema( schema ) ;

int sfnSplitData( string, string, string ) ;


/* <] - Rachel - [> */
typedef struct _rachel_functions{
     schema ( *fnOpen )( string ) ;
     void ( *fnChange )( schema ) ;
     string ( *fnGetData )( string ) ;
     void ( *fnClose )( schema ) ;
}RachelFunctions ;

#define BIRTH_RACHEL {\
     _fnOpenSchema,\
     _fnChangeSchema,\
     _fnGetData,\
     _fnCloseSchema\
}

static RachelFunctions Rachel ;

RachelFunctions callRachel( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataRachel{
     int schemaSeq ;
     FILE* currSchema ;
     FILE* schemafp[RACHEL_MAX_SCHEMA_COUNT] ;
     char schemaName[RACHEL_MAX_SCHEMA_COUNT][HALF_LENGTH] ;
     char data[HALF_LENGTH] ;
}_MyDataRachel ;

#define INIT_RACHEL_MYDATA {\
     0,\
     NULL,\
     { NULL },\
     { { NL } },\
     { NL }\
}


//--< Free Definitions >--//


#endif
