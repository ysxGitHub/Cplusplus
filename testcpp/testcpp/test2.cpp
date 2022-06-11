#include <iostream>
#include <string>
using namespace std;


int main2()
{
	try
	{
		char* p = new char[10e11];
		delete p;
	}
	catch (const std::bad_alloc& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}