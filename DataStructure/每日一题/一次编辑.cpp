/*
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。
*/
bool oneEditAway(string first, string second) {
    int m = first.size(), n = second.size();
    if(m<n) {
        swap(first, second);
        swap(m,n);
    }
    if(m>n+1) return false;
    else if(m==n+1){ // 删除
        for(int i=0; i<n; ++i){
            if(first[i]!=second[i]){
                if(first.substr(0,i)+first.substr(i+1)==second) return true;
                else return false;
            }
        }
        return true;
    }else if(m==n){ // 替换
        for(int i=0; i<m; ++i){
            if(first[i]!=second[i])
            if(first.substr(0,i)+second[i]+first.substr(i+1)==second)
                return true;
            else return false;
        }
    }
    return first==second;
}