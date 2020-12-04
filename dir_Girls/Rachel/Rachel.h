#ifndef _RACHEL_
#define _RACHEL_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Specifications/sisdef.h"
#include "../../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
schema _RachelfnOpenSchema( string ) ;
void _RachelfnChangeSchema( schema ) ;
int _RachelfnCreateBox( string ) ;
void _RachelfnRegistData( int, string ) ;
void _RachelfnCommit( void ) ;
string _RachelfnGetData( string ) ;
void _RachelfnCloseSchema( schema ) ;

int sfnSplitData( string, string, string ) ;


/* <] - Rachel - [> */
typedef struct _rachel_functions{
     schema ( *fnOpen )( string ) ;
     void ( *fnChange )( schema ) ;
     int ( *fnCreate )( string ) ;
     void ( *fnRegist )( int, string ) ;
     void ( *fnCommit )( void ) ;
     string ( *fnGet )( string ) ;
     void ( *fnClose )( schema ) ;
}RachelFunctions ;

#define BIRTH_RACHEL {\
     _RachelfnOpenSchema,\
     _RachelfnChangeSchema,\
     _RachelfnCreateBox,\
     _RachelfnRegistData,\
     _RachelfnCommit,\
     _RachelfnGetData,\
     _RachelfnCloseSchema\
}

static RachelFunctions Rachel ;

RachelFunctions callRachel( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataRachel{
     int schemaSeq ;
     int currSeq ;
     int newSeq ;
     FILE* currSchema ;
     FILE* schemafp[RACHEL_MAX_SCHEMA_COUNT] ;
     char schemaName[RACHEL_MAX_SCHEMA_COUNT][HALF_LENGTH] ;
     char data[MAX_LENGTH] ;
     char newBox[RACHEL_MAX_NEW_SCHEMA_COUNT][HALF_LENGTH] ;
     char newData[RACHEL_MAX_NEW_SCHEMA_COUNT][MAX_LENGTH] ;
}_MyDataRachel ;

#define INIT_RACHEL_MYDATA {\
     0,\
     0,\
     0,\
     NULL,\
     { NULL },\
     { { NL } },\
     { NL },\
     { { NL } },\
     { { NL } }\
}


//--< Free Definitions >--//


#endif
