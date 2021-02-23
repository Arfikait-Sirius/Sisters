#include "forDorothy.h"


static void callSisters( void ){
     Tina = callTina() ;
     Dorothy = callDorothy() ;

     return ;
}

static file fileID ;


void examForDorothy( void ){
     callSisters() ;

     Tina.fnSetGirlName( "Dorothy" ) ;

     examFnOpen() ;
     examFnReadLine() ;
     examFnClose() ;

     return ;
}

static void examFnOpen( void ){
     Tina.fnSetSkillName( "fnOpen" ) ;

     bool result ;

     fileID = Dorothy.fnOpen( "./dir_Examinations/ExamsResources/ExamsTestFile.txt" ) ;
     result = fileID == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnReadLine( void ){
     Tina.fnSetSkillName( "fnReadLine" ) ;

     string s ;
     bool result ;

     s = Dorothy.fnReadLine( fileID ) ;
     result = strcmp( s, "This is ExamTestFile." ) == 0 ;

     Tina.fnJudge( result ) ;

     return ;
}

static void examFnClose( void ){
     Tina.fnSetSkillName( "fnClose" ) ;

     bool result ;

     Dorothy.fnClose( fileID ) ;

     Dorothy.fnReadLine( fileID ) ;
     result = Dorothy.isError( fileID ) ;

     Tina.fnJudge( result ) ;

     return ;
}
