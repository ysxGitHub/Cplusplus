#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include"auxfunc.hpp"

using namespace std;

void test_vector(long& value)
{
    cout<<"\ntest_vector().......... \n";
    vector<string> c;
    char buf[10];
    
    clock_t timeStart = clock();
    for(long i=0; i<value; ++i)
    {
        try
        {
            snprintf(buf, 10, "%d", rand());
            c.push_back(string(buf));
        }
        catch(const std::exception& e)
        {
            cout<<"i= "<<i<<" "<<e.what()<<endl;
            abort();
        }
        
    }
    cout<<"milli-seconds:  "<<(clock()-timeStart)<<endl;
    cout<<"vector.size() = "<<c.size()<<endl;
    cout<<"vector.capacity() = "<<c.capacity()<<endl;
    cout<<"vector.front() = "<<c.front()<<endl;
    cout<<"vector.back() = "<<c.back()<<endl;
    cout<<"vector.data() = "<<c.data()<<endl;
    
    string target = get_a_target_string();

    timeStart = clock();

    auto pItem = find(c.begin(), c.end(), target);
    cout<<"find(), milli-seconds: "<<(clock()-timeStart)<<endl;
    if(pItem!=c.end())
    {
        cout<<"found, "<<*pItem<<endl;
    }
    else
    {
        cout<<"not found! "<<endl;
    }

    timeStart = clock();
    sort(c.begin(), c.end());
    string* item = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareString);
    cout<<"sort()+bsearch(), milli-seconds: "<<(clock()-timeStart)<<endl;
    if(item!=NULL)
    {
        cout<<"found, "<<*item<<endl;
    }
    else
    {
        cout<<"not found! "<<endl;
    }    
}
int main(int argc, char const *argv[])
{
    long value = 1000000;
    test_vector(value);
    return 0;
}
