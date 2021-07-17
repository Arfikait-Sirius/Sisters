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
     int index ;
     int size ;
     _ListData* currAddress ;
     _ListData* prev ;

     index = MyData.myIndex[listID] ;

     size = strlen( s ) + 1 ;
     MyData.myList[listID][index].data = malloc( size ) ;
     strcpy( MyData.myList[listID][index].data, s ) ;
     currAddress = &( MyData.myList[listID][index] ) ;

     if( index == 0 ){
          MyData.myList[listID][index].prev = NULL ;
     }else{
          MyData.myList[listID][index].prev = &( MyData.myList[listID][index - 1] ) ;
          MyData.myList[listID][index - 1].next = currAddress ;
     }

     MyData.myIndex[listID]++ ;

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
     int i ;

     i = index ;

     return MyData.myList[listID][i].data ;
}

//------------------------
// :[ NAME ]:
//     fnRemove
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _KotonefnRemove( list listID, int index ){
     int i ;

     i = index ;
     if( MyData.myList[listID][i].prev != NULL ){
          MyData.myList[listID][i - 1].next = MyData.myList[listID][i + 1].next ;
     }
     if( MyData.myList[listID][i].next != NULL ){
          MyData.myList[listID][i + 1].prev = MyData.myList[listID][i].prev ;
     }

     free( MyData.myList[listID][i].data ) ;

     return ;
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
