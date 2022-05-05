#include<iostream>
using namespace std;
#include<queue>

/*
queue不允许遍历
先进先出
队头出队
队尾进队
*/

int main(int argc, char const *argv[])
{
    queue<int>q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout<<"size: "<<q1.size()<<endl;
    cout<<"front: "<<q1.front()<<endl;
    cout<<"back: "<<q1.back()<<endl;

    while (!q1.empty())
    {
        cout<<"front: "<<q1.front()<<endl;
        cout<<"back: "<<q1.back()<<endl;
        q1.pop();
    }
    
    
    return 0;
}

