#include "Dorothy.h"

// Dorothy's Memo
static _MyDataDorothy MyData = INIT_DOROTHY_MYDATA ;

// Birth
DorothyFunctions callDorothy( void ){
	DorothyFunctions _DorothySkills = BIRTH_DOROTHY ;

	return _DorothySkills ;
}

//------------------------
// :[ NAME ]:
//     fnOpenRead
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnOpenRead( string fileName ){

	MyData.error[MyData.fileSeq] = FALSE ;

	MyData.fp[MyData.fileSeq] = fopen( fileName, "r" ) ;
	if( MyData.fp[MyData.fileSeq] == NULL ){
		MyData.error[MyData.fileSeq] = TRUE ;
		logSisters(
				"Failed to open file.",
				FATAL,
				Dorothy_ID
			) ;
		return CHAO ;
	}
	MyData.path[MyData.fileSeq] = sfnExtractFilePath( fileName ) ;
	strcpy( MyData.fname[MyData.fileSeq], fileName ) ;
	MyData.stat[MyData.fileSeq] = FILE_STAT_BEGINNING ;

	return MyData.fileSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnOpenWrite
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnOpenWrite( string fileName ){

	MyData.error[MyData.fileSeq] = FALSE ;

	MyData.fp[MyData.fileSeq] = fopen( fileName, "w" ) ;
	if( MyData.fp[MyData.fileSeq] == NULL ){
		MyData.error[MyData.fileSeq] = TRUE ;
		logSisters(
				"Failed to open file.",
				FATAL,
				Dorothy_ID
			) ;
		return CHAO ;
	}
	MyData.path[MyData.fileSeq] = sfnExtractFilePath( fileName ) ;
	strcpy( MyData.fname[MyData.fileSeq], fileName ) ;
	MyData.stat[MyData.fileSeq] = FILE_STAT_BEGINNING ;

	return MyData.fileSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnCloseFile
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnCloseFile( int fileID ){

	fclose( MyData.fp[fileID] ) ;
	MyData.stat[fileID] = FILE_STAT_END ;

	return ;
}

//------------------------
// :[ NAME ]:
//     fnReadLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
string _fnReadLine( int fileID ){
	char c ;
	string src ;
	int count ;
	char errMsg[HALF_LENGTH] = { NL } ;

	if( MyData.stat[fileID] == FILE_STAT_END ){
		return NULL ;
	}

	c = fgetc( MyData.fp[fileID] ) ;
	if( c == EOF ){
		MyData.stat[fileID] = FILE_STAT_END ;
		return NULL ;
	}
	for( src = MyData.readStr[fileID], count = 0 ;
			c != LF && c != EOF && count < READ_BUFSIZE ;
			count++
			){
		*src++ = c ;
		c = fgetc( MyData.fp[fileID] ) ;
	}
	*src = 0x00 ;
	MyData.stat[fileID] = FILE_STAT_READING ;

	return MyData.readStr[fileID] ;
}

//------------------------
// :[ NAME ]:
//     fnWriteLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnWriteLine( int fileID, string srcData ){

	strcat( srcData, "\n" ) ;
	fputs( srcData, MyData.fp[fileID] ) ;

	return ;
}

//------------------------
// :[ NAME ]:
//     fnRenameFile
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnRenameFile( int fileID, string newName ){
	char name[MAX_LENGTH] ;

	sprintf( name, "%s%s", MyData.path[fileID], newName ) ;
	rename( MyData.fname[fileID], name ) ;

	return ;
}

//------------------------
// :[ NAME ]:
//     fnDelete
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnDelete( string fileName ){
	int result = 0 ;

	result = remove( fileName ) ;
	if( result != 0 ){
		MyData.error[MyData.fileSeq] = TRUE ;
	}

	return MyData.fileSeq ;
}

//------------------------
// :[ NAME ]:
//     fnOpenParse
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnOpenParse( string fileName ){
	FILE* fp ;
	int len ;
	int line ;
	char buf[READ_BUFSIZE] = { NL } ;
	char* p ;

	fp = fopen( fileName, READ_ONLY ) ;
	if( fp == NULL ){
		return TOO_BAD ;
	}
	len = 0 ;
	line = 0 ;
	p = fgets( buf, READ_BUFSIZE, fp ) ;
	while( p != NULL ){
		line++ ;
		len += strlen( buf ) ;
		p = fgets( buf, READ_BUFSIZE, fp ) ;
	}
	fclose( fp ) ;
	MyData.parseLine[MyData.parseSeq] = line ;
	MyData.parseLen[MyData.parseSeq] = len ;
	MyData.parseStat[MyData.parseSeq] = FILE_PARSE_START ;

	return MyData.parseSeq++ ;
}

//------------------------
// :[ NAME ]:
//     fnCloseParse
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnCloseParse( int prsfID ){

	MyData.parseStat[prsfID] = FILE_PARSE_END ;

	return ;
}

//------------------------
// :[ NAME ]:
//     fnGetFileLength
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnGetFileLength( int prsfID ){

	if( MyData.parseStat[prsfID] == FILE_PARSE_END ){
		return TOO_BAD ;
	}

	return MyData.parseLen[prsfID] ;
}

//------------------------
// :[ NAME ]:
//     fnGetFileLine
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _fnGetFileLine( int prsfID ){

	if( MyData.parseStat[prsfID] == FILE_PARSE_END ){
		return TOO_BAD ;
	}

	return MyData.parseLine[prsfID] ;
}

//------------------------
// :[ NAME ]:
//     fnCopyFile
//
// :[ CATEGORY ]:
//     Skill
//------------------------
void _fnCopyFile( string dstFileName, string srcFileName ){
	FILE* sfp ;
	FILE* dfp ;
	char buf[READ_BUFSIZE] = { NL } ;
	char* p ;

	sfp = fopen( srcFileName, READ_ONLY ) ;
	if( sfp == NULL ){
		return ;
	}
	dfp = fopen( dstFileName, WRITE_ONLY ) ;
	p = fgets( buf, READ_BUFSIZE, sfp ) ;
	while( p != NULL ){
		fputs( buf, dfp ) ;
		p = fgets( buf, READ_BUFSIZE, sfp ) ;
	}
	fclose( dfp ) ;
	fclose( sfp ) ;

	return ;
}

//------------------------
// :[ NAME ]:
//     sfnExtractFilePath
//
// :[ CATEGORY ]:
//     Thinking
//------------------------
static string sfnExtractFilePath( string fileName ){
	char* p ;
	char s[MAX_LENGTH] ;
	char* buff ;

	p = fileName ;
	buff = s ;
	while( *p != NL ){
		*buff++ = *p ;
		if( *p == SLASH ){
			*buff = NL ;
			strcat( MyData.tmpPath[MyData.fileSeq], s ) ;
			buff = s ;
		}
		p++ ;
	}

	return MyData.tmpPath[MyData.fileSeq] ;
}

//------------------------
// :[ NAME ]:
//     isNotFileEnd
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isNotFileEnd( int fileID ){

	if( MyData.stat[fileID] == FILE_STAT_END ){
		return FALSE ;
	}

	return TRUE ;
}

//------------------------
// :[ NAME ]:
//     isExistError
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _isExistError( int fileID ){

	return MyData.error[fileID] ;
}
