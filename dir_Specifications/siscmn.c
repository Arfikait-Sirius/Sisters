#include "siscmn.h"

int chao( void ){
     printf( "Finish!!\n" ) ;

     if( _LouiselvCalled() ){
          printf( "Leave Louise.\n" ) ;
          _LouiselvFree() ;
     }

     return 0 ;
}
