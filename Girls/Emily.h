#ifndef _EMILY_
#define _EMILY_


//--< Sisters ID >--//
#define Emily_ID 3


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../dir_Specifications/sisdef.h"


//--< Prototype Declarations >--//
int mfnMainEmily( int argc, char* argv[] ) ;

string _fnGetLine( string ) ;
void _fnDispLine( string ) ;
void _fnDispLineCustom( string, string, string ) ;
void _fnDispStr( string ) ;
void _fnDispStrCustom( string, string, string ) ;


/* <] - Emily - [> */
typedef struct _emily_functions{
	string ( *fnGetLine )( string ) ;
	void ( *fnDispLine )( string ) ;
	void ( *fnDispLineCustom )( string, string, string ) ;
	void ( *fnDispStr )( string ) ;
	void ( *fnDispStrCustom )( string, string, string ) ;
}EmilyFunctions ;

#define BIRTH_EMILY {\
	_fnGetLine,\
	_fnDispLine,\
	_fnDispLineCustom,\
	_fnDispStr,\
	_fnDispStrCustom\
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
