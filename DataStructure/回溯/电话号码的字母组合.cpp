/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

*/

vector<string> ans;
void dfs(string digits, vector<string>&mp, string&path, int n, int idx){
    if(n==idx){
        ans.push_back(path);
        return;
    }
    string s = mp[digits[idx]-'0'-2];
    for(int i=0; i<s.size(); i++){
        path += s[i];
        dfs(digits, mp, path, n, idx+1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string>mp={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int n = digits.size();
    if(n==0) return {};
    string path;
    dfs(digits, mp, path, n, 0);
    return ans;
}