#include "Louise.h"

// Name
static string MyName = "Louise" ;

// Louise's Memo
static _MyDataLouise MyData = INIT_LOUISE_MYDATA ;

// Birth
LouiseFunctions callLouise( void ){
     LouiseFunctions _LouiseSkills = BIRTH_LOUISE ;
     MyData.isLouise = true ;

     return _LouiseSkills ;
}

//------------------------
// :[ NAME ]:
//     fnCount
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _LouisefnCount( string data, string sepStr ){
     int len ;
     int counter = 0 ;
     char* p ;

     len = strlen( sepStr ) ;
     p = data ;
     p = strstr( p, sepStr ) ;
     while( p != NULL ){
          counter++ ;
          p = strstr( ( p + len ), sepStr ) ;
     }

     return counter ;
}

//------------------------
// :[ NAME ]:
//     fnCopy
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnCopy( string data ){
     int size ;
     bool isAllocation ;

     if( data == NULL ){
          return NULL ;
     }
     size = strlen( data ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     strcpy( MyData.str[MyData.seq], data ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnReplace
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnReplace( string base, string target, string replacement ){
     int size ;
     bool isAllocation ;
     int len ;
     char* p ;
     char* e ;
     int baseSize ;
     string s ;

     len = strlen( target ) ;
     baseSize = strlen( base ) + 1 ;
     s = malloc( baseSize ) ;
     strcpy( s, base ) ;
     p = strstr( s, target ) ;
     *p = NL ;
     e = p + len ;
     size = strlen( base ) - len + strlen( replacement ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     sprintf( MyData.str[MyData.seq], "%s%s%s", s, replacement, e ) ;
     free( s ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnSplit
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnSplit( string data, string splitter, int position ){
     int size ;
     bool isAllocation ;
     int i ;
     char* s ;
     char* p ;
     int splitterLen ;
     int dataSize ;
     string d ;

     splitterLen = strlen( splitter ) ;
     dataSize = strlen( data ) + 1 ;
     d = malloc( dataSize ) ;
     strcpy( d, data ) ;

     p = strstr( d, splitter ) ;
     s = d ;
     if( p == NULL ){
          return NULL ;
     }
     *p = NL ;
     for( i = 0 ; i < position ; i++ ){
          s = p + splitterLen ;
          p = strstr( s, splitter ) ;
          if( p == NULL ){
               break ;
          }
          *p = NL ;
     }
     size = strlen( s ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     strcpy( MyData.str[MyData.seq], s ) ;
     free( d ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnUpperAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnUpperAll( string data ){
     int size ;
     bool isAllocation ;
     char c ;
     char* result ;

     size = strlen( data ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     result = MyData.str[MyData.seq] ;
     c = *data++ ;
     while( c != NL ){
          if( LOWER_A <= c && c <= LOWER_Z ){
               c -= L_U_OFFSET ;
          }
          *result++ = c ;
          c = *data++ ;
     }

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnLowerAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnLowerAll( string data ){
     int size ;
     bool isAllocation ;
     char c ;
     string result ;

     size = strlen( data ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     result = MyData.str[MyData.seq] ;
     c = *data++ ;
     while( c != NL ){
          if( UPPER_A <= c && c <= UPPER_Z ){
               c += L_U_OFFSET ;
          }
          *result++ = c ;
          c = *data++ ;
     }
     *result = NL ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnUpperFirst
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnUpperFirst( string data ){
     int size ;
     bool isAllocation ;
     char c ;
     char* result ;

     size = strlen( data ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     result = MyData.str[MyData.seq] ;
     c = *data++ ;
     if( LOWER_A <= c && c <= LOWER_Z ){
          c -= L_U_OFFSET ;
     }
     *result++ = c ;
     c = *data++ ;
     while( c != NL ){
          if( UPPER_A <= c && c <= UPPER_Z ){
               c += L_U_OFFSET ;
          }
          *result++ = c ;
          c = *data++ ;
     }
     *result = NL ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnGetMiddle
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnGetMiddle( string format, string data ){
     int size ;
     bool isAllocation ;
     int flen ;
     int len ;
     char f[MAX_LENGTH] ;
     char d[MAX_LENGTH] ;
     char* p ;
     char* s ;
     char* e ;

     flen = strlen( format ) ;
     if( flen > strlen( data ) ){
          return NULL ;
     }
     strcpy( f, format ) ;
     p = strstr( f, "%s" ) ;
     *p = NL ;
     len = strlen( f ) ;
     e = p ;
     if( len + 2 != flen ){
          e += 2 ;
     }
     strcpy( d, data ) ;
     s = strstr( d, f ) ;
     if( *e != NL ){
          p = strstr( s, e ) ;
          if( p == NULL ){
               return NULL ;
          }
          *p = NL ;
     }
     size = strlen( s ) - len + 1 ;
     isAllocation = sfnAllocate( size ) ;
     strcpy( MyData.str[MyData.seq], s + len ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnTrim
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnTrim( string target ){
     int size ;
     bool isAllocation ;
     int targetSize ;
     string t ;
     char* p ;
     char* s ;

     targetSize = strlen( target ) + 1 ;
     t = malloc( targetSize ) ;
     strcpy( t, target ) ;
     p = t ;
     while( *p == SPACE || *p == TAB ){
          p++ ;
     }
     s = p ;
     p = strchr( t, NL ) ;
     p-- ;
     while( *p == SPACE || *p == TAB ){
          p-- ;
     }
     *++p = NL ;
     size = strlen( s ) + 1 ;
     isAllocation = sfnAllocate( size ) ;
     strcpy( MyData.str[MyData.seq], s ) ;
     free( t ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnFromInt
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnFromInt( int num ){
     int size ;
     bool isAllocation ;
     int n ;
     int digit ;

     n = num ;

     digit = 1 ;
     n /= 10 ;
     while( n != 0 ){
          n /= 10 ;
          digit++ ;
     }

     size = digit + 1 ;
     isAllocation = sfnAllocate( size ) ;
     sprintf( MyData.str[MyData.seq], "%d", num ) ;

     return MyData.str[MyData.seq++] ;
}

//------------------------
// :[ NAME ]:
//     fnFind
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _LouisefnFind( string base, string target ){
     int position ;
     char* p ;
     char* q ;
     char* r ;

     position = 0 ;
     p = base ;
     q = target ;
     r = p ;
     while( *p != NL ){
          while( *r == *q ){
               r++ ;
               q++ ;
          }
          if( *q == NL ){
               break ;
          }
          q = target ;
          p++ ;
          r = p ;
          position++ ;
     }

     return position ;
}

//------------------------
// :[ NAME ]:
//     fnGetLength
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _LouisefnGetLength( string data ){
     int len = 0 ;

     if( data != NULL ){
          len = strlen( data ) ;
     }

     return len ;
}

//------------------------
// :[ NAME ]:
//     isMatch
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _LouiseisFormat( string data, string format ){
     int i ;
     int len ;
     int pos ;
     char tmpStr[256] = { NL } ;
     char* p ;
     string strFormat ;

     strFormat = format ;
     pos = 0 ;
     p = strstr( strFormat, "%s" ) ;
     while( p != NULL ){
          len = p - strFormat ;
          for( i = 0 ; i < len ; i++ ){
               tmpStr[i] = *( strFormat + i ) ;
          }
          p++ ;
          strFormat = ++p ;
          if( tmpStr[0] == NL ){
               p = strstr( strFormat, "%s" ) ;
               continue ;
          }
          p = strstr( ( data + pos ), tmpStr ) ;
          if( p == NULL ){
               return false;
          }
          pos = len ;
          p = strstr( strFormat, "%s" ) ;
     }
     strcpy( tmpStr, strFormat ) ;
     p = strstr( ( data + pos ), tmpStr ) ;
     if( p == NULL ){
          return false ;
     }

     return true ;
}

//------------------------
// :[ NAME ]:
//     isContain
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _LouiseisContain( string data, string target ){
     char* p ;

     p = strstr( data, target ) ;
     if( p == NULL ){
          return false ;
     }

     return true ;
}

//------------------------
// :[ NAME ]:
//     isEqual
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _LouiseisEqual( string org, string target ){

     if( strcmp( org, target ) == 0 ){
          return true ;
     }

     return false ;
}

//------------------------
// :[ NAME ]:
//     isEmpty
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _LouiseisEmpty( string data ){

     if( data == NULL ){
          return true ;
     }
     if( *data == NL ){
          return true ;
     }

     return false ;
}

//------------------------
// :[ NAME ]:
//     sfnAllocate
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static bool sfnAllocate( int size ){

     if( MyData.seq == LOUISE_MAX_STRINGS ){
          return false ;
     }
     MyData.str[MyData.seq] = malloc( size ) ;
     if( MyData.str[MyData.seq] == NULL ){
          return false ;
     }

     return true ;
}

//------------------------
// :[ NAME ]:
//     lvCalled
//
// :[ CATEGORY ]:
//     Leave
//------------------------
bool _LouiselvCalled( void ){
     bool called = false ;

     if( MyData.isLouise ){
          called = true ;
          MyData.isLouise = false ;
     }

     return called ;
}

//------------------------
// :[ NAME ]:
//     lvFree
//
// :[ CATEGORY ]:
//     Leave
//------------------------
void _LouiselvFree( void ){
     int i ;

     for( i = 0 ; i < MyData.seq ; i++ ){
          free( MyData.str[i] ) ;
     }

     return ;
}
