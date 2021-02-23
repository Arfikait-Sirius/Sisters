#include "Dorothy.h"

// Name
static string MyName = "Dorothy" ;

// Dorothy's Memo
static _MyDataDorothy MyData = INIT_DOROTHY_MYDATA ;

// Birth
DorothyFunctions callDorothy( void ){
     DorothyFunctions _DorothySkills = BIRTH_DOROTHY ;

     return _DorothySkills ;
}

//------------------------
// :[ NAME ]:
//     fnOpen
//
// :[ CATEGORY ]:
//     Skill
//------------------------
int _DorothyfnOpen( string fileName ){
     char filePath[MAX_LENGTH] ;

     MyData.error[MyData.fileSeq] = false ;

     sprintf( filePath, "../%s", fileName ) ;
     MyData.fp[MyData.fileSeq] = fopen( filePath, "r+" ) ;
     if( MyData.fp[MyData.fileSeq] == NULL ){
          MyData.error[MyData.fileSeq] = true ;
          logSisters(
                    "Failed to open file.",
                    FTL,
                    MyName
               ) ;
          return TOO_BAD ;
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
void _DorothyfnCloseFile( int fileID ){

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
string _DorothyfnReadLine( int fileID ){
     char c ;
     string src ;
     int count ;
     char errMsg[HALF_LENGTH] = { NL } ;

     if( MyData.stat[fileID] == FILE_STAT_END ){
          MyData.error[fileID] = true ;
          return NULL ;
     }

     c = fgetc( MyData.fp[fileID] ) ;
     if( c == EOF ){
          MyData.stat[fileID] = FILE_STAT_END ;
          return NULL ;
     }
     for( src = MyData.readStr[fileID], count = 0 ;
               c != LF && c != EOF && count < DOROTHY_READ_BUFSIZE ;
               count++ ){
          *src++ = c ;
          c = fgetc( MyData.fp[fileID] ) ;
     }
     *src = NL ;
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
void _DorothyfnWriteLine( int fileID, string srcData ){

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
void _DorothyfnRenameFile( int fileID, string newName ){
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
int _DorothyfnDelete( string fileName ){
     int result = 0 ;

     result = remove( fileName ) ;
     if( result != 0 ){
          MyData.error[MyData.fileSeq] = true ;
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
int _DorothyfnOpenParse( string fileName ){
     FILE* fp ;
     int len ;
     int line ;
     char buf[DOROTHY_READ_BUFSIZE] = { NL } ;
     char* p ;

     fp = fopen( fileName, "r" ) ;
     if( fp == NULL ){
          return TOO_BAD ;
     }
     len = 0 ;
     line = 0 ;
     p = fgets( buf, DOROTHY_READ_BUFSIZE, fp ) ;
     while( p != NULL ){
          line++ ;
          len += strlen( buf ) ;
          p = fgets( buf, DOROTHY_READ_BUFSIZE, fp ) ;
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
void _DorothyfnCloseParse( int prsfID ){

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
int _DorothyfnGetFileLength( int prsfID ){

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
int _DorothyfnGetFileLine( int prsfID ){

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
void _DorothyfnCopyFile( string dstFileName, string srcFileName ){
     FILE* sfp ;
     FILE* dfp ;
     char buf[DOROTHY_READ_BUFSIZE] = { NL } ;
     char* p ;

     sfp = fopen( srcFileName, "r" ) ;
     if( sfp == NULL ){
          return ;
     }
     dfp = fopen( dstFileName, "w" ) ;
     p = fgets( buf, DOROTHY_READ_BUFSIZE, sfp ) ;
     while( p != NULL ){
          fputs( buf, dfp ) ;
          p = fgets( buf, DOROTHY_READ_BUFSIZE, sfp ) ;
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
          return false ;
     }

     return true ;
}

//------------------------
// :[ NAME ]:
//     isExistError
//
// :[ CATEGORY ]:
//     Judge
//------------------------
bool _DorothyisError( int fileID ){

     return MyData.error[fileID] ;
}
