/*
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
*/
/*
位运算实现加法
二进制位异或运算相当于对应位相加，不考虑进位
比如： 1 ^ 1 = 0 —> 1 + 1 = 0 (当前位值为0，进一位)
1 ^ 0 = 1 —> 1 + 0 = 1 (当前位值为1)
0 ^ 0 = 0 —> 0 + 0 = 0 (当前位值为0)

二进制位与运算相当于对应位相加之后的进位
比如： 1 & 1 = 1 —> 1 + 1 = 0 (当前位的值进一位)
1 & 0 = 0 —> 1 + 0 = 1 (当前位的值不进位)
0 & 0 = 0 —> 0 + 0 = 0 (当前位的值不进位)

两个数相加：对应二进制位相加的结果 + 进位的结果
比如：3 + 2 --> 0011 + 0010 --> 0011 ^ 0010 + ((0011 & 0010) << 1)
—> (0011 ^ 0010) ^ ((0011 & 0010) << 1)， 当进位之后的结果为0时，相加结束

*/
int getSum(int a, int b) {
    while(b){
        unsigned int sum = a^b;
        unsigned int carry = static_cast<unsigned int>(a&b)<<1;
        a = sum;
        b = carry;
    }
    return a;
}

