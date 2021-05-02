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
schema _RachelfnOpen( string schemaName ){
     FILE* fp ;
     char name[HALF_LENGTH] ;
     char msg[MEDIUM_LENGTH] ;

     sprintf( name, "%s.rachel", schemaName ) ;

     fp = fopen( name, "a+" ) ;
     if( fp == NULL ){
          return -1 ;
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
void _RachelfnChange( schema schemaID ){

     if( MyData.schemafp[schemaID] == NULL ){
          MyData.currSchema = NULL ;
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
int _RachelfnCreate( string dataID ){

     strcpy( MyData.newBox[MyData.newSeq], dataID ) ;

     return MyData.newSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnRegister
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _RachelfnRegister( int boxID, string data ){

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
void _RachelfnCommit( void ){
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
          return ;
     }
     MyData.schemafp[MyData.currSeq] = fp ;
     fputc( LF, fp ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnGetValue
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _RachelfnGetValue( string dataID ){
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
void _RachelfnClose( schema schemaID ){

     if( MyData.schemaName[schemaID] == NULL ){
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
