/*
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
*/

 bool isAlienSorted(vector<string>& words, string order) {
    int chs[26] = {0};
    for(int i=0; i<26; ++i){
        chs[order[i]-'a'] =i;
    }
    string pre;
    for(int i=0; i<words.size(); ++i){
        if(i==0) pre = words[0];
        else{
            string cur = words[i];
            int k = 0;
            int m = pre.size(), n = cur.size();
            while(k<m||k<n){
                if(chs[pre[k]-'a']>chs[cur[k]-'a']){
                    return 0;
                }
                else if(chs[pre[k]-'a']<chs[cur[k]-'a']){
                    break;
                }else{
                    ++k;
                    if(k==n&&m>n) return 0;
                    if(k>=m||k>=n) break;
                }
            }
            pre = cur;
        }
    }
    return 1;
}