#include "Alice.h"

// Name
static string MyName = "Alice" ;

// Alice's Memo
static _MyDataAlice MyData = INIT_ALICE_MYDATA ;

// Birth
AliceFunctions callAlice( void ){
     AliceFunctions _AliceSkills = BIRTH_ALICE ;

     return _AliceSkills ;
}

//------------------------
// :[ NAME ]:
//     fnCreate
//
// :[ CATEGORY ]:
//     Skill
//------------------------
pochette _AlicefnCreate( void ){
     if( MyData.seq >= ALICE_MAX_POCHETTES ){
          return 0 ;
     }
     return MyData.seq++ ;
}

//------------------------
// :[ NAME ]:
//     fnPutString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _AlicefnPutString( pochette pochetteID, string key, string value ){
     MyData.poc[pochetteID][MyData.curr[pochetteID]].key = malloc( strlen( key ) + 1 ) ;
     MyData.poc[pochetteID][MyData.curr[pochetteID]].value = malloc( strlen( value ) + 1 ) ;

     strcpy( MyData.poc[pochetteID][MyData.curr[pochetteID]].key, key ) ;
     strcpy( MyData.poc[pochetteID][MyData.curr[pochetteID]].type, "string" ) ;
     strcpy( MyData.poc[pochetteID][MyData.curr[pochetteID]].value, value ) ;

     MyData.curr[pochetteID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnGetString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _AlicefnGetString( pochette pochetteID, string key ){
     string result ;
     int i ;

     for( i = 0 ; i < MyData.curr[pochetteID] ; i++ ){
          if( strcmp( MyData.poc[pochetteID][i].key, key ) == 0 ){
               result = MyData.poc[pochetteID][i].value ;
               break ;
          }
     }

     return result ;
}

//------------------------
// :[ NAME ]:
//     fnToString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _AlicefnToString( pochette pochetteID ){
     int len ;
     int i ;
     char str[64 + 1] = { NL } ;

     len = MyData.curr[pochetteID] * 64 + 5 + 1 ;
     MyData.str[pochetteID] = malloc( len + 1 ) ;
     strcat( MyData.str[pochetteID], "[" ) ;
     for( i = 0 ; i < MyData.curr[pochetteID] ; i++ ){
          if( i > 0 ) {
               strcat( MyData.str[pochetteID], "," ) ;
          }
          sprintf( str, "%s@%s=%s", MyData.poc[pochetteID][i].key, MyData.poc[pochetteID][i].type, MyData.poc[pochetteID][i].value ) ;
          sprintf( MyData.str[pochetteID], "%s%s", MyData.str[pochetteID], str ) ;
     }
     strcat( MyData.str[pochetteID], "]" ) ;

     return MyData.str[pochetteID] ;
}
