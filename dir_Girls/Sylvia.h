#ifndef _SYLVIA_
#define _SYLVIA_


//--< Sisters ID >--//
#define Sylvia_ID 9


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Runtimefiles/sisset.h"
#include "../dir_Runtimefiles/sismsg.h"


//--< Prototype Declarations >--//
int mfnSylvia( int, char*[] ) ;

int _fnStrToNum( string ) ;
int _fnCalcStrExpression( string ) ;
int _fnAdd( int, int ) ;
int _fnSub( int, int ) ;
int _fnMul( int, int ) ;
int _fnDiv( int, int ) ;

int sfnCalc( int*, char* ) ;

/* <] - Sylvia - [> */
typedef struct _sylvia_functions{
     int ( *fnStrToNum )( string ) ;
     int ( *fnCalcStrExpression )( string ) ;
     int ( *fnAdd )( int, int ) ;
     int ( *fnSub )( int, int ) ;
     int ( *fnMul )( int, int ) ;
     int ( *fnDiv )( int, int ) ;
}SylviaFunctions ;

#define BIRTH_SYLVIA {\
     _fnStrToNum,\
     _fnCalcStrExpression,\
     _fnAdd,\
     _fnSub,\
     _fnMul,\
     _fnDiv\
}

static SylviaFunctions Sylvia ;

SylviaFunctions callSylvia( void ) ;


//--< Mydata Declaration >--//


//--< Free Definitions >--//
#define NUM_OF_OPERATOR OPERATOR_STACK_BUFSIZE
#define NUM_OF_NUMBERS NUMBER_STACK_BUFSIZE


#endif
