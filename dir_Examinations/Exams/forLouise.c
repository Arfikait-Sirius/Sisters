#include "forLouise.h"


static void callSisters( void ){
     Tina = callTina() ;
     Louise = callLouise() ;

     return ;
}


void examForLouise( void ){
     callSisters() ;
     
     Tina.fnSetGirlName( "Louise" ) ;

     examFnCopy() ;
     examFnReplace() ;
     examFnUpperAll() ;
     examFnLowerAll() ;
     examFnUpperFirst() ;

     return ;
}

static void examFnCopy( void ){
     Tina.fnSetSkillName( "fnCopy" ) ;

     string s ;
     int result ;

     s = Louise.fnCopy( "TestString 000", TMP ) ;
     result = strcmp( s, "TestString 000" ) ;


     Tina.fnJudge( result == 0 ) ;

     return ;
}

static void examFnReplace( void ){
     Tina.fnSetSkillName( "fnReplace" ) ;

     string s ;
     int result ;

     s = Louise.fnReplace( "This is normal string.", "normal", "changed" ) ;
     result = strcmp( s, "This is changed string." ) ;

     Tina.fnJudge( result == 0 ) ;

     return ;
}

static void examFnUpperAll( void ){
     Tina.fnSetSkillName( "fnUpperAll" ) ;

     string s ;
     int result ;

     s = Louise.fnUpperAll( "sTrInG_123." ) ;
     result = strcmp( s, "STRING_123." ) ;

     Tina.fnJudge( result == 0 ) ;

     return ;
}

static void examFnLowerAll( void ){
     Tina.fnSetSkillName( "fnLowerAll" ) ;

     string s ;
     int result ;

     s = Louise.fnLowerAll( "sTrInG_123." ) ;
     result = strcmp( s, "string_123." ) ;

     Tina.fnJudge( result == 0 ) ;

     return ;
}

static void examFnUpperFirst( void ){
     Tina.fnSetSkillName( "fnUpperFirst" ) ;

     string s ;
     int result ;

     s = Louise.fnUpperFirst( "sTrInG_123." ) ;
     result = strcmp( s, "String_123." ) ;

     Tina.fnJudge( result == 0 ) ;

     return ;
}
