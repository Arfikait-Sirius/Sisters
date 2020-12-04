#include "forVeera.h"


void examForVeera( void ){
     Veera = callVeera() ;

     dispExamGirl( "Veera" ) ;

     examFnGetDate() ;

     return ;
}

static void examFnGetDate( void ){
     dispExamTarget( "fnGetDate" ) ;

     string s ;
     char tmp[TEST_BUF_SIZE_DATE] ;
     time_t t ;
     struct tm* utc ;
     int result ;

     t = time( NULL ) ;
     utc = gmtime( &t ) ;
     sprintf( tmp, "%4d/%2d/%2d", utc->tm_year + 1900, utc->tm_mon + 1, utc->tm_mday ) ;
     s = Veera.fnGetDate() ;
     result = strcmp( s, tmp ) ;
     if( result == 0 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}
