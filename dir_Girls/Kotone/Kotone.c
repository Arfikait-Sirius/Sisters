#include "Kotone.h"

// Name
static string MyName = "Kotone" ;

// Kotone's Memo
static _MyDataKotone MyData = INIT_KOTONE_MYDATA ;

// Birth
KotoneFunctions callKotone( void ){
     KotoneFunctions _KotoneSkills = BIRTH_KOTONE ;

     return _KotoneSkills ;
}

//------------------------
// :[ NAME ]:
//     fnCreate
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnCreateList( mode m ){

     if( m == TMP ){
          return TMP_LIST ;
     }

     return MyData.seq++ ;
}

//------------------------
// :[ NAME ]:
//     fnAdd_p
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnAddList_p( int listID, pointer p ){

     MyData.plist[listID][MyData.index[listID]] = p ;
     MyData.index[listID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnAdd_c
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnAddList_c( int listID, char c ){

     MyData.clist[listID][MyData.index[listID]] = c ;
     MyData.index[listID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnAdd_s
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnAddList_s( int listID, string s ){

     MyData.slist[listID][MyData.index[listID]] = s ;
     MyData.index[listID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnAdd_i
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnAddList_i( int listID, int i ){

     MyData.ilist[listID][MyData.index[listID]] = i ;
     MyData.index[listID]++ ;

     return ;
}
