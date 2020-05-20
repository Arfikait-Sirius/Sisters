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
//     fnCountString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnCountString( string data, string sepStr ){
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
//     fnCopyString
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnCopyString( string data, int mode ){
	int counter = MyData.cpyCounter ;
	int i ;
	bool result = TRUE ;

	switch( mode ) {
	case TMP:
		counter = 0 ;
		break ;
	case FIX:
		MyData.cpyCounter++ ;
		for( i = 0 ; i < MAX_CPY_SIZE ; i++ ){
			if( strcmp( data, MyData.cpyStr[i] ) == 0 ){
				result = FALSE ;
				break ;
			}
		}
		break ;
	}
	if( result ){
		strcpy( MyData.cpyStr[counter], data ) ;
	}

	return MyData.cpyStr[counter] ;
}

//------------------------
// :[ NAME ]:
//     fnGetMiddle
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnGetMiddle( string format, string data ){
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
//     fnTrimWhiteSpace
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnTrimWhiteSpace( string target ){
	char str[MAX_LENGTH] ;
	char* p ;

	p = target ;
	while( *p == SPACE || *p == TAB ){
		p++ ;
	}
	strcpy( str, p ) ;
	p = str + strlen( p ) ;
	while( *p == SPACE || *p == TAB ){
		p-- ;
	}
	*p = NL ;
	strcpy( MyData.trmStr, str ) ;

	return MyData.trmStr ;
}

//------------------------
// :[ NAME ]:
//     fnReplace
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnReplace( string data, string repTarget, string repData ){
	int len ;
	char* p ;
	char* e ;
	char s[MAX_LENGTH] ;

	len = strlen( repTarget ) ;
	strcpy( s, data ) ;
	p = strstr( s, repTarget ) ;
	*p = NL ;
	e = p + len ;
	sprintf( MyData.repStr, "%s%s%s", s, repData, e ) ;

	return MyData.repStr ;
}

//------------------------
// :[ NAME ]:
//     fnUpperAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnUpperAll( string data ){
	char c ;
	char* result ;

	result = MyData.resStr ;
	c = *data++ ;
	while( c != NL ){
		if( 0x61 <= c && c <= 0x7a ){
			c -= 0x20 ;
		}
		*result++ = c ;
		c = *data++ ;
	}

	return MyData.resStr ;
}

//------------------------
// :[ NAME ]:
//     fnLowerAll
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnLowerAll( string data ){
	char c ;
	string result ;

	result = MyData.resStr ;
	c = *data++ ;
	while( c != NL ){
		if( 0x41 <= c && c <= 0x5a ){
			c += 0x20 ;
		}
		*result++ = c ;
		c = *data++ ;
	}
	*result = NL ;

	return MyData.resStr ;
}

//------------------------
// :[ NAME ]:
//     fnUpperFirst
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnUpperFirst( string data ){
	char c ;
	char* result ;

	result = MyData.resStr ;
	c = *data++ ;
	if( 0x61 <= c && c <= 0x7a ){
		c -= 0x20 ;
	}
	*result++ = c ;
	c = *data++ ;
	while( c != NL ){
		if( 0x41 <= c && c <= 0x5a ){
			c += 0x20 ;
		}
		*result++ = c ;
		c = *data++ ;
	}
	*result = NL ;

	return MyData.resStr ;
}

//------------------------
// :[ NAME ]:
//     fnNumToStr
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnNumToStr( int num ){
	int n ;
	char result[HALF_LENGTH] ;
	char tmp[HALF_LENGTH] ;
 	char* p ;
	char* q ;

	if( num == 0 ){
		MyData.numStr[0] = CHAR_0 ;
		MyData.numStr[1] = NL ;
		return MyData.numStr ;
	}

	p = tmp ;
	*p++ = NL ;
	while( num != 0 ){
		n = num % 10 ;
		*p++ = n + CHAR_0 ;
		num = ( num - n ) / 10 ;
	}

	p-- ;
	q = result ;
	while( *p != NL ) {
		*q++ = *p-- ;
	}
	*q = NL ;

	strcpy( MyData.numStr, result ) ;

	return MyData.numStr ;
}

//------------------------
// :[ NAME ]:
//     fnGetLength
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnGetLength( string data ){
	int len = 0 ;

	if( data != NULL ){
		len = strlen( data ) ;
	}

	return len ;
}

//------------------------
// :[ NAME ]:
//     isMatchFormat
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isMatchFormat( string format, string data ){
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
			return FALSE ;
		}
		pos = len ;
		p = strstr( strFormat, "%s" ) ;
	}
	strcpy( tmpStr, strFormat ) ;
	p = strstr( ( data + pos ), tmpStr ) ;
	if( p == NULL ){
		return FALSE ;
	}

	return TRUE ;
}

//------------------------
// :[ NAME ]:
//     isContain
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isContain( string data, string target ){
	char* p ;

	p = strstr( data, target ) ;
	if( p == NULL ){
		return FALSE ;
	}

	return TRUE ;
}

//------------------------
// :[ NAME ]:
//     isEqualStr
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isEqualStr( string org, string target ){

	if( strcmp( org, target ) == 0 ){
		return TRUE ;
	}

	return FALSE ;
}

//------------------------
// :[ NAME ]:
//     isEmpty
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isEmpty( string data ){

	if( data == NULL ){
		return TRUE ;
	}
	if( *data == NL ){
		return TRUE ;
	}

	return FALSE ;
}
