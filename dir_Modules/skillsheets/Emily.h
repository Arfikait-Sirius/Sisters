#ifndef _EMILY_
#define _EMILY_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "./commons/sisdef.h"
#include "./commons/sisset.h"


//--< Prototype Declarations >--//
int mfnMainEmily( int argc, char* argv[] ) ;

string _EmilyfnGetLine( string ) ;
void _EmilyfnDispLine( string ) ;
void _EmilyfnDispLineCustom( string, string, string ) ;
void _EmilyfnDispStr( string ) ;
void _EmilyfnDispStrCustom( string, string, string ) ;
void _EmilyfnNewLine( void ) ;
void _EmilyfnBackLine( int ) ;
void _EmilyfnClearAll( void ) ;
void _EmilyfnClearLine( void ) ;
void _EmilyfnClearBackLine( int ) ;


/* <] - Emily - [> */
typedef struct _emily_functions{
     string ( *fnGetLine )( string ) ;
     void ( *fnDispLine )( string ) ;
     void ( *fnDispLineCustom )( string, string, string ) ;
     void ( *fnDispStr )( string ) ;
     void ( *fnDispStrCustom )( string, string, string ) ;
     void ( *fnNewLine )( void ) ;
     void ( *fnBackLine )( int ) ;
     void ( *fnClearAll )( void ) ;
     void ( *fnClearLine )( void ) ;
     void ( *fnClearBackLine )( int ) ;
}EmilyFunctions ;

#define BIRTH_EMILY {\
     _EmilyfnGetLine,\
     _EmilyfnDispLine,\
     _EmilyfnDispLineCustom,\
     _EmilyfnDispStr,\
     _EmilyfnDispStrCustom,\
     _EmilyfnNewLine,\
     _EmilyfnBackLine,\
     _EmilyfnClearAll,\
     _EmilyfnClearLine,\
     _EmilyfnClearBackLine\
}

static EmilyFunctions Emily ;

EmilyFunctions callEmily( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataEmily{
     char str[MAX_LENGTH] ;
}_MyDataEmily ;

#define INIT_EMILY_MYDATA {\
     { NL }\
}


//--< Free Definitions >--//


#endif
