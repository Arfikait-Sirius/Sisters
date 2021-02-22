#ifndef _SYLVIA_
#define _SYLVIA_


//--< Sisters ID >--//
#define Sylvia_ID 9


//--< Use Headers >--//
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Runtimefiles/sisset.h"
#include "../../dir_Runtimefiles/sismsg.h"


//--< Prototype Declarations >--//
int mfnSylvia( int, char*[] ) ;

int _SylviafnStrToNum( string ) ;
int _SylviafnCalcStrExpression( string ) ;
int _SylviafnAdd( int, int ) ;
int _SylviafnSub( int, int ) ;
int _SylviafnMul( int, int ) ;
int _SylviafnDiv( int, int ) ;

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
     _SylviafnStrToNum,\
     _SylviafnCalcStrExpression,\
     _SylviafnAdd,\
     _SylviafnSub,\
     _SylviafnMul,\
     _SylviafnDiv\
}

static SylviaFunctions Sylvia ;

SylviaFunctions callSylvia( void ) ;


//--< Mydata Declaration >--//


//--< Free Definitions >--//
#define NUM_OF_OPERATOR 16
#define NUM_OF_NUMBERS 256


#endif
