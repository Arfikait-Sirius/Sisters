#include "Emily.h"

// Sisters呼び出し
void callSisters( void ){

     // Emilyを呼び出し
     Emily = callEmily() ;

     return ;
}

int main( void ){
     // Sisters呼び出し
     callSisters() ;

     string s ;

     // fnGetLine
     s = Emily.fnGetLine( "fnGetLine: " ) ;
     printf( "%s", s ) ;

     // fnDispLine
     Emily.fnDispLine( s ) ;

     // fnDispLineCustom
     Emily.fnDispLineCustom( "Input: ", s, " (inputed)." ) ;

     // fnDispStr
     Emily.fnDispStr( s ) ;

     // fnDispStrCustom
     Emily.fnDispStrCustom( "Input: ", s, "(inputed)." ) ;

     // fnNewLine
     Emily.fnNewLine() ;

     return CHAO ;
}
