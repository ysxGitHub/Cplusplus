/*
这里将 dir 作为根目录中的唯一目录。dir 包含两个子目录 subdir1 和 subdir2 。
    subdir1 包含文件 file1.ext 和子目录 subsubdir1；subdir2 包含子目录 subsubdir2，
    该子目录下包含文件 file2.ext 。
*/

#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int lengthLongestPath(string input) {
    unordered_map<int, string> mp;
    int n = input.size();
    string ans="";
    for(int i=0; i<n; ){
        int level = 0;
        // 记录目录层数
        while(i<n&&input[i]=='\t'&&++level>=0) i++;
        int j = i;
        bool isDir = true;
        // 检查该层是否为文件名
        while(j<n&&input[j]!='\n'){
            if(input[j++]=='.') isDir=false;
        }
        // 得到该层的名字
        string cur = input.substr(i, j-i);
        // 拼接路径
        string path = mp.count(level-1) ? mp[level-1] + "/" + cur : cur;
        // 该层为目录时 存储该层路径
        if(isDir) mp[level] = path;
        // 否则比较路径长度
        else if(ans == ""||path.size()>ans.size()) ans = path;
        i = j+1;
    }
    return ans == "" ? 0 : ans.size();
}


int main(int argc, char const *argv[])
{
    string s = "dir\n\t        file.txt\n\tfile2.txt";
    lengthLongestPath(s);
    return 0;
}
