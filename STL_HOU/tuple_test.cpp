#include<iostream>
#include<string>
#include<complex>
#include<tuple>
using namespace std;

ostream &operator<<(ostream &os, const tuple<int, float, string> &t)
{
    return os<<get<0>(t)<<", "<<get<1>(t)<<", "<<get<2>(t);
}



int main(int argc, char const *argv[])
{
    cout<<"string sizeof = "<<sizeof(string)<<endl;
    cout<<"double sizeof = "<<sizeof(double)<<endl;
    cout<<"float sizeof = "<<sizeof(float)<<endl;
    cout<<"int sizeof = "<<sizeof(int)<<endl;
    cout<<"complex<double> sizeof = "<<sizeof(complex<double>)<<endl;

    tuple<string, int, int, complex<double>> t;
    cout<<"sizeof = "<<sizeof(t)<<endl;

    tuple<int, float, string>t1(41, 6.3, "nico");
    cout<<"tuple<int, float, string> sizeof = "<<sizeof(t1)<<endl;
    cout<<"t1: "<<get<0>(t1)<<", "<<get<1>(t1)<<", "<<get<2>(t1)<<endl;

    auto t2 = make_tuple(22, 44.0, "stay");

    get<1>(t1) = get<1>(t2);

    if(t1<t2){
        cout<<"t1 < t2"<<endl;
    }else{
        cout<<"t1 >= t2 "<<endl;
    }

    t1 = t2;
    cout<<"t1: "<<t1<<endl;

    tuple<int, float, string>t3(77, 1.1, "more");
    int il;
    float fl;
    string sl;
    tie(il, fl, sl) = t3;

    typedef tuple<int, float, string> TupleType;
    cout<<tuple_size<TupleType>::value<<endl;
    tuple_element<1, TupleType>::type fi=1.0;
    typedef tuple_element<1, TupleType>::type T;
    cout<<typeid(T).name()<<endl;

    return 0;
}
    


