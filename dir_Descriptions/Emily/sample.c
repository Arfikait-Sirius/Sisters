#include "Emily.h"

// Sisters呼び出し関数
void callSisters( void ){

     // Emilyを呼び出し
     Emily = callEmily() ;

     return ;
}

int main( void ){
     // Sisters呼び出し
     callSisters() ;

     string s ;

     s = Emily.fnGetLine( "fnGetLine: " ) ;
     Emily.fnDispStr( "fnDispLine: " ) ;
     Emily.fnDispLine( s ) ;

     Emily.fnDispStr( "fnDispLineCustom: " ) ;
     Emily.fnDispLineCustom( "Input: ", s, NULL ) ;

     Emily.fnDispStr( "fnDispStr: " ) ;
     Emily.fnDispStr( "Hello!" ) ;

     Emily.fnNewLine() ;

     Emily.fnDispStr( "fnDispStrCustom: " ) ;
     Emily.fnDispStrCustom( NULL, s, "(inputed)." ) ;

     Emily.fnNewLine() ;

     Emily.fnDispStr( "fnNewLine: " ) ;
     Emily.fnNewLine() ;

     return CHAO ;
}
