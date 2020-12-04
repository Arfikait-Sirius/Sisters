#include "Emily.h"

// Name
static string MyName = "Emily" ;

// Emily's Memo
static _MyDataEmily MyData = INIT_EMILY_MYDATA ;

// Birth
EmilyFunctions callEmily( void ){
     EmilyFunctions _EmilySkills = BIRTH_EMILY ;

     return _EmilySkills ;
}

//------------------------
// :[ NAME ]:
//     fnGetLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _EmilyyfnGetLine( string label ){
     int len ;

     if( label != NULL ){
          fputs( label, stdout ) ;
     }
     fgets( MyData.str, MAX_LENGTH, stdin ) ;
     len = strlen( MyData.str ) ;
     MyData.str[--len] = NL ;

     return MyData.str ;
}

//------------------------
// :[ NAME ]:
//     fnDispLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnDispLine( string str ){

     printf( "%s\n", str ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnDispLineCustom
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnDispLineCustom( string pre, string str, string suf ){

     if( pre == NULL ){
          pre = STR_EMPTY ;
     }
     if( suf == NULL ){
          suf = STR_EMPTY ;
     }
     printf( "%s%s%s\n", pre, str, suf ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnDispStr
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnDispStr( string str ){

     printf( "%s", str ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnDispStrCustom
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnDispStrCustom( string pre, string str, string suf ){

     if( pre == NULL ){
          pre = STR_EMPTY ;
     }
     if( suf == NULL ){
          suf = STR_EMPTY ;
     }
     printf( "%s%s%s", pre, str, suf ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnNewLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnNewLine( void ){

     printf( "\n" ) ;

     return ;
}
