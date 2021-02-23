#include "Grace.h"

// Name
static string MyName = "Grace" ;

// Grace's Memo
static _MyDataGrace MyData = INIT_GRACE_MYDATA ;

// Birth
GraceFunctions callGrace( void ){
     GraceFunctions _GraceSkills = BIRTH_GRACE ;

     return _GraceSkills ;
}

//------------------------
// :[ NAME ]:
//     fnService
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _GracefnService( int portNumber ){
     int socketRead ;
     int socketWrite ;
     char method[MIN_LENGTH] ;
     char url[HALF_LENGTH] ;
     char protocol[HALF_LENGTH] ;
     int result ;

     socketRead = sfnBindSocket( portNumber ) ;
     if( socketRead < 0 ){
          return ;
     }

     listen( socketRead, 5 ) ;
     while( true ){
          socketWrite = sfnAccept( socketRead, method, url, protocol ) ;
          if( socketWrite < 0 ){
               return ;
          }

          result = sfnSendProperty( socketWrite, url ) ;
          if( result < 0 ){
               close( socketWrite ) ;
               return ;
          }

          result = sfnSendHTML( socketWrite, url ) ;
          if( result < 0 ){
               close( socketWrite ) ;
               return ;
          }
          close( socketWrite ) ;
     }
     close( socketRead ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     sfnBindSocket
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static int sfnBindSocket( int portNumber ){
     int sock ;
     struct sockaddr_in addr ;
     int result ;

     sock = socket( AF_INET, SOCK_STREAM, 0 ) ;

     if( sock < 0 ){
          fprintf( stderr, "Error: Cannot create socket.\n" ) ;
          return -1 ;
     }

     addr.sin_family = AF_INET ;
     addr.sin_port = htons( portNumber ) ;
     addr.sin_addr.s_addr = INADDR_ANY ;

     result = bind( sock, ( struct sockaddr* )&addr, sizeof( addr ) ) ;

     if( result < 0 ){
          fprintf( stderr, "Error: Cannot bind.\n" ) ;
          return -1 ;
     }

     return sock ;
}

//------------------------
// :[ NAME ]:
//     sfnAccept
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static int sfnAccept( int socketRead, string method, string url, string protocol ){
     int sock ;
     struct sockaddr_in client ;
     socklen_t len ;
     char buf[MAX_LENGTH] ;
     int result ;

     len = sizeof( client ) ;
     memset( &client, 0, len ) ;
     memset( buf, 0, sizeof( buf ) ) ;
     memset( method, 0, MIN_LENGTH) ;
     memset( url, 0, HALF_LENGTH ) ;
     memset( protocol, 0, HALF_LENGTH ) ;

     sock = accept( socketRead, ( struct sockaddr* )&client, &len ) ;
     printf( "accept\n" ) ;

     result = recv( sock, buf, sizeof( buf ), 0 ) ;
     if( result < 0 ){
          fprintf( stderr, "Error: Cannot receive request.\n" ) ;
          return -1 ;
     }

     sscanf( buf, "%s %s %s", method, url, protocol ) ;
     printf( "%s\n", url ) ;

     return sock ;
}

//------------------------
// :[ NAME ]:
//     sfnSendProperty
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static int sfnSendProperty( int sock, string url ){
     FILE* fp ;
     char fileName[MAX_LENGTH] = { NL } ;
     char responseHeader[DOUBLE_LENGTH] = { NL } ;
     char contentLength[SHORT_LENGTH] = { NL } ;
     char contentType[SHORT_LENGTH] = { NL } ;
     char property[MAX_LENGTH] ;
     int size ;

     sprintf( fileName, GRACE_PROPERTY, url ) ;
     fp = fopen( fileName, "r" ) ;
     if( fp == NULL ){
          fprintf( stderr, "Error: Cannot read property file.\n" ) ;
          return -1 ;
     }
     fgets( property, MAX_LENGTH, fp ) ;
     sprintf( contentLength, "Content-Length: %s", property ) ;
     fgets( property, MAX_LENGTH, fp ) ;
     sprintf( contentType, "Content-Type: text/%s", property ) ;
     sprintf( responseHeader,
               "%s\r\n%s%s\r\n\r\n",
               "HTTP/1.1 200 OK",
               contentLength,
               contentType
          ) ;
     size = strlen( responseHeader ) ;
     send( sock, responseHeader, size, 0 ) ;
     printf( "[ Size ]\n%d\n[ Header ]\n%s", size, responseHeader ) ;
     fclose( fp ) ;

     return 0 ;
}

//------------------------
// :[ NAME ]:
//     sfnSendHTML
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static int sfnSendHTML( int sock, string url ){
     FILE* fp ;
     char fileName[MAX_LENGTH] = { NL } ;
     char str[MAX_LENGTH] ;
     int size ;
     char* p ;

     sprintf( fileName, GRACE_PATH, url ) ;
     fp = fopen( fileName, "r" ) ;
     if( fp == NULL ){
          fprintf( stderr, "Error: Cannot read grace file.\n" ) ;
          return -1 ;
     }
     printf( "[ Body ]\n" ) ;
     p = fgets( str, MAX_LENGTH, fp ) ;
     while( p != NULL ){
          size = strlen( str ) ;
          send( sock, str, size + 1, 0 ) ;
          printf( "%s", str ) ;
          p = fgets( str, MAX_LENGTH, fp) ;
     }
     fclose( fp ) ;

     return 0 ;
}

//------------------------
// :[ NAME ]:
//     fnDeploy
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _GracefnDeploy( string fileName ){
     FILE* sfp ;
     FILE* dfp ;
     char str[MAX_LENGTH] ;
     char* p ;
     char fileNameOmitExtension[HALF_LENGTH] = { NL } ;
     char graceFileName[MAX_LENGTH] = { NL } ;
     char gracePropertyFileName[MAX_LENGTH] = { NL } ;
     int len ;
     int line ;
     char contentLength[MIN_LENGTH] = { NL } ;
     char s[HALF_LENGTH] = { NL } ;

     sfnSplitFileName( fileName ) ;
     if( strcmp( MyData.type, GRACE_HTML ) == 0 ){
          strcpy( MyData.type, "html" ) ;
     }
     strcpy( fileNameOmitExtension, MyData.name ) ;
     sprintf( graceFileName, GRACE_PATH, fileNameOmitExtension ) ;
     sfp = fopen( fileName, "r" ) ;
     if( sfp == NULL ){
          return ;
     }
     dfp = fopen( graceFileName, "w" ) ;
     if( dfp == NULL ){
          return ;
     }
     line = 0 ;
     len = 0 ;
     p = fgets( str, MAX_LENGTH, sfp ) ;
     while( p != NULL ){
          line++ ;
          sfnGenerateHTML( s, str ) ;
          if( s[0] == NL ){
               fprintf( stderr, "Error: Cannot generated. - %s\n", str ) ;
               break ;
          }
          len += strlen( s ) ;
          fputs( s, dfp ) ;
          p = fgets( str, MAX_LENGTH, sfp ) ;
     }
     fclose( dfp ) ;
     fclose( sfp ) ;
     sprintf( contentLength, "%d\n", len + line ) ;
     sprintf( gracePropertyFileName, GRACE_PROPERTY, fileNameOmitExtension ) ;
     dfp = fopen( gracePropertyFileName, "w" ) ;
     if( dfp == NULL ){
          return ;
     }
     fputs( contentLength, dfp ) ;
     fputs( MyData.type, dfp ) ;
     fclose( dfp ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnSetValue
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _GracefnSetValue( string key, string value ){

     strcpy( MyData.key[MyData.index], key ) ;
     strcpy( MyData.value[MyData.index], value ) ;

     MyData.index++ ;

     return ;
}

static void sfnSplitFileName( string fileName ){
     char c ;
     char* p ;
     char* q ;
     int i ;
     int len ;

     p = fileName ;
     q = MyData.name ;
     len = strlen( fileName ) ;
     for( i = 0 ; i < len ; i++ ){
          if( *p == DOT ){
               if( *( p + 1 ) == DOT || *( p + 1 ) == SLASH ){
                    p++ ;
                    continue ;
               }
               *q++ = NL ;
               q = MyData.type ;
               p++ ;
          }
          if( *p == SLASH ){
               p++ ;
               q = MyData.name ;
               continue ;
          }
          *q++ = *p++ ;
     }
     *q = NL ;

     return ;
}

static void sfnGenerateHTML( string buffer, string readStr ){
     char tmp[MIN_LENGTH] ;
     char* b ;
     char* r ;
     char* t ;
     int len ;
     string value ;

     b = buffer ;
     r = readStr ;
     t = tmp ;

     while( *r != NL ){
          if( *r == DOLLAR && *( r + 1 ) == BRACE_LEFT ){
               t = tmp ;
               r += 2 ;
               *b++ = NL ;
          } else if( *r == BRACE_RIGHT ){
               *t = NL ;
               value = sfnGetValue( tmp ) ;
               if( value == NULL ){
                    *buffer = NL ;
                    return ;
               }
               strcat( buffer, value ) ;
               len = strlen( buffer ) ;
               b = buffer + len ;
               r++ ;
          }
          *t++ = *r ;
          *b++ = *r++ ;
     }
     *b = NL ;

     return ;
}

static string sfnGetValue( string key ){
     int i ;

     for( i = 0 ; MyData.key[i][0] != NL ; i++ ){
          if( strcmp( MyData.key[i], key ) == 0 ){
               return MyData.value[i] ;
          }
     }

     return NULL ;
}
