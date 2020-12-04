#ifndef _LOUISE_
#define _LOUISE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


//--< Standard Definition >--//
#include "../dir_Specifications/siscmn.h"
#include "../dir_Specifications/sisdef.h"


//--< Prototype Declarations >--//
string _LouisefnCopyString( string, int ) ;
string _LouisefnReplaceString( string, string, string ) ;
string _LouisefnSplitString( string, char, int ) ;
string _LouisefnUpperAll( string ) ;
string _LouisefnLowerAll( string ) ;
string _LouisefnUpperFirst( string ) ;
string _LouisefnGetMiddleString( string, string ) ;
string _LouisefnTrimWhiteSpace( string ) ;
string _LouisefnNumToStr( int ) ;
int _LouisefnCountString( string, string ) ;
int _LouisefnGetLengthString( string ) ;

bool _isMatchFormat( string, string ) ;
bool _isContainString( string, string ) ;
bool _isEqualString( string, string ) ;
bool _isEmptyString( string ) ;


/* <] - Louise - [> */
typedef struct _louise_functions{
     int ( *fnCount )( string, string ) ;
     string ( *fnCopy )( string, int ) ;
     string ( *fnReplace )( string, string, string ) ;
     string ( *fnSplit )( string, char, int ) ;
     string ( *fnUpperAll )( string ) ;
     string ( *fnLowerAll )( string ) ;
     string ( *fnUpperFirst )( string ) ;
     string ( *fnGetMiddle )( string, string ) ;
     string ( *fnTrim )( string ) ;
     string ( *fnNumToStr )( int ) ;
     int ( *fnGetLength )( string ) ;

     bool ( *isMatch )( string, string ) ;
     bool ( *isContain )( string, string ) ;
     bool ( *isEqual )( string, string ) ;
     bool ( *isEmpty )( string ) ;
}LouiseFunctions ;

#define BIRTH_LOUISE {\
     _LouisefnCountString,\
     _LouisefnCopyString,\
     _LouisefnReplaceString,\
     _LouisefnSplitString,\
     _LouisefnUpperAll,\
     _LouisefnLowerAll,\
     _LouisefnUpperFirst,\
     _LouisefnGetMiddleString,\
     _LouisefnTrimWhiteSpace,\
     _LouisefnNumToStr,\
     _LouisefnGetLengthString,\
     \
     _isMatchFormat,\
     _isContainString,\
     _isEqualString,\
     _isEmptyString\
}

static LouiseFunctions Louise ;

LouiseFunctions callLouise( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataLouise{
     int cpyCounter ;
     char cpyStr[LOUISE_MAX_CPY_SIZE][MAX_LENGTH] ;
     char repStr[MAX_LENGTH] ;
     char splStr[HALF_LENGTH] ;
     char midStr[HALF_LENGTH] ;
     char resStr[MAX_LENGTH] ;
     char trmStr[MAX_LENGTH] ;
     char numStr[HALF_LENGTH] ;
}_MyDataLouise ;

#define INIT_LOUISE_MYDATA {\
     1,\
     { { NL } },\
     { NL },\
     { NL },\
     { NL },\
     { NL },\
     { NL },\
     { NL }\
}


//--< Free Definitions >--//


#endif
