#include "Kotone.h"

// Name
static string MyName = "Kotone" ;

// Kotone's Memo
static _MyDataKotone MyData = INIT_KOTONE_MYDATA ;

// Birth
KotoneFunctions callKotone( void ){
     KotoneFunctions _KotoneSkills = BIRTH_KOTONE ;
     MyData.isKotone = true ;

     return _KotoneSkills ;
}

//------------------------
// :[ NAME ]:
//     fnCreate
//
// :[ CATEGORY ]:
//     Skill
//------------------------
list _KotonefnCreate( void ){
     return MyData.seq++ ;
}

//------------------------
// :[ NAME ]:
//     fnAdd
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _KotonefnAdd( list listID, string s ){
     int size ;

     size = strlen( s ) + 1 ;
     MyData.myList[listID][MyData.index[listID]] = malloc( size ) ;
     strcpy( MyData.myList[listID][MyData.index[listID]], s );
     MyData.index[listID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnGet
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _KotonefnGet( list listID, int index ){
     if( MyData.index[listID] <= index ){
          return NULL ;
     }

     return MyData.myList[listID][index] ;
}

//------------------------
// :[ NAME ]:
//     lvCalled
//
// :[ CATEGORY ]:
//     Leave
//------------------------
bool _KotonelvCalled( void ){
     bool called = false ;

     if( MyData.isKotone ){
          called = true ;
          MyData.isKotone = false ;
     }

     return called ;
}

//------------------------
// :[ NAME ]:
//     lvFree
//
// :[ CATEGORY ]:
//     Leave
//------------------------
void _KotonelvFree( void ){
     int i ;
     int j ;

     for( i = 0 ; i < MyData.seq ; i++ ){
          for( j = 0 ; j < MyData.index[i] ; j++ ){
               free( MyData.myList[i][j] ) ;
          }
     }

     return ;
}
