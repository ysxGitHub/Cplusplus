/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），
返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
*/
#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    if(n==0){
        return 0;
    }
    int count = 0;
    while(n/2!=0){
        int mod=n%2;
        if(mod==1){
            count++;
        }
        n /=2;
    }    
    return count+1;
}

int hammingWeight1(uint32_t n) {

    int count = 0;
    while (n>0){
        if((n&1)==1){
            count++;
        }
        n = (n>>1);
    }
    return count;
}


int hammingWeight2(uint32_t n) {
    // 0101 0101 0101 0101 0101 0101 0101 0101
    uint32_t m_1 = 0x55555555; 
    // 0011 0011 0011 0011 0011 0011 0011 0011
    uint32_t m_2 = 0x33333333; 
    // 0000 1111 0000 1111 0000 1111 0000 1111
    uint32_t m_3 = 0x0f0f0f0f;
    // 0000 0000 1111 1111 0000 0000 1111 1111
    uint32_t m_4 = 0x00ff00ff;
    // 0000 0000 0000 0000 1111 1111 1111 1111
    uint32_t m_5 = 0x0000ffff;

    int a = (m_1&n) + (m_1&(n>>1));
    int b = (m_2&a) + (m_2&(a>>2));
    int c = (m_3&b) + (m_3&(b>>4));
    int d = (m_4&c) + (m_4&(c>>8));
    int f = (m_5&d) + (m_5&(d>>16));
    return f;
}

int main(int argc, char const *argv[])
{
    cout<<hammingWeight2(1)<<endl;
    return 0;
}

