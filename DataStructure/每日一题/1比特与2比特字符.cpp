/*
有两种特殊字符：

第一种字符可以用一个比特 0 来表示
第二种字符可以用两个比特(10 或 11)来表示、
给定一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一位字符，则返回 true 。
*/

/*
遇到1开始跳两个，遇到0开始跳一个，最后pos==n-1时就是0可以单独结尾
*/

bool isOneBitCharacter(vector<int>& bits) {
    int len = bits.size();
    int pos = 0;
    while(pos<len-1){
        pos += bits[pos]+1;
    }
    return pos==len-1 ? true : false;
}