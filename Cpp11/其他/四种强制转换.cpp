/*
1. reinterpret_cast

reinterpret_cast<type-id> (expression)

type-id ������һ��ָ�롢���á��������͡�����ָ����߳�Աָ�롣��������������֮�����ǿ��ת����

2. const_cast

const_cast<type_id> (expression)

������������޸����͵�const��volatile���ԡ�����const ��volatile����֮�⣬ type_id��expression��������һ���ġ��÷����£�

1) ����ָ�뱻ת���ɷǳ�����ָ�룬������Ȼָ��ԭ���Ķ���

2) �������ñ�ת���ɷǳ��������ã�������Ȼָ��ԭ���Ķ���

3) const_castһ�������޸ĵ�ָ�롣��const char *p��ʽ

3. static_cast

static_cast < type-id > (expression)

���������expressionת��Ϊtype-id���ͣ���û������ʱ���ͼ������֤ת���İ�ȫ�ԡ�����Ҫ�����¼����÷���

1) �������νṹ�л��ࣨ���ࣩ�������ࣨ���ࣩ֮��ָ����������õ�ת��

1.1) ��������ת�������������ָ�������ת���ɻ����ʾ���ǰ�ȫ��

1.2) ��������ת�����ѻ���ָ�������ת�����������ʾ��ʱ������û�ж�̬���ͼ�飬�����ǲ���ȫ��

2) ���ڻ�����������֮���ת�������intת����char����intת����enum������ת���İ�ȫ��ҲҪ������Ա����֤��

3) �ѿ�ָ��ת����Ŀ�����͵Ŀ�ָ��

4) ���κ����͵ı��ʽת����void����

ע�⣺static_cast����ת����expression��const��volatile������__unaligned���ԡ�

dynamic_cast

�����ͼ�飬������������ת���Ƚϰ�ȫ�����������������ת����̫��ȫ

dynamic_cast <type-id> (expression)

���������expressionת����type-id���͵Ķ���type-id ���������ָ�롢������û���void*

��� type-id ����ָ�����ͣ���ôexpressionҲ������һ��ָ�룬��� type-id ��һ�����ã���ô expression Ҳ������һ������

dynamic_cast�����������ִ���ھ������������ͣ�Ҳ����˵expression�����Ƕ�̬���͡��������ת���ǰ�ȫ�ģ�Ҳ��˵���������ָ���������ȷʵָ��һ��������������������ᴫ���ʵ�ת�͹���ָ�롣��� �������ת������ȫ�����������ᴫ�ؿ�ָ�루Ҳ����˵������ָ���������û��ָ��һ�����������

dynamic_cast��Ҫ�������μ������ת��������ת����������������֮��Ľ���ת��

�����μ��������ת��ʱ��dynamic_cast��static_cast��Ч����һ����

�ڽ�������ת��ʱ��dynamic_cast�������ͼ��Ĺ��ܣ���static_cast����ȫ
*/

#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
	Base() :b(1) {}
	virtual void fun() {};
	int b;
};

class Son : public Base
{
public:
	Son() :d(2) {}
	int d;
};

int main()
{
	int n = 97;

	//reinterpret_cast
	int *p = &n;
	//��������Ч����ͬ
	char *c = reinterpret_cast<char*> (p);
	char *c2 =  (char*)(p);
	cout << "reinterpret_cast�����"<< *c2 << endl;
	//const_cast
	const int *p2 = &n;
	int *p3 = const_cast<int*>(p2);
	*p3 = 100;
	cout << "const_cast�����" << *p3 << endl;

	Base* b1 = new Son;
	Base* b2 = new Base;

	//static_cast
	Son* s1 = static_cast<Son*>(b1); //ͬ����ת��
	Son* s2 = static_cast<Son*>(b2); //����ת��������ȫ
	cout << "static_cast�����"<< endl;
	cout << s1->d << endl;
	cout << s2->d << endl; //����ת����ԭ�ȸ�����û��d��Ա���������ֵ

	//dynamic_cast
	Son* s3 = dynamic_cast<Son*>(b1); //ͬ����ת��
	Son* s4 = dynamic_cast<Son*>(b2); //����ת������ȫ
	cout << "dynamic_cast�����" << endl;
	cout << s3->d << endl;
	if(s4 == nullptr)
		cout << "s4ָ��Ϊnullptr" << endl;
	else
		cout << s4->d << endl;


	return 0;
}