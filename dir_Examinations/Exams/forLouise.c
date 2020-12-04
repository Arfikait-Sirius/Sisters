#include "forLouise.h"


void examForLouise( void ){
     Louise = callLouise() ;

     dispExamGirl( "Louise" ) ;

     examFnCopy() ;
     examFnReplace() ;
     examFnUpperAll() ;
     examFnLowerAll() ;
     examFnUpperFirst() ;

     return ;
}

static void examFnCopy( void ){
     dispExamTarget( "fnCopy" ) ;

     string s ;
     int result ;

     s = Louise.fnCopy( "TestString 000", TMP ) ;
     result = strcmp( s, "TestString 000" ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}

static void examFnReplace( void ){
     dispExamTarget( "fnReplace" ) ;

     string s ;
     int result ;

     s = Louise.fnReplace( "This is normal string.", "normal", "changed" ) ;
     result = strcmp( s, "This is changed string." ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}

static void examFnUpperAll( void ){
     dispExamTarget( "fnUpperAll" ) ;

     string s ;
     int result ;

     s = Louise.fnUpperAll( "sTrInG_123." ) ;
     result = strcmp( s, "STRING_123." ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}

static void examFnLowerAll( void ){
     dispExamTarget( "fnLowerAll" ) ;

     string s ;
     int result ;

     s = Louise.fnLowerAll( "sTrInG_123." ) ;
     result = strcmp( s, "string_123." ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}

static void examFnUpperFirst( void ){
     dispExamTarget( "fnUpperFirst" ) ;

     string s ;
     int result ;

     s = Louise.fnUpperFirst( "sTrInG_123." ) ;
     result = strcmp( s, "String_123." ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}
