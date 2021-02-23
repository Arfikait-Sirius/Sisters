#include "Louise.h"

// Name
static string MyName = "Louise" ;

// Louise's Memo
static _MyDataLouise MyData = INIT_LOUISE_MYDATA ;

// Birth
LouiseFunctions callLouise( void ){
     LouiseFunctions _LouiseSkills = BIRTH_LOUISE ;

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
     int counter = MyData.cpyCounter ;
     int i ;
     bool result = true ;

     for( i = 0 ; i < LOUISE_MAX_CPY_SIZE ; i++ ){
          if( strcmp( data, MyData.cpyStr[i] ) == 0 ){
               result = false ;
               counter = i ;
               break ;
          }
     }
     if( result ){
          strcpy( MyData.cpyStr[counter], data ) ;
          MyData.cpyCounter++ ;
     }

     return MyData.cpyStr[counter] ;
}

//------------------------
// :[ NAME ]:
//     fnReplace
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnReplace( string base, string target, string replacement ){
     int len ;
     char* p ;
     char* e ;
     char s[MAX_LENGTH] ;

     len = strlen( target ) ;
     strcpy( s, base ) ;
     p = strstr( s, target ) ;
     *p = NL ;
     e = p + len ;
     sprintf( MyData.repStr, "%s%s%s", s, replacement, e ) ;

     return MyData.repStr ;
}

//------------------------
// :[ NAME ]:
//     fnSplit
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnSplit( string data, char splitter, int position ){
     int i ;
     char* s ;
     char* p ;
     char d[MAX_LENGTH] ;

     strcpy( d, data ) ;

     p = strchr( d, splitter ) ;
     s = d ;
     if( p == NULL ){
          return NULL ;
     }
     *p++ = NL ;
     strcpy( MyData.splStr, s ) ;
     for( i = 0 ; i < position ; i++ ){
          s = p ;
          p = strchr( p, splitter ) ;
          if( p == NULL ){
               break ;
          }
          *p++ = NL ;
          strcpy( MyData.splStr, s ) ;
     }
     if( i < position ){
          strcpy( MyData.splStr, s ) ;
     }

     return MyData.splStr ;
}

//------------------------
// :[ NAME ]:
//     fnUpperAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnUpperAll( string data ){
     char c ;
     char* result ;

     result = MyData.uprStr ;
     c = *data++ ;
     while( c != NL ){
          if( LOWER_A <= c && c <= LOWER_Z ){
               c -= L_U_OFFSET ;
          }
          *result++ = c ;
          c = *data++ ;
     }

     return MyData.uprStr ;
}

//------------------------
// :[ NAME ]:
//     fnLowerAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnLowerAll( string data ){
     char c ;
     string result ;

     result = MyData.lwrStr ;
     c = *data++ ;
     while( c != NL ){
          if( UPPER_A <= c && c <= UPPER_Z ){
               c += L_U_OFFSET ;
          }
          *result++ = c ;
          c = *data++ ;
     }
     *result = NL ;

     return MyData.lwrStr ;
}

//------------------------
// :[ NAME ]:
//     fnUpperFirst
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnUpperFirst( string data ){
     char c ;
     char* result ;

     result = MyData.fstStr ;
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

     return MyData.fstStr ;
}

//------------------------
// :[ NAME ]:
//     fnGetMiddle
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnGetMiddle( string format, string data ){
     int flen ;
     int len ;
     char f[MAX_LENGTH] ;
     char d[MAX_LENGTH] ;
     char* p ;
     char* s ;
     char* e ;

     flen = strlen( format ) ;
     if( flen > strlen( data ) ){
          logSisters(
                    "Length of \"format\" is over length of \"data\".",
                    ERR,
                    MyName
               ) ;
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
     strcpy( MyData.midStr, s + len ) ;

     return MyData.midStr ;
}

//------------------------
// :[ NAME ]:
//     fnTrim
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnTrim( string target ){
     char str[MAX_LENGTH] ;
     char* p ;
     char* s ;

     strcpy( str, target ) ;
     p = str ;
     while( *p == SPACE || *p == TAB ){
          p++ ;
     }
     s = p ;
     p = strchr( str, NL ) ;
     p-- ;
     while( *p == SPACE || *p == TAB ){
          p-- ;
     }
     *++p = NL ;
     strcpy( MyData.trmStr, s ) ;

     return MyData.trmStr ;
}

//------------------------
// :[ NAME ]:
//     fnToString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _LouisefnToString( int num ){
     char result[MEDIUM_LENGTH] ;

     sprintf( result, "%d", num ) ;
     strcpy( MyData.numStr, result ) ;

     return MyData.numStr ;
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
