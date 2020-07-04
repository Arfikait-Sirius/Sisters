#include "Alice.h"

//------------------------
// :[ NAME ]:
//     mfnAlice
//
// :[ CATEGORY ]:
//     Solo
//------------------------
int mfnAlice( int argc, char* argv[] ){

     if( argc < 3 ){
          logSisters( "Too few arguments.", ERROR, Alice_ID ) ;
          return CHAO ;
     }
     if( argc > 4 ){
          logSisters( "Too many arguments.", ERROR, Alice_ID ) ;
          return CHAO ;
     }
     if( strcmp( argv[1], "run" ) == 0 ){
          logSisters( "Running...", INFO, Alice_ID ) ;
          return CHAO ;
     }
     if( strcmp( argv[1], "set" ) == 0 ){
          logSisters( "Setting...", INFO, Alice_ID ) ;
          return CHAO ;
     }
     logSisters( "The arguments cannot use.", ERROR, Alice_ID ) ;

     return CHAO ;
}

void _fnGreetAlice( void ){

     printf( "My name is Alice.\n" ) ;

     return ;
}
