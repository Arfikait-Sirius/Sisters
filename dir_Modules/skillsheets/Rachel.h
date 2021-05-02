#ifndef _RACHEL_
#define _RACHEL_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "./commons/sisdef.h"
#include "./commons/sisset.h"


//--< Prototype Declarations >--//
schema _RachelfnOpen( string ) ;
void _RachelfnChange( schema ) ;
int _RachelfnCreate( string ) ;
void _RachelfnRegister( int, string ) ;
void _RachelfnCommit( void ) ;
string _RachelfnGetValue( string ) ;
void _RachelfnClose( schema ) ;

int sfnSplitData( string, string, string ) ;


/* <] - Rachel - [> */
typedef struct _rachel_functions{
     schema ( *fnOpen )( string ) ;
     void ( *fnChange )( schema ) ;
     int ( *fnCreate )( string ) ;
     void ( *fnRegister )( int, string ) ;
     void ( *fnCommit )( void ) ;
     string ( *fnGetValue )( string ) ;
     void ( *fnClose )( schema ) ;
}RachelFunctions ;

#define BIRTH_RACHEL {\
     _RachelfnOpen,\
     _RachelfnChange,\
     _RachelfnCreate,\
     _RachelfnRegister,\
     _RachelfnCommit,\
     _RachelfnGetValue,\
     _RachelfnClose\
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
