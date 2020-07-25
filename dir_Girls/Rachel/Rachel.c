#include "Rachel.h"

// Name
static string MyName = "Rachel" ;

// Louise's Memo
static _MyDataRachel MyData = INIT_RACHEL_MYDATA ;

// Birth
RachelFunctions callRachel( void ){
     RachelFunctions _RachelSkills = BIRTH_RACHEL ;

     return _RachelSkills ;
}

//------------------------
// :[ NAME ]:
//     fnOpen
//
// :[ CATEGORY ]:
//     Skill
//------------------------
schema _fnOpenSchema( string schemaName ){
     FILE* fp ;
     char msg[MEDIUM_LENGTH] ;

     fp = fopen( schemaName, "r" ) ;
     if( fp == NULL ){
          sprintf( msg, "Cannot find schema: %s.", schemaName ) ;
          logSisters(
                    msg,
                    FTL,
                    MyName
               ) ;
          return TOO_BAD ;
     }
     MyData.schemafp[MyData.schemaSeq] = fp ;
     MyData.schemaName[MyData.schemaSeq] = schemaName ;
     MyData.currSchema = MyData.schemafp[MyData.schemaSeq] ;

     return MyData.schemaSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnChange
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnChangeSchema( schema schemaID ){

     if( MyData.schemafp[schemaID] == NULL ){
          MyData.currSchema = NULL ;
          logSisters(
                    "Cannot change schema.",
                    ERR,
                    MyName
               ) ;
          return ;
     }

     MyData.currSchema = MyData.schemafp[schemaID] ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnClose
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnCloseSchema( schema schemaID ){

     if( MyData.schemaName[schemaID] == NULL ){
          logSisters(
                    "Cannot close schema.",
                    FTL,
                    MyName
               ) ;
          return ;
     }

     fclose( MyData.schemafp[schemaID] ) ;

     return ;
}
