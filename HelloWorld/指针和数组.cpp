#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int* p = arr;

    cout<<*p++<<endl;
    cout<<*p<<endl;

    int* p1 = arr;

    for(int i=0;i<10;i++)
    {
        cout<<*p1++<<" ";
    }


    return 0;
}
