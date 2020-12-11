#include "forVeera.h"


static void callSisters( void ){
     Tina = callTina() ;
     Veera = callVeera() ;

     return ;
}


void examForVeera( void ){
     callSisters() ;
     
     Tina.fnSetGirlName( "Veera" ) ;

     examFnGetDate() ;

     return ;
}

static void examFnGetDate( void ){
     Tina.fnSetSkillName( "fnGetDate" ) ;

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

     Tina.fnJudge( result == 0 ) ;

     return ;
}
