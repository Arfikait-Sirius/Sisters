# Dorothyの呼び方

*callSisters*を以下のように記載すれば呼び出せますよ！
```
void callSisters( void ){

     Dorothy = callDorothy() ;

     return ;
}
```

# Dorothyができること
## fnOpenRead()
```
file fileID = Dorothy.fnOpenRead(
     fileName
) ;
```
指定した名前のファイルを読み取り専用で開けます！
fileID が返却されるので、後続の処理でファイル操作を行うときは  
この ID を引数に渡してあげてくださいね！
