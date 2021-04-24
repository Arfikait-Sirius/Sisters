#ifndef _VEERA_
#define _VEERA_


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stddef.h"
#include "time.h"


//--< Standard Definition >--//
#include "../../dir_Modules/skillsheets/commons/sisdef.h"
#include "../../dir_Modules/skillsheets/commons/sisset.h"
#include "../../dir_Modules/skillsheets/commons/sismsg.h"


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
#define VEERA_SYMBOL_YEAR 'Y'
#define VEERA_SYMBOL_MONTH 'M'
#define VEERA_SYMBOL_DAY 'D'

#define VEERA_FORMAT_YEAR "YYYY"
#define VEERA_FORMAT_MONTH "MM"
#define VEERA_FORMAT_DAY "DD"


#endif
