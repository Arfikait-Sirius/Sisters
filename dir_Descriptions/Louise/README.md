# Louiseの呼び方

*callSisters*を以下のように記載すれば呼び出せますよ！
```
void callSisters( void ){

     Louise = callLouise() ;

     return ;
}
```

# Louiseができること
## fnCopy()
```
string s = Louise.fnCopy(
     str,
     mode
) ;
```
文字列 str をコピーできます！  
mode には以下を指定することができます！
     * FIX
          * 以降の処理でも書き換えられなくなります
          * 半永続的な文字列の管理はこちらのモードが便利です
     * TMP
          * 以降の処理で再度 Louise.fnCopy() が呼び出される度に上書きされます
          * 一時的／局所的な文字列の利用はこちらのモードが便利です

## fnReplace()
```
string s = Louise.fnReplace(
     baseString,
     replaceTarget,
     replaceString
) ;
```
文字列 baseString に含まれる文字列 replaceTarget を、文字列 replaceString に置き換えた文字列を得られます！  
文字列 baseString は書き変わりません！

## fnUpperAll()
```
string s = Louise.fnUpperAll(
     str
) ;
```
文字列 str をすべて大文字にできます！  
文字列 str は書き変わりません！

## fnUpperFirst()
```
string s = Louise.fnUpperFirst(
     str
) ;
```
文字列 str の最初の文字を大文字に、以降の文字をすべて小文字にできます！  
文字列 str は書き変わりません！

## fnGetMiddle()
```
string s = Louise.fnGetMiddle(
     baseString,
     format
) ;
```
文字列 baseString から、形式文字列 format の %s に該当する最初の位置にある文字列を得られます！
