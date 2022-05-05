#include<iostream>
#include<type_traits>
using namespace std;
// typedef basic_string<char> string;


template <typename T>
void type_traits_output(const T& x){
    cout<<"\ntype traits for type: "<<typeid(T).name()<<endl;
    cout<<"is_class\t"<<is_class<T>::value<<endl;
    cout<<"is_object\t"<<is_object<T>::value<<endl;
    cout<<"is_compound\t"<<is_compound<T>::value<<endl;
    cout<<"is_standard_layout\t"<<is_standard_layout<T>::value<<endl;
    cout<<"is_pod\t"<<is_pod<T>::value<<endl;
    cout<<"is_polymorphic\t"<<is_polymorphic<T>::value<<endl; //有虚函数？
    cout<<"has_virtual_destructor\t"<<has_virtual_destructor<T>::value<<endl;
    cout<<"is_default_constructible\t"<<is_default_constructible<T>::value<<endl;
    cout<<"is_copy_constructible\t"<<is_copy_constructible<T>::value<<endl;
    cout<<"is_move_constructible\t"<<is_move_constructible<T>::value<<endl;
    cout<<"is_copy_assignable\t"<<is_copy_assignable<T>::value<<endl;
    cout<<"is_move_assignable\t"<<is_move_assignable<T>::value<<endl;
    cout<<"is_destructible\t"<<is_destructible<T>::value<<endl;
    cout<<"is_trivial\t"<<is_trivial<T>::value<<endl;
};

class Foo{
private:
    int d1,d2;
};
class Goo{
public:
    virtual~Goo(){

    }
private:
    int d1,d2;
};

class Zoo{
public:
    Zoo(int i1, int i2):d1(i1),d2(i2){}    
    Zoo(const Zoo&)=delete;
    Zoo(Zoo&&)=default;
    Zoo& operator=(const Zoo&)=default;
    Zoo& operator=(const Zoo&&)=delete;
    virtual ~Zoo(){}
private:
    int d1, d2;
};

int main(int argc, char const *argv[])
{
    type_traits_output(Foo());
    type_traits_output(Goo());
    type_traits_output(Zoo(1,2));
    return 0;


}


