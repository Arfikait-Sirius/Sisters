#include "forSylvia.h"


void examForSylvia( void ){
     Sylvia = callSylvia() ;

     dispExamGirl( "Sylvia" ) ;

     examFnCalcStrExpression() ;

     return ;
}

static void examFnCalcStrExpression( void ){
     dispExamTarget( "fnCalcStrExpression" ) ;

     int result ;

     result = Sylvia.fnCalcStrExpression( "12/2 +5 - 2  * 3" ) ;
     if( result == 5 ){
          dispResultOK() ;
     }else{
          dispResultNG() ;
     }

     return ;
}
