#ifndef _LOUISE_
#define _LOUISE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "./commons/siscmn.h"
#include "./commons/sisdef.h"
#include "./commons/sisset.h"


//--< Prototype Declarations >--//
int _LouisefnCount( string, string ) ;
string _LouisefnCopy( string ) ;
string _LouisefnReplace( string, string, string ) ;
string _LouisefnSplit( string, char, int ) ;
string _LouisefnUpperAll( string ) ;
string _LouisefnLowerAll( string ) ;
string _LouisefnUpperFirst( string ) ;
string _LouisefnGetMiddle( string, string ) ;
string _LouisefnTrim( string ) ;
string _LouisefnFromInt( int ) ;
int _LouisefnFind( string, string ) ;
int _LouisefnGetLength( string ) ;

bool _LouiseisFormat( string, string ) ;
bool _LouiseisContain( string, string ) ;
bool _LouiseisEqual( string, string ) ;
bool _LouiseisEmpty( string ) ;

void _LouiselvFree( void ) ;


/* <] - Louise - [> */
typedef struct _louise_functions{
     int ( *fnCount )( string, string ) ;
     string ( *fnCopy )( string ) ;
     string ( *fnReplace )( string, string, string ) ;
     string ( *fnSplit )( string, char, int ) ;
     string ( *fnUpperAll )( string ) ;
     string ( *fnLowerAll )( string ) ;
     string ( *fnUpperFirst )( string ) ;
     string ( *fnGetMiddle )( string, string ) ;
     string ( *fnTrim )( string ) ;
     string ( *fnFromInt )( int ) ;
     int ( *fnFind )( string, string ) ;
     int ( *fnGetLength )( string ) ;

     bool ( *isFormat )( string, string ) ;
     bool ( *isContain )( string, string ) ;
     bool ( *isEqual )( string, string ) ;
     bool ( *isEmpty )( string ) ;
}LouiseFunctions ;

#define BIRTH_LOUISE {\
     _LouisefnCount,\
     _LouisefnCopy,\
     _LouisefnReplace,\
     _LouisefnSplit,\
     _LouisefnUpperAll,\
     _LouisefnLowerAll,\
     _LouisefnUpperFirst,\
     _LouisefnGetMiddle,\
     _LouisefnTrim,\
     _LouisefnFromInt,\
     _LouisefnFind,\
     _LouisefnGetLength,\
     \
     _LouiseisFormat,\
     _LouiseisContain,\
     _LouiseisEqual,\
     _LouiseisEmpty\
}

static LouiseFunctions Louise ;

LouiseFunctions callLouise( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataLouise{
     int seq ;
     string str[LOUISE_MAX_STRINGS] ;
}_MyDataLouise ;

#define INIT_LOUISE_MYDATA {\
     0,\
     { NULL }\
}


//--< Free Definitions >--//


#endif
