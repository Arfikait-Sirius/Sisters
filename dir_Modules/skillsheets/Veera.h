#ifndef _VEERA_
#define _VEERA_


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stddef.h"
#include "time.h"


//--< Standard Definition >--//
#include "./commons/sisdef.h"
#include "./commons/sisset.h"
#include "./commons/sismsg.h"


//--< Prototype Declarations >--//
int mfnVeera( int, char*[] ) ;

void _VeerafnInitRandom( void ) ;
int _VeerafnRandom( int ) ;
string _VeerafnGetDate( string ) ;


/* <] - Veera - [> */
typedef struct _veera_functions{
     void ( *fnInit )( void ) ;
     int ( *fnRandom )( int ) ;
     string ( *fnGetDate )( string ) ;
}VeeraFunctions ;

#define BIRTH_VEERA {\
     _VeerafnInitRandom,\
     _VeerafnRandom,\
     _VeerafnGetDate\
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
