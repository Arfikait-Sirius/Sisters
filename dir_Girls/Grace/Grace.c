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
//     fnRunServer
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnService( void ){
     FILE* fp ;
     int socketRead ;
     int socketWrite ;
     struct sockaddr_in addr ;
     struct sockaddr_in client ;
     socklen_t len ;
     int result ;
     int size ;
     char buf[MAX_LENGTH] ;
     char method[HALF_LENGTH] ;
     char url[HALF_LENGTH] ;
     char protocol[HALF_LENGTH] ;
     char fileName[MAX_LENGTH] = { NL } ;
     char responseHeader[DOUBLE_LENGTH] = { NL } ;
     char contentLength[SHORT_LENGTH] = { NL } ;
     char contentType[SHORT_LENGTH] = { NL } ;
     char property[READ_BUFSIZE] ;
     char str[READ_BUFSIZE] ;
     char* p ;

     socketRead = socket( AF_INET, SOCK_STREAM, 0 ) ;

     if( socketRead < 0 ){
          fprintf( stderr, "Error: Cannot create socketRead.\n" ) ;
          return ;
     }

     addr.sin_family = AF_INET ;
     addr.sin_port = htons( 8080 ) ;
     addr.sin_addr.s_addr = INADDR_ANY ;

     result = bind( socketRead, ( struct sockaddr* )&addr, sizeof( addr ) ) ;

     if( result < 0 ){
          fprintf( stderr, "Error: Cannot bind.\n" ) ;
          return ;
     }

     listen( socketRead, 5 ) ;
     while( TRUE ){
          len = sizeof( client ) ;
          memset( &client, 0, len ) ;
          memset( buf, NL, sizeof( buf ) ) ;
          memset( method, NL, sizeof( method ) ) ;
          memset( url, NL, sizeof( url ) ) ;
          memset( protocol, NL, sizeof( protocol ) ) ;
          socketWrite = accept( socketRead, ( struct sockaddr* )&client, &len ) ;
          printf( "accept\n" ) ;

          result = recv( socketWrite, buf, sizeof( buf ), 0 ) ;
          if( result < 0 ){
               fprintf( stderr, "Error\n" ) ;
               return ;
          }
          sscanf( buf, "%s %s %s", method, url, protocol ) ;
          printf( "%s\n", url ) ;

          sprintf( fileName, GRACE_PROPERTY, url ) ;
          fp = fopen( fileName, "r" ) ;
          if( fp == NULL ){
               return ;
          }
          fgets( property, READ_BUFSIZE, fp ) ;
          sprintf( contentLength, "Content-Length: %s", property ) ;
          fgets( property, READ_BUFSIZE, fp ) ;
          sprintf( contentType, "Content-Type: text/%s", property ) ;
          sprintf( responseHeader,
                    "%s\r\n%s%s\r\n\r\n",
                    "HTTP/1.1 200 OK",
                    contentLength,
                    contentType
                    ) ;
          size = strlen( responseHeader ) ;
          send( socketWrite, responseHeader, size, 0 ) ;
          printf( "[ Size ]\n%d\n[ Header ]\n%s", size, responseHeader ) ;
          fclose( fp ) ;

          sprintf( fileName, GRACE_PATH, url ) ;
          fp = fopen( fileName, "r" ) ;
          if( fp == NULL ){
               return ;
          }
          printf( "[ Body ]\n" ) ;
          p = fgets( str, READ_BUFSIZE, fp ) ;
          while( p != NULL ){
               size = strlen( str ) ;
               send( socketWrite, str, size + 1, 0 ) ;
               printf( "%s", str ) ;
               p = fgets( str, READ_BUFSIZE, fp) ;
          }
          fclose( fp ) ;

          close( socketWrite ) ;
     }
     close( socketRead ) ;

     return ;
}

//------------------------
// :[ NAME ]:
//     fnDeploy
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnDeploy( string fileName ){
     FILE* sfp ;
     FILE* dfp ;
     char str[READ_BUFSIZE] ;
     char* p ;
     char fileNameOmitExtension[HALF_LENGTH] = { NL } ;
     char graceFileName[MAX_LENGTH] = { NL } ;
     char gracePropertyFileName[MAX_LENGTH] = { NL } ;
     int len ;
     int line ;
     char contentLength[MIN_LENGTH] = { NL } ;
	char s[HALF_LENGTH] = { NL } ;

     sfnSplitFileName( fileName ) ;
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
     p = fgets( str, READ_BUFSIZE, sfp ) ;
     while( p != NULL ){
          line++ ;
		sfnGenerateHTML( s, str ) ;
		if( s[0] == NL ){
			fprintf( stderr, "Error: Cannot generated.\n" ) ;
			break ;
		}
          len += strlen( s ) ;
          fputs( s, dfp ) ;
          p = fgets( str, READ_BUFSIZE, sfp ) ;
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
void _fnSetValue( string key, string value ){

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
			t  = tmp ;
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
	string result ;

	result = NULL ;

	i = 0 ;
	while( MyData.key[i][0] != NL ){
		if( strcmp( MyData.key[i], key ) == 0 ){
			result = MyData.value[i] ;
		}
		i++ ;
	}

	return result ;
}
