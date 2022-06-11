/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。
*/

bool backspaceCompare(string s, string t) {
    int sl = s.size()-1, tl = t.size()-1;
    int sskip=0, tskip=0;
    while(sl>=0||tl>=0){
        while(sl>=0){
            if(s[sl]=='#'){
                sskip++, sl--;
            }else if(sskip>0){
                sskip--, sl--;
            }else{
                break;
            }
        }
        while(tl>=0){
            if(t[tl]=='#'){
                tskip++, tl--;
            }else if(tskip>0){
                tskip--, tl--;
            }else{
                break;
            }
        }
        if(sl>=0&&tl>=0){
            if(s[sl]!=t[tl]) return 0;
        }else{
            if(sl>=0||tl>=0) return 0;
        }
        sl--, tl--;
    }
    return 1;
}