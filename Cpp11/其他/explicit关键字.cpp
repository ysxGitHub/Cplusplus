/*
何时用explicit:
    当我们不希望自动类型转换的时候用，其实标准库好多构造函数都是explicit的

何时不用explicit:
    当我们需要隐式转换的时候

关键字explicit只对一个实参的构造函数有效，需要多个实参的构造函数不能用于执行隐式转换，所以无需将这些构造函数指定为explicit。
*/

#include <iostream>
using namespace  std;

class A {
public:
	explicit A(int a) {
		cout<<"创建类成功了!"<<endl;
	}
};
int main()
{
    // 如果不加 explicit的话 A a=10； 实际的转换过程如下： 相当于直接调用A（10）；
	A a=10;
	return 0;
}