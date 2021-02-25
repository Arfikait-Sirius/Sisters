# How to call Dorothy
```c
static void callSisters( void ){
     Dorothy = callDorothy() ;

     return ;
}
```

# Skills
**./path/file.txt**
```
This is text file.
Number of lines is 2.
```

## fnOpen()
```c
string fileName = "./path/file.txt" ;

file fileID = Dorothy.fnOpenRead( fileName ) ;
// Open the file and return the id for access.
```

## fnClose()
```c
// After opening file and the file id is "fileID".

Dorothy.fnClose( fileID ) ;
// Close the file.
```

## fnReadLine()
```c
// After opening file and the file id is "fileID".

string result1 = Dorothy.fnReadLine( fileID ) ;
// result1( The first time ): "This is text file."

string result2 = Dorothy.fnReadLine( fileID ) ;
// result2( The Second time ): "Number of lines is 2."
```

## fnWriteLine()
```c
// After opening file and the file id is "fileID".

string line = "This is new line." ;

Dorothy.fnWriteLine( fileID, line ) ;
// Write "This is new line." to the file.
```

## fnRename()
```c
// After opening file and the file id is "fileID".

string newFileName = "NewFile" ;

Dorothy.fnRename( fileID, newFileName ) ;
// Rename the file to "NewFile".
```

## fnDelete()
```c
string fileName = "./path/file.txt" ;

Dorothy.fnDelete( fileName ) ;
// Delete the file.
```

## fnCopy()
```c
string destFileName = "./path/file_copy.txt" ;
string srcFileName = "./path/file.txt" ;

Dorothy.fnCopy( destFileName, srcFileName ) ;
// Copy file "./path/file.txt" to file "./path/file_copy.txt".
```

# Judges
## isNotEnd()
```c
// After opening file and the file id is "fileID".

bool result = Dorothy.isNotEnd( fileID ) ;
// Judge if exist unread lines.( Exist: true )
```

## isError()
```c
// After opening file and the file id is "fileID".
// Or after failed to open file.

bool result = Dorothy.isError( fileID ) ;
// Judge if exist any errors.( Exist: true )
```
