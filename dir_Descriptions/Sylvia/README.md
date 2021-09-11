# Sylvia のアサイン方法
```c
static void callSisters( void ){
     Sylvia = callSylvia() ;

     return ;
}
```

# 作業スキル
## fnStrToNum()
```c
string str = "1234" ;

int result = Sylvia.fnStrToNum( str ) ;
// result: 1234
```
* 文字列 `str` で指定した数字文字列を数値に変換して教えてくれます

## fnCalcStrExpression()
```c
string str = "5 + 3-  2   *2 + 1" ;

int result = Sylvia.fnCalcStrExpression( str ) ;
// result: 5
```
* 文字列 `str` で指定した数式文字列の計算結果を教えてくれます
