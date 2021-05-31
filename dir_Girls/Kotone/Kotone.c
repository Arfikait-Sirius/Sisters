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
     int i ;
     int index ;
     _ListData* currAddress ;
     _ListData* prev ;
     int size ;

     for( i = 0 ; i < MyData.accessIndex[listID] ; i++ ){
          if( MyData.accessList[listID][i] == NULL ){
               break ;
          }
     }
     index = i ;

     size = strlen( s ) + 1 ;
     MyData.myList[listID][index].data = malloc( size ) ;
     strcpy( MyData.myList[listID][index].data, s ) ;
     currAddress = &( MyData.myList[listID][index] ) ;
     MyData.accessList[listID][index] = currAddress ;
     MyData.accessIndex[listID]++ ;

     if( index == 0 ){
          prev = NULL ;
     }else{
          prev = &( MyData.myList[listID][index - 1] ) ;
     }
     MyData.myList[listID][index].prev = prev ;

     MyData.myList[listID][index - 1].next = currAddress ;

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

     return MyData.accessList[listID][index]->data ;
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
          for( j = 0 ; j < KOTONE_MAX_LIST_SIZE ; j++ ){
               if( MyData.myList[i][j].data == NULL ){
                    continue ;
               }
               free( MyData.myList[i][j].data ) ;
          }
     }

     return ;
}
