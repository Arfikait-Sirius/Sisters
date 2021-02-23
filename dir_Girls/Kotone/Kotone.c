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
//     fnCreateList
//
// :[ CATEGORY ]:
//     Skill
//------------------------
list _KotonefnCreateList( mode m ){
     return MyData.listSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnAddList
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _KotonefnAddList( list listID, string s ){

     MyData.myList[listID][MyData.listIndex[listID]] = s ;
     MyData.listIndex[listID]++ ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnCreateStack
//
// :[ CATEGORY ]:
//     Skill
//------------------------
stack _KotonefnCreateStack( mode m ){
     return MyData.stackSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnPushStack
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _KotonefnPushStack( stack stackID, string s ){

     MyData.myStack[stackID][MyData.stackIndex[stackID]] = s ;
     MyData.stackIndex[stackID]++ ;

     return ;
}
