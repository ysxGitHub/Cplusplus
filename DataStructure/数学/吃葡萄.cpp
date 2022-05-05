/*

有三种葡萄，每种分别有\mathit a,b,ca,b,c颗。有三个人，第一个人只吃第1,2种葡萄，
    第二个人只吃第2,3种葡萄，第三个人只吃第1,3种葡萄。
适当安排三个人使得吃完所有的葡萄,并且且三个人中吃的最多的那个人吃得尽量少。
*/

#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;

using namespace std;


/*
PS：向上取整是一个常用的算法技巧。大部分编程语言中，如果你想计算 M 除以 N，M / N 会向下取整，
    你想向上取整的话，可以改成 (M+(N-1)) / N


思想: 可以看成是三个人分别站在三角形的顶点（假定可以形成三角形）。设三角形两个短边是a,b，长边是c。则，
    若两短边之和大于等于长边的一半，可实现总数平分；反之，则结果为长边的一半。
*/
int main(){
    int many = 0;
    cin>>many;
    for(int i=0; i<many; i++){
        ll num = 0;
        vector<ll>nums;
        while(cin>>num){
            nums.emplace_back(num);
            if('\n'==cin.get()) break;
        }

        ll sum = nums[0]+nums[1]+nums[2];
        ll maxn = max(nums[0],max(nums[1],nums[2]));
        ll ans = -1;

        if(sum-maxn>=maxn/2){
            ans = (sum+2)/3;
        }else{
            ans = (maxn+1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}

