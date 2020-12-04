#ifndef _ALICE_
#define _ALICE_


//--< Sisters ID >--//
#define Alice_ID 1


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"


//--< Prototype Declarations >--//
int mfnAlice( int, char*[] ) ;

void _fnGreetAlice( void ) ;


/* <] - Alice - [> */
typedef struct _alice_functions{
     void ( *fnGreet )( void ) ;
}AliceFunctions ;

#define BIRTH_ALICE {\
     _fnGreetAlice\
}

static AliceFunctions _Alice = BIRTH_ALICE ;
static AliceFunctions* Alice = &_Alice ;

//--< Mydata Declaration >--//


//--< Free Definitions >--//


#endif
