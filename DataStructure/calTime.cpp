#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

void fun01(int n, double a[], double x)
{
    double p = a[0];
    for(int i=1; i<=n; i++)
    {
        p+=(a[i]*pow(x, i));
    }
    // cout<<p<<endl;
}

void fun02(int n, double a[], double x)
{
    double p = a[n];
    for(int i=n; i>0; i--)
    {
        p=a[i-1] + x*p;
    }
    // cout<<p<<endl;    
}

int main()
{
    double a[100];

    for(int i=0; i<100; i++)
    {
        a[i] = (double)i;
    }

    clock_t start, end;
    start = clock();
    
    for(int i=0; i<100000; i++)
    {
        fun01(100, a, 20);
        // fun02(100, a, 20);
    }
    
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;

    return 0;
}
