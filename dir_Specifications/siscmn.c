#include "siscmn.h"

void logSisters( string freeStr, int status, string name ){
	char message[MAX_LENGTH] = { NL } ;

	sprintf(
			message,
			"[%10s][%7s]: %s\n",
			name,
			statusLabel[status],
			freeStr
		) ;
	if( IS_LOG_FILE ){
		sfnWriteLog( LOG_FILE, message ) ;
		switch ( status ) {
		case ATTEND:
			sfnWriteLog( ATTENDANCE_FILE, message ) ;
			break ;
		case INFO:
			sfnWriteLog( INFO_FILE, message ) ;
			break ;
		case ERROR:
			sfnWriteLog( ERROR_FILE, message ) ;
			break ;
		case FATAL:
			sfnWriteLog( FATAL_FILE, message ) ;
			break ;
		}
	}else{
		fputs( message, stdout ) ;
	}

	return ;
}

static void sfnWriteLog( string logFileName, string msg ){
	FILE* fp ;

	fp = fopen( logFileName, APPEND_ONLY ) ;
	if( fp == NULL ){
		return ;
	}
	fputs( msg, fp ) ;
	fclose( fp ) ;

	return ;
}
