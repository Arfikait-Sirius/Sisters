#ifndef _RACHEL_
#define _RACHEL_


//--< Use Headers >--//
#include "stdio.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"
#include "../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
schema _fnOpenSchema( string ) ;
void _fnChangeSchema( schema ) ;
void _fnCloseSchema( schema ) ;


/* <] - Rachel - [> */
typedef struct _rachel_functions{
     schema ( *fnOpen )( string ) ;
     void ( *fnChange )( schema ) ;
     void ( *fnClose )( schema ) ;
}RachelFunctions ;

#define BIRTH_RACHEL {\
     _fnOpenSchema,\
     _fnChangeSchema,\
     _fnCloseSchema\
}


//--< Mydata Declaration >--//
typedef struct myDataRachel{
     int schemaSeq ;
     FILE* currSchema ;
     FILE* schemafp[RACHEL_MAX_SCHEMA_COUNT] ;
     string schemaName[RACHEL_MAX_SCHEMA_COUNT] ;
}_MyDataRachel ;

#define INIT_RACHEL_MYDATA {\
     0,\
     NULL,\
     { NULL },\
     { NULL }\
}


//--< Free Definitions >--//


#endif
