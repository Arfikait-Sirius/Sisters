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
int mfnLouise( int, char*[] ) ;

string _fnCopyString( string, int ) ;
string _fnReplaceString( string, string, string ) ;
string _fnUpperAll( string ) ;
string _fnLowerAll( string ) ;
string _fnUpperFirst( string ) ;
string _fnGetMiddleString( string, string ) ;
string _fnTrimWhiteSpace( string ) ;
string _fnNumToStr( int ) ;
int _fnCountString( string, string ) ;
int _fnGetLengthString( string ) ;

bool _isMatchFormat( string, string ) ;
bool _isContainString( string, string ) ;
bool _isEqualString( string, string ) ;
bool _isEmptyString( string ) ;


/* <] - Louise - [> */
typedef struct _louise_functions{
     string ( *fnCopy )( string, int ) ;
     string ( *fnReplace )( string, string, string ) ;
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
     _fnCopyString,\
     _fnReplaceString,\
     _fnUpperAll,\
     _fnLowerAll,\
     _fnUpperFirst,\
     _fnGetMiddleString,\
     _fnTrimWhiteSpace,\
     _fnNumToStr,\
     _fnGetLengthString,\
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
     char cpyStr[MAX_CPY_SIZE][MAX_LENGTH] ;
     char repStr[MAX_LENGTH] ;
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
     { NL }\
}


//--< Free Definitions >--//


#endif
