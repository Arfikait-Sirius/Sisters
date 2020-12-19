#include "Tina.h"

// Name
static string MyName = "Tina" ;

// Tina's Memo
static _MyDataTina MyData = INIT_TINA_MYDATA ;

// Birth
TinaFunctions callTina( void ){
     TinaFunctions _TinaSkills = BIRTH_TINA ;

     return _TinaSkills ;
}

//------------------------
// :[ NAME ]:
//     fnSetGirlName
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _TinafnSetGirlName( string girlName ){

     printf( "%s%s\n", LABEL_GIRLS_NAME, girlName ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnSetSkillName
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _TinafnSetSkillName( string target ){

     printf( "%s%s()\n", LABEL_TARGET, target ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnJudge
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _TinafnJudge( bool judgement ){

     if( judgement ){
          printf( "%sOK\n", LABEL_JUDGE ) ;
     }else{
          printf( "%sNG\n", LABEL_JUDGE ) ;
     }

     return ;
}

//------------------------
// :[ NAME ]:
//     fnPrint
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _TinafnPrint( string result ){

     printf( "%s%s\n", LABEL_PRINT, result ) ;

     return ;
}
