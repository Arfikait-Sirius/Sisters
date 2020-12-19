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

     s = Veera.fnGetDate() ;

     Tina.fnPrint( s ) ;

     return ;
}
