/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。
*/

string ans;
for(int i=0; i<201; ++i){
    char tmp;
    for(int j=0; j<strs.size(); ++j){
        if(j==0&&strs[j].size()>=i+1) tmp = strs[j][i];
        else{
            if(tmp!=strs[j][i]) return ans;
        }
    }
    ans+=tmp;
}
return ans;