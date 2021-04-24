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
//     fnOpen
//
// :[ CATEGORY ]:
//     Skill
//------------------------
storage _AlicefnOpenStorage( string fileName, string storageType ){
     FILE* fp ;
     char* filePath ;

     filePath = malloc( strlen( fileName ) + 3 ) ;
     sprintf( filePath, "./%s", fileName ) ;
     fp = fopen( fileName, "r" ) ;
     free( filePath ) ;
     if( fp == NULL ){
          return -1 ;
     }
     MyData.fp[MyData.seq] = fp ;
     strcpy( MyData.type[MyData.seq], storageType ) ;

     return MyData.seq++ ;
}

//------------------------
// :[ NAME ]:
//     fnClose
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _AlicefnCloseStorage( storage storageID ){

     fclose( MyData.fp[storageID] ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnGet
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _AlicefnGetData( storage storageID, string key ){
     string data ;

     return data ;
}
