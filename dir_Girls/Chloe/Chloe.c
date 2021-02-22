#include "Chloe.h"

// Name
static string MyName = "Chloe" ;

// Chloe's Memo
static _MyDataChloe MyData ;

// Birth
ChloeFunctions callChloe( void ){
     ChloeFunctions _ChloeSkills = BIRTH_CHLOE ;

     return _ChloeSkills ;
}

//------------------------
// :[ NAME ]:
//     acNot
//
// :[ CATEGORY ]:
//     Accessory
//------------------------
bool _acNot( bool b ){

     if( b ){
          return false ;
     }

     return true ;
}

//------------------------
// :[ NAME ]:
//     fnPass
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnPass( void ){

     // Do not anything.

     return ;
}

//------------------------
// :[ NAME ]:
//     isNo
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isNo( string judgement ){

     sfnToLower( judgement ) ;
     if( strcmp( judgement, NO ) == 0 || strcmp( judgement, "no" ) == 0 ){
          return true ;
     }

     return false ;
}

static void sfnToLower( string s ){
     char* p ;

     p = s ;
     while( *p != NL ){
          if( LOWER_A <= *p && *p <= LOWER_Z ){
               *p += L_U_OFFSET ;
          }
          p++ ;
     }

     return ;
}
