/*
单调栈用途不太广泛，只处理一种典型的问题，叫做 Next Greater Element。

如何维护单调栈

    以维护一个单调递增栈为例。
当插入一个新元素时，为了维护栈内的单调性，我们将该元素与栈顶元素进行比较，若不满足单调性，就将栈顶元素弹出，
    不断重复，直到栈空或者满足单调性为止，最后再将该元素塞入栈顶。

    for(int i=1;i<=n;i++)
    {
        while(!sta.empty()&&sta.top()>=a[i]) sta.pop();
        sta.push(a[i]);
    }//c++ stl版
当然，实际上我们更常用的是用单调栈保存元素的下标，而非其值——————
    for(int i=1;i<=n;i++)
    {
        while(!sta.empty()&&a[sta.top()]>=a[i]) sta.pop();
        sta.push(i);
    }//c++ stl版    

求解的问题	   遍历方向	   维护单调性（栈底->栈顶）
左侧第一个更大	从右到左	单调递减
左侧第一个更小	从右到左	单调递增
右侧第一个更大	从左到右	单调递减
右侧第一个更小	从左到右	单调递增

拓展内容：如何寻找左侧第二个比当前元素大的元素位置？
其题目大意是这样：一列人在排队，身高有高有矮，每个人可以插队无限次比自己矮的人，
    仅可以插队一次比自己高的人，问如果只有一个人插队，这个人最多能排到多前面？
*/

#include<iostream>
#include<vector>
#include<stack>

#define ll long long
#define pb push_back
#define sz size()
#define pii pair<int,long long>
#define mkp make_pair
using namespace std;

const int N=1e6+10;

stack<int>st1,st2,st3;

int a[N], ans[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!st2.empty()&&a[st2.top()]<a[i])
        {
            ans[st2.top()]=i+1;
            st2.pop();
        }
        while(!st1.empty()&&a[st1.top()]<a[i])
        {
            st3.push(st1.top());
            st1.pop();
        }
        st1.push(i);
        while(!st3.empty()) st2.push(st3.top()),st3.pop();
    }
    while(!st1.empty()) ans[st1.top()]=1,st1.pop();
    while(!st2.empty()) ans[st2.top()]=1,st2.pop();
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    
    return 0;
}

