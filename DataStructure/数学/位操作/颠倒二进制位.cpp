/*
颠倒给定的 32 位无符号整数的二进制位。
*/
#include<iostream>
using namespace std;


uint32_t reverseBits(uint32_t n) {
    if(n==0){
        return n;
    }
    int i=0;
    uint32_t num = 0;
    while(n/2!=0){
        int mod = n%2;
        if(mod==1){
            num+=(1<<(31-i));
        }
        n /=2;
        i++;
    } 
    num+=(1<<(31-i));

    return num;
}


uint32_t reverseBits1(uint32_t n) {
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

    uint32_t a = ((n&m_5)<<16) + ((n>>16)&m_5);
    uint32_t b = ((a&m_4)<<8) + ((a>>8)&m_4);
    uint32_t c = ((b&m_3)<<4) + ((b>>4)&m_3);
    uint32_t d = ((c&m_2)<<2) + ((c>>2)&m_2);
    uint32_t f = ((d&m_1)<<1) + ((d>>1)&m_1);
    return f;
}

int main(int argc, char const *argv[])
{
    cout<<reverseBits(43261596)<<endl;
    cout<<reverseBits1(43261596);
    return 0;
}
