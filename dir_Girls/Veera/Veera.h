#ifndef _VEERA_
#define _VEERA_


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
string _fnGetDate( void ) ;


/* <] - Veera - [> */
typedef struct _veera_functions{
     void ( *fnInit )( void ) ;
     int ( *fnRandom )( int ) ;
     string ( *fnGetDate )( void ) ;
}VeeraFunctions ;

#define BIRTH_VEERA {\
     _fnInitRandom,\
     _fnRandom,\
     _fnGetDate\
}

static VeeraFunctions Veera ;

VeeraFunctions callVeera( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataVeera{
     char date[BUF_SIZE_DATE] ;
}_MyDataVeera ;

#define INIT_VEERA_MYDATA {\
     { NL },\
}


//--< Free Definitions >--//


#endif
