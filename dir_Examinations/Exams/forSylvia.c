#include "forSylvia.h"


static void callSisters( void ){
     Tina = callTina() ;
     Sylvia = callSylvia() ;

     return ;
}


void examForSylvia( void ){
     callSisters() ;
     
     Tina.fnSetGirlName( "Sylvia" ) ;

     examFnCalcStrExpression() ;

     return ;
}

static void examFnCalcStrExpression( void ){
     Tina.fnSetSkillName( "fnCalcStrExpression" ) ;

     int result ;

     result = Sylvia.fnCalcStrExpression( "12/2 +5 - 2  * 3" ) ;

     Tina.fnJudge( result == 5 ) ;

     return ;
}
