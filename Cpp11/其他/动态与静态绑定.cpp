/*
静态类型：对象在声明时采用的类型，在编译期既已确定；
动态类型：通常是指一个指针或引用目前所指对象的类型，是在运行期决定的；
静态绑定：绑定的是静态类型，所对应的函数或属性依赖于对象的静态类型，发生在编译期；
动态绑定：绑定的是动态类型，所对应的函数或属性依赖于对象的动态类型，发生在运行期；

非虚函数一般都是静态绑定，而虚函数都是动态绑定（如此才可实现多态性）
*/

/*
静态绑定发生在编译期，动态绑定发生在运行期；

对象的动态类型可以更改，但是静态类型无法更改；

要想实现动态，必须使用动态绑定；

在继承体系中只有虚函数使用的是动态绑定，其他的全部是静态绑定；
*/

#include <iostream>
using namespace std;

class A {
public:
	/*virtual*/ void func() { std::cout << "A::func()\n"; }
};
class B : public A {
public:
	void func() { std::cout << "B::func()\n"; }
};
class C : public A {
public:
	void func() { std::cout << "C::func()\n"; }
};


int main() {
	C* pc = new C(); //pc的静态类型是它声明的类型C*，动态类型也是C*；
	B* pb = new B(); //pb的静态类型和动态类型也都是B*；
	A* pa = pc;      //pa的静态类型是它声明的类型A*，动态类型是pa所指向的对象pc的类型C*；
	pa = pb;         //pa的动态类型可以更改，现在它的动态类型是B*，但其静态类型仍是声明时候的A*；
	C *pnull = NULL; //pnull的静态类型是它声明的类型C*,没有动态类型，因为它指向了NULL；

    pa->func();      //A::func() pa的静态类型永远都是A*，不管其指向的是哪个子类，都是直接调用A::func()；
	pc->func();      //C::func() pc的动、静态类型都是C*，因此调用C::func()；
	pnull->func();   //C::func() 不用奇怪为什么空指针也可以调用函数，因为这在编译期就确定了，和指针空不空没关系；

    // 如果将A类中的virtual注释去掉
    // B::func()
    // C::func()
    // 异常
	return 0;
}

/*
当缺省参数和virtual函数一起使用的时候一定要谨慎，不然出了问题怕是很难排查。
*/
class E {
public:
	virtual void func(int i = 0) {
		std::cout << "E::func()\t" << i << "\n";
	}
};
class F : public E {
public:
	virtual void func(int i = 1) {
		std::cout << "F::func()\t" << i << "\n";
	}
};

void test2() {
	F* pf = new F();
	E* pe = pf;
	pf->func(); //F::func() 1  正常，就该如此；
	pe->func(); //F::func() 0  哇哦，这是什么情况，调用了子类的函数，却使用了基类中参数的默认值！
}

/*
引用是否能实现动态绑定，为什么可以实现？
可以。

引用在创建的时候必须初始化，在访问虚函数时，编译器会根据其所绑定的对象类型决定要调用哪个函数。注意只能调用虚函数。
*/
class Base {
public:
	virtual void  fun() {
		cout << "base :: fun()" << endl;
	}
};

class Son : public Base {
public:
	virtual void  fun() {
		cout << "son :: fun()" << endl;
	}
	void func() {
		cout << "son :: not virtual function" <<endl;
	}
};

void test3() {
	Son s;
	Base& b = s; // 基类类型引用绑定已经存在的Son对象，引用必须初始化
	s.fun(); //son::fun()
	b.fun(); //son :: fun()
}
/*
需要说明的是虚函数才具有动态绑定，上面代码中，Son类中还有一个非虚函数func()，这在b对象中是无法调用的，如果使用基类指针来指向子类也是一样的。
*/