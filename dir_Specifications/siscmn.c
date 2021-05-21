#include "siscmn.h"

int chao( void ){

     if( _LouiselvCalled() ){
          _LouiselvFree() ;
     }

     if( _KotonelvCalled() ){
          _KotonelvFree() ;
     }

     return 0 ;
}
