/*
给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。

UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：

对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
这是 UTF-8 编码的工作方式：

*/

#include<vector>
#include<iostream>

using namespace std;

int checkFrontOne(int num){
    int mask = 1 << 7;
    int n_bytes = 0;
    while(mask&num){
        n_bytes ++;
        mask = mask >> 1;
    }
    return n_bytes;
}
bool isOneZero(int num){
    int mask1 = 1 << 7;
    int mask2 = 1 << 6;
    if(num&mask1&&!(num&mask2)){
        return true;
    }
    return false;
}

bool validUtf8(vector<int>& data) {
    int len = data.size();
    int i=0;
    while(i<len){
        int numsOne = checkFrontOne(data[i]);
        if(numsOne>4){return false;}
        if(numsOne==0){
            ++i;
            continue;
        }
        else if(numsOne==1){
            return false;
        }
        else{
            for(int k = 1; k < numsOne; ++k){
                if(i+k >= len||!isOneZero(data[i+k])){
                    return false;
                }
            }
            i += numsOne;
        }
    }
    return true;
}