/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

*/
#include<iostream>  
#include<algorithm>
using namespace std;

int atoi(char a){
    return a - '0';
}

string addStrings(string num1, string num2) {
    int n1 = num1.size()-1, n2 = num2.size()-1;
    string ans;
    bool flag=0;
    while(n1>=0||n2>=0){
        int tmp;
        if(n2==-1){
            tmp = atoi(num1[n1]);
            if(flag){
                tmp += 1;
            }
            ans += to_string(tmp%10);
            --n1;
        }
        else if(n1==-1){
            tmp = atoi(num2[n2]);
            if(flag){
                tmp += 1;
            }
            ans += to_string(tmp%10);
            --n2;
        }
        else{
            tmp = atoi(num1[n1])+atoi(num2[n2]);
            if(flag){
                tmp += 1;
            }
            ans += to_string(tmp%10);
            --n1, --n2;
        }

        if(tmp>=10){
            flag=1;
        }else{
            flag=0;
        }
    }
    if(flag){ans+='1'; }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    cout<<addStrings("123", "11");
    return 0;
}
