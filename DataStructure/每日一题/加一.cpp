/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

vector<int> plusOne(vector<int>& digits) {
    int back = digits.back()+1;
    if(back==10){
        for(int i=digits.size()-1; i>=0; --i){
            if(digits[i]==9) {
                digits[i] = 0;
                if(i==0){
                    vector<int>ans(digits.size()+1, 0);
                    ans[0] = 1;
                    return ans;
                }
            }
            else{
                ++digits[i];
                break;
            }
        }
    }else{
        ++digits.back();
    }
    return digits;
}