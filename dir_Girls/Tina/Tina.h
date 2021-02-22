#ifndef _TINA_
#define _TINA_


//--< Use Headers >--//
#include "stdio.h"
#include "stdbool.h"


//--< Standard Definition >--//
#include "../../dir_Specifications/siscmn.h"
#include "../../dir_Specifications/sisdef.h"


//--< Prototype Declarations >--//
void _TinafnSetGirlName( string ) ;
void _TinafnSetSkillName( string ) ;
void _TinafnJudge( bool ) ;
void _TinafnPrint( string ) ;


/* <] - Tina - [> */
typedef struct _tina_functions{
     void ( *fnSetGirlName )( string ) ;
     void ( *fnSetSkillName )( string ) ;
     void ( *fnJudge )( bool ) ;
     void ( *fnPrint )( string ) ;
}TinaFunctions ;

#define BIRTH_TINA {\
     _TinafnSetGirlName,\
     _TinafnSetSkillName,\
     _TinafnJudge,\
     _TinafnPrint\
}

static TinaFunctions Tina ;

TinaFunctions callTina( void ) ;


//--< MyData Declaration >--//
typedef struct _myDataTina{
}_MyDataTina ;

#define INIT_TINA_MYDATA {\
}


//--< Free Definitions >--//
#define LABEL_GIRLS_NAME "[GIRLS-NAME]: "
#define LABEL_TARGET "[    TARGET]: "
#define LABEL_JUDGE "[     JUDGE]: "
#define LABEL_PRINT "[     PRINT]: "


#endif
