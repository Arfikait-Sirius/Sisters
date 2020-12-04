#ifndef _CHLOE_
#define _CHLOE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Specifications/sisdef.h"
#include "../../dir_Runtimefiles/sisset.h"


//--< Prototype Declarations >--//
int mfnChloe( int, char*[] ) ;

bool _acNot( bool ) ;

void _fnPass( void ) ;

bool _isNo( string ) ;

static void sfnToLower( string ) ;


/* <] - Chloe - [> */
typedef struct _chloe_functions{
     bool ( *acNot )( bool ) ;

     void ( *fnPass )( void ) ;

     bool ( *isNo )( string ) ;
}ChloeFunctions ;

#define BIRTH_CHLOE {\
     _acNot,\
     \
     _fnPass,\
     \
     _isNo\
}

static ChloeFunctions Chloe ;

ChloeFunctions callChloe( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataChloe{
}_MyDataChloe ;


//--< Free Definitions >--//


#endif
