#include <iostream>
using namespace std;

int main(void)
{
    int a = 10;
    while (a > 0)
    {
        cout << a << endl;
        a--;
    }

    do
    {
        cout << a << endl;
        a++;
    } while (a<10);
    
    // do...while会先执行代码
    int b = 100;
    int a1,a2,a3;
    do
    {
        a1 = b/100;
        a2 = b%100/10;
        a3 = b%10;
        if(a1*a1*a1+a2*a2*a2+a3*a3*a3==b)
        {
            cout<<b<<endl;
        }
        b++;
        
    } while (b<1000);
    

    return 0;
}
