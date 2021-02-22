#ifndef _GRACE_
#define _GRACE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "sys/types.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "unistd.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Specifications/sisdef.h"


//--< Prototype Declarations >--//
int mfnGrace( int, char*[] ) ;

void _GracefnService( int ) ;
void _GracefnDeploy( string ) ;
void _GracefnSetValue( string, string ) ;

static int sfnBindSocket( int ) ;
static int sfnAccept( int, string, string, string ) ;
static int sfnSendProperty( int, string ) ;
static int sfnSendHTML( int, string ) ;

static void sfnSplitFileName( string ) ;
static void sfnGenerateHTML( string, string ) ;
static string sfnGetValue( string ) ;


/* <] - Grace - [> */
typedef struct _grace_functions{
     void ( *fnService )( int ) ;
     void ( *fnDeploy )( string ) ;
     void ( *fnSetValue )( string, string ) ;
}GraceFunctions ;

#define BIRTH_GRACE {\
     _GracefnService,\
     _GracefnDeploy,\
     _GracefnSetValue\
}

static GraceFunctions Grace ;

GraceFunctions callGrace( void ) ;


//--< Mydata Declaration >--//
typedef struct _myDataGrace{
     char name[HALF_LENGTH] ;
     char type[HALF_LENGTH] ;

     int index ;
     char key[MEDIUM_LENGTH][HALF_LENGTH] ;
     char value[MEDIUM_LENGTH][HALF_LENGTH] ;
}_MyDataGrace ;

#define INIT_GRACE_MYDATA {\
     { NL },\
     { NL },\
     \
     0,\
     { { NL } },\
     { { NL } }\
}


//--< Free Definitions >--//
#define GRACE_HTML "ghtml"


#endif
