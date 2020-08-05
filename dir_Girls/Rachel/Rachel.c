#include "Rachel.h"

// Name
static string MyName = "Rachel" ;

// Rachel's Memo
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
     char name[HALF_LENGTH] ;
     char msg[MEDIUM_LENGTH] ;

     sprintf( name, "%s.rachel", schemaName ) ;

     fp = fopen( name, "a+" ) ;
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
     strcpy( MyData.schemaName[MyData.schemaSeq], schemaName ) ;
     MyData.currSchema = MyData.schemafp[MyData.schemaSeq] ;
     MyData.currSeq = MyData.schemaSeq ;

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
     MyData.currSeq = schemaID ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnCreate
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnCreateBox( string dataID ){

     strcpy( MyData.newBox[MyData.newSeq], dataID ) ;

     return MyData.newSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnRegist
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnRegistData( int boxID, string data ){

     strcpy( MyData.newData[boxID], data ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnCommit
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnCommit( void ){
     FILE* fp ;
     int currNewSeq ;
     char name[HALF_LENGTH] ;
     char box[MAX_LENGTH] ;
     char msg[MEDIUM_LENGTH] ;

     sprintf( name, "%s.rachel", MyData.schemaName[MyData.currSeq] ) ;

     currNewSeq = MyData.newSeq - 1 ;
     sprintf( box, "%s@%s", MyData.newBox[currNewSeq], MyData.newData[currNewSeq] ) ;
     fputs( box, MyData.currSchema ) ;
     fclose( MyData.currSchema ) ;

     MyData.newSeq = 0 ;

     fp = fopen( name, "a+" ) ;
     if( fp == NULL ){
          sprintf( msg, "Failed to commit to schema: %s.", MyData.schemaName[MyData.currSeq] ) ;
          logSisters(
                    msg,
                    FTL,
                    MyName
               ) ;
          return ;
     }
     MyData.schemafp[MyData.currSeq] = fp ;
     fputc( LF, fp ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnGet
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnGetData( string dataID ){
     int result ;
     char* p ;
     char id[SHORT_LENGTH] ;
     char data[HALF_LENGTH] ;
     char tmp[HALF_LENGTH] ;

     rewind( MyData.currSchema ) ;

     p = fgets( tmp, HALF_LENGTH, MyData.currSchema ) ;
     if( p == NULL ){
          return NULL ;
     }
     while( p != NULL ){
          p = strchr( tmp, LF ) ;
          *p = NL ;
          result = sfnSplitData( tmp, id, data ) ;
          if( result == -1 ){
               return NULL ;
          }
          if( strcmp( dataID, id ) == 0 ){
               break ;
          }
          p = fgets( tmp, HALF_LENGTH, MyData.currSchema ) ;
     }
     strcpy( MyData.data, data ) ;

     return MyData.data ;
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

//------------------------
// :[ NAME ]:
//     sfnSplitData
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
int sfnSplitData( string tmp, string id, string data ){
     char* p ;

     p = strchr( tmp, '@' ) ;
     if( p == NULL ){
          return -1 ;
     }
     *p = NL ;
     strcpy( id, tmp ) ;
     p++ ;
     strcpy( data, p ) ;

     return 0 ;
}
