/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
    它们的乘积也表示为字符串形式。

注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
*/
#include<vector>
#include<iostream>
using namespace std;


string multiply(string num1, string num2) {
    if(num1=="0"||num2=="0") return "0";
    int m = num1.size(), n = num2.size();
    // 后面是低位
    vector<int> res(m+n);
    for(int i=m-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            int mut = (num1[i] - '0')*(num2[j] - '0');
            int p1 = j+i, p2 = j+i+1;
            int sum = res[p2] + mut;
            res[p2] = sum%10;
            res[p1] += sum/10;
        }
    }
    int i=0;
    while(i<m+n && res[i]==0) i++;
    string ans;
    for(i; i<m+n; i++){
        ans += '0' + res[i];
    }
    return ans;
}




int main(int argc, char const *argv[])
{
    
    return 0;
}
