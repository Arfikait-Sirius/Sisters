#include "Chloe.h"

// Name
static string MyName = "Chloe" ;

// Chloe's Memo
static _MyDataChloe MyData = INIT_CHLOE_MYDATA ;

// Birth
ChloeFunctions callChloe( void ){
     ChloeFunctions _ChloeSkills = BIRTH_CHLOE ;

     return _ChloeSkills ;
}

//------------------------
// :[ NAME ]:
//     acYes
//
// :[ CATEGORY ]:
//     Accessory
//------------------------
string _ChloeacYes( void ){
     return MyData.YES ;
}

//------------------------
// :[ NAME ]:
//     acNo
//
// :[ CATEGORY ]:
//     Accessory
//------------------------
string _ChloeacNo( void ){
     return MyData.NO ;
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
bool _ChloeisNo( string judgement ){

     if( strcmp( judgement, MyData.NO ) == 0 ){
          return true ;
     }

     return false ;
}
