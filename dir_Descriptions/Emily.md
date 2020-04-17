# Emilyの呼び方
*callSisters*を以下のように記載すれば呼び出せますよ！
```
void callSisters( void ){

     Emily = callEmily() ;

     return ;
}
```

# Emilyができること
## fnGetLine()
```
string s = Emily.fnGetLine() ;
```
コンソールから文字列を入力できます！  
エンターキー押下まで入力待ちになります！

## fnDispLine()
```
Emily.fnDispLine(
     "Hello!"
) ;
```
コンソールに「Hello!(改行あり)」を表示できます！

## fnDispLineCustom()
```
Emily.fnDispLineCustom(
     "Hello, ",
     "I'm ",
     "Emily!"
) ;
```
コンソールに「Hello, I'm Emily!(改行あり)」を表示できます！

## fnDispStr()
```
Emily.fnDispStr(
     "Hello!"
) ;
```
コンソールに「Hello!(改行なし)」を表示できます！

## fnDispStrCustom()
```
Emily.fnDispStrCustom(
     "Hello, ",
     "I'm ",
     "Emily!"
) ;
```
コンソールに「Hello, I'm Emily!(改行なし)」を表示できます！
