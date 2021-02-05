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
string _EmilyfnGetLine( string label ){
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

//------------------------
// :[ NAME ]:
//     fnBackLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnBackLine( int line ){
     int i ;

     for( i = 0 ; i < line ; i++ ){
          printf( "\x1B[1A" ) ;
     }

     return ;
}

//------------------------
// :[ NAME ]:
//     fnClearAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnClearAll( void ){

     printf( "\x1B[2J" ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnClearLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnClearLine( void ){
     printf( "\x1B[0K" ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnClearBackLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _EmilyfnClearBackLine( int line ){
     int i ;

     for( i = 0 ; i < line ; i++ ){
          printf( "\x1B[1F" ) ;
          printf( "\x1B[0K" ) ;
     }

     return ;
}
