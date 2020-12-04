#include "siscmn.h"

void logSisters( string msg, int status, string name ){
     char message[MAX_LENGTH] = { NL } ;

     sprintf(
               message,
               "[%10s][%7s]: %s\n",
               name, statusLabel[status], msg
          ) ;
     if( IS_LOG_FILE ){
          sfnWriteLog( LOG_FILE, message ) ;
          switch ( status ) {
          case MSG:
               sfnWriteLog( MASSAGE_FILE, message ) ;
               break ;
          case INF:
               sfnWriteLog( INFO_FILE, message ) ;
               break ;
          case ERR:
               sfnWriteLog( ERROR_FILE, message ) ;
               break ;
          case FTL:
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

     fp = fopen( logFileName, "a" ) ;
     if( fp == NULL ){
          return ;
     }
     fputs( msg, fp ) ;
     fclose( fp ) ;

     return ;
}
