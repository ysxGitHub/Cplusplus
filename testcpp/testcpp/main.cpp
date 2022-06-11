#include <iostream>
#include "test_template.h"
#include "test_template.cpp" // 这里必须加上 .cpp 否则需要将模板与定义写在一个hpp中
using namespace std;


int main(int argc, char const* argv[])
{
	TestTemplate<int> test_template(5);
	cout << test_template.get_ele() << endl;
	return 0;
}
