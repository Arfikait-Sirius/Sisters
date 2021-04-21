#ifndef _CHLOE_
#define _CHLOE_


//--< Use Headers >--//
#include "stdio.h"
#include "string.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "../../dir_Modules/skillsheets/commons/siscmn.h"
#include "../../dir_Modules/skillsheets/commons/sisdef.h"
#include "../../dir_Modules/skillsheets/commons/sisset.h"
#include "../../dir_Modules/skillsheets/commons/sismsg.h"


//--< Prototype Declarations >--//
string _ChloeacYes( void ) ;
string _ChloeacNo( void ) ;

void _fnPass( void ) ;

bool _isNo( string ) ;

static void sfnToLower( string ) ;


/* <] - Chloe - [> */
typedef struct _chloe_functions{
     string ( *acYes )( void ) ;
     string ( *acNo )( void ) ;

     void ( *fnPass )( void ) ;

     bool ( *isNo )( string ) ;
}ChloeFunctions ;

#define BIRTH_CHLOE {\
     _ChloeacYes,\
     _ChloeacNo,\
     \
     _fnPass,\
     \
     _isNo\
}

static ChloeFunctions Chloe ;

ChloeFunctions callChloe( void ) ;


//--< Mydata Declaration >--//
typedef struct myDataChloe{
     string YES ;
     string NO ;
}_MyDataChloe ;

#define INIT_CHLOE_MYDATA {\
     "yes",\
     "no"\
}


//--< Free Definitions >--//


#endif
