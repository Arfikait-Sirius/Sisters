#include "forDorothy.h"


static void callSisters( void ){
     Tina = callTina() ;
     Dorothy = callDorothy() ;

     return ;
}


void examForDorothy( void ){
     callSisters() ;
     
     Tina.fnSetGirlName( "Dorothy" ) ;

     return ;
}
