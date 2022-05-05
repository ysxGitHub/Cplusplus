#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"workManager.h"

int main(int argc,  const char* argv[])
{
	int choice = -1;
	WorkerManager wm;
	//wm.WorkerManagerInit();
	while (1)
	{

		wm.Show_Menu();
		cout << "请输入对应数字进行操作: ";
		cin >> choice;

		if (choice == 0)
		{
			cout << endl;
			wm.Exit_Menu();
		}
		else if (choice == 1)
		{
			cout << endl;
			wm.Show_Worker();
			cout << endl;
			//system("pause");
			//system("cls");
		}
		else if (choice == 2)
		{
			cout << endl;
			wm.Add_Worker();
			cout << endl;
		}
		else if (choice == 3)
		{
			cout << endl;
			wm.Del_Worker();
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << endl;
			wm.Mod_Worker();
			cout << endl;
		}
		else if (choice == 5)
		{
			cout << endl;
			wm.Find_Worker();
			cout << endl;
		}
		else if (choice == 6)
		{
			cout << endl;
			wm.Sort_Worker();
			cout << endl;
		}
		else if (choice == 7)
		{
			cout << endl;
			wm.Cls_Worker();
			cout << endl;
		}
	}
	
	//system("pause");
	return 0;
}


