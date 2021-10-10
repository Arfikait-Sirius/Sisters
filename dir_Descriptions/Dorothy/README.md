# Dorothy のアサイン方法
```c
static void callSisters( void ){
     Dorothy = callDorothy() ;

     return ;
}
```

# 作業スキル
例えばこんなファイルがあったとしたら......  
**./path/file.txt**
```
This is text file.
Number of lines is 2.
```

## fnOpen()
```c
string fileName = "./path/file.txt" ;

file fileID = Dorothy.fnOpen( fileName ) ;
```
* 文字列 `filename` で指定したファイルを開いて準備してくれます
* 以降そのファイルにアクセスするためのファイル ID を教えてくれます

## fnClose()
```c
Dorothy.fnClose( fileID ) ;
```
* ファイル ID で指定したファイルを閉じてくれます

## fnReadLine()
```c
string result1 = Dorothy.fnReadLine( fileID ) ;
// result1: "This is text file."

string result2 = Dorothy.fnReadLine( fileID ) ;
// result2: "Number of lines is 2."
```
* ファイルのテキストを行単位で読み出して教えてくれます
* 副作用のあるスキルです
  * 呼び出す度に読み出す行が進みます

## fnWriteLine()
```c
string line = "This is new line." ;

Dorothy.fnWriteLine( fileID, line ) ;
```
* ファイルにテキストを行単位で書き出してくれます

## fnRename()
```c
string newFilename = "NewFile" ;

Dorothy.fnRename( fileID, newFilename ) ;
```
* ファイル ID で指定したファイルのファイル名を文字列 `newFilename` に変更してくれます

## fnDelete()
```c
string fileName = "./path/file.txt" ;

Dorothy.fnDelete( fileName ) ;
```
* 文字列 `filename` で指定したファイルを削除してくれます

## fnCopy()
```c
string destFilename = "./path/file_copy.txt" ;
string srcFilename = "./path/file.txt" ;

Dorothy.fnCopy( destFilename, srcFilename ) ;
```
* 文字列 `srcFilename` で指定したファイルを文字列 `destFilename` で指定するファイルにコピーしてくれます

# 判定スキル
## isNotEnd()
```c
bool result = Dorothy.isNotEnd( fileID ) ;
// Judge if exist unread lines.( Exist: true )
```
* まだ読み出していない行があるかどうかを教えてくれます

## isError()
```c
bool result = Dorothy.isError( fileID ) ;
// Judge if exist any errors.( Exist: true )
```
* ファイル処理でエラーが発生しているかどうかを教えてくれます
