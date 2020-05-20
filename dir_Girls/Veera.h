#ifndef _VEERA_
#define _VEERA_


//--< Sisters ID >--//
#define Veera_ID 8


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"
#include "time.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"


//--< Prototype Declarations >--//
int mfnVeera( int, char*[] ) ;

void _fnInitRandom( void ) ;
int _fnRandom( int ) ;


/* <] - Veera - [> */
typedef struct _veera_functions{
	void ( *fnInit )( void ) ;
	int ( *fnRandom )( int ) ;
}VeeraFunctions ;

#define BIRTH_VEERA {\
	_fnInitRandom,\
	_fnRandom\
}

static VeeraFunctions Veera ;

VeeraFunctions callVeera( void ) ;


//--< Mydata Declaration >--//


//--< Free Definitions >--//


#endif
