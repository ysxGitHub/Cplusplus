/*
注意

模板及其特例化版本应该声明在同一个头文件中，且所有同名模板的声明应该放在前面，后面放特例化版本。
 */
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


// 函数模板特化demo
template<typename T>
T Max(T t1,T t2) {
	return (t1>t2)?t1:t2;
}

typedef const char* CCP;
template<>
CCP Max<CCP>(CCP s1,CCP s2) {
	return (strcmp(s1,s2)>0)?s1:s2;
}

// 类模板特化demo
template<typename T>
class A {
	T num;
public:
	A() {
		num=T(6.6);
	}
	void print() {
		cout<<"A'num:"<<num<<endl;
	}
};

template<>
class A<char*> {
	char* str;
public:
	A() {
		str="A' special definition ";
	}
	void print() {
		cout<<str<<endl;
	}
};


// 函数模板
template<typename T, class N>
void compare(T num1, N num2) {
	cout << "standard function template" << endl;
	if(num1>num2) {
		cout << "num1:" << num1 << " > num2:" << num2 <<endl;
	} else {
		cout << "num1:" << num1 << " <= num2:" << num2 << endl;
	}
}

// 对部分模板参数进行特化
template<class N>
void compare(int num1, N num2) {
	cout<< "partitial specialization" <<endl;
	if (num1>num2)
		cout << "num1:" << num1 << " > num2:" << num2 << endl;
	else
		cout << "num1:" << num1 << " <= num2:" << num2 << endl;
}

// 将模板参数特化为指针(模板参数的部分特性)
template<typename T, class N>
void compare(T* num1, N* num2) {
	cout << "new partitial specialization" << endl;
	if (*num1>*num2)
		cout << "num1:" << *num1 << " > num2:" << *num2 << endl;
	else
		cout << "num1:" << *num1 << " <= num2:" << *num2 << endl;
}

// 将模板参数特化为另一个模板类
template<typename T, class N>
void compare(std::vector<T>& vecLeft, std::vector<T>& vecRight) {
	cout << "to vector partitial specialization" << endl;
	if (vecLeft.size()>vecRight.size())
		cout << "vecLeft.size()" << vecLeft.size() << " > vecRight.size():" << vecRight.size() << endl;
	else
		cout << "vecLeft.size()" << vecLeft.size() << " <= vecRight.size():" << vecRight.size() << endl;
}


// 类模板
template<typename T, class N>
class TestClass {
public:
	static bool comp(T num1, N num2) {
		cout <<"standard class template"<< endl;
		return (num1<num2) ? true : false;
	}
};

// 对部分模板参数进行特化
template<class N>
class TestClass<int, N> {
public:
	static bool comp(int num1, N num2) {
		cout << "partitial specialization" << endl;
		return (num1<num2) ? true : false;
	}
};

// 将模板参数特化为指针
template<typename T, class N>
class TestClass<T*, N*> {
public:
	static bool comp(T* num1, N* num2) {
		cout << "new partitial specialization" << endl;
		return (*num1<*num2) ? true : false;
	}
};

// 将模板参数特化为另一个模板类
template<typename T, class N>
class TestClass<vector<T>,vector<N>> {
public:
	static bool comp(const vector<T>& vecLeft, const vector<N>& vecRight) {
		cout << "to vector partitial specialization" << endl;
		return (vecLeft.size()<vecRight.size()) ? true : false;
	}
};


// 可以特例化类中的部分成员函数而不是整个类
template<class T>
class Foo {
public:
    void Bar(){
        cout << "template" << endl;
    }
};

template<>
void Foo<int>::Bar() {
    //进行int类型的特例化处理
    cout << "specialization" << endl;
}

int main(int argc, char const *argv[])
{
    Foo<char> fs;
    Foo<int> fi;//使用特例化
    fs.Bar();//使用的是普通模板，即Foo<string>::Bar()
    fi.Bar();//特例化版本，执行Foo<int>::Bar()
    return 0;
}
