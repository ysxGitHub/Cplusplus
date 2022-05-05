#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[] = {4,2,1,3,8,5,8,9,0};
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9-i-1; j++)
        {
            int temp = 0;
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }

    }
    for(int i=0; i<9; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
