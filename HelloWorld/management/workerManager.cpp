#include"workManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_FileIsEmpty = true;
		this->m_EmpNum = 0;
		this->Parray = NULL;
		ifs.close();
		return;
	}
	else
	{
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			//cout << "文件存在但为空" << endl;
			this->m_FileIsEmpty = true;
			this->m_EmpNum = 0;
			this->Parray = NULL;
			ifs.close();
			return;
		}
		else
		{
			ifs.clear();
			ifs.seekg(0, ios::beg);
			int id;
			int departId;
			string  name;
			int num = 0;
			this->m_EmpNum = 0;
			//cout << "文件已存在且不为空" << endl;
			this->m_FileIsEmpty = false;
			while (ifs>>id && ifs>>name && ifs>>departId)
			{
				this->m_EmpNum ++;
			}
			this->Parray = new Person * [this->m_EmpNum];

			ifs.clear();
			ifs.seekg(0, ios::beg);
			while (ifs >> id && ifs >> name && ifs >> departId)
			{
				Person* p1 = NULL;
				if (departId == 1)
				{
					p1 = new Boss(id, name, departId);
				}
				else if (departId == 2)
				{
					p1 = new Manager(id, name, departId);
				}
				else if (departId == 3)
				{
					p1 = new Employees(id, name, departId);
				}
				this->Parray[num] = p1;
				num++;
			}
			ifs.close();
		}
	
	}

}

void WorkerManager::Show_Menu()
{
	cout << "员工管理系统" << endl;
	cout << "    0: 退出管理系统" << endl;
	cout << "    1: 显示所有职工信息" << endl;
	cout << "    2: 增加入职职工信息" << endl;
	cout << "    3: 删除离职职工信息" << endl;
	cout << "    4: 更改职工信息" << endl;
	cout << "    5: 查找职工信息" << endl;
	cout << "    6: 按编号排序职工信息" << endl;
	cout << "    7: 清空职工信息" << endl;
}

void WorkerManager::WorkerManagerInit()
{
	//记录职工人数
	m_EmpNum = 0;
	//记录职工数组的指针
	Parray = NULL;
}

void WorkerManager::Add_Worker()
{
	int num_Emp;
	cout << "请输入要添加的职工个数：";
	cin >> num_Emp;

	if (num_Emp > 0)
	{
		int new_num = num_Emp + this->m_EmpNum;
		Person** new_Parray = new Person * [new_num];

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			new_Parray[i] = this->Parray[i];
		}

		for (int i = 0; i < num_Emp; i++)
		{
			int Id;
			string  Name;
			int Dselect;
			Person* p1 = NULL;

			cout << "请输入第" << i + 1 << "新职工的编号：";
			cin >> Id;

			cout << "请输入第" << i + 1 << "新职工的姓名：";
			cin >> Name;

			cout << "第" << i + 1 << "新职工的岗位：" << endl;
			cout << "1: 老板" << endl;
			cout << "2: 经理" << endl;
			cout << "3: 员工" << endl;
			cout << "请输入数字进行选择：";
			cin >> Dselect;
			if (Dselect == 1)
			{
				p1 = new Boss(Id, Name, 1);
			}
			else if (Dselect == 2)
			{
				p1 = new Manager(Id, Name, 2);
			}
			else if (Dselect == 3)
			{
				p1 = new Employees(Id, Name, 3);
			}
			new_Parray[this->m_EmpNum + i] = p1;

			cout << "第" << i + 1 << "新职工的信息输入完成！" << endl;
		}
		delete[] this->Parray;
		this->Parray = new_Parray;
		this->m_EmpNum = new_num;
		this->save_file();
		cout << "添加完成" << endl;
	}
	else
	{
		cout << "输入错误" << endl;
	}
	

}

void WorkerManager::save_file()
{
	ofstream ofs(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->Parray[i]->m_Id << " "
			<< this->Parray[i]->m_Name << " "
			<< this->Parray[i]->m_DepartId << endl;
	}
	ofs.close();

}

void WorkerManager::Show_Worker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件记录成员为0个" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->Parray[i]->showInfo();
		}
	}

}

int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->Parray[i]->m_Id == id)
		{
			return i;
		}
	}
	if (index == -1)
	{
		return -1;
	}
}

void WorkerManager::Find_Worker()
{
	int find_id;
	int index = -1;
	cout << "请输入要查询职工的编号：";
	cin >> find_id;
	index = this->IsExist(find_id);
	
	if (index == -1)
	{
		cout << "未找到编号为 " << find_id << " 的职工" << endl;
	}
	else
	{
		cout << "找到编号为 " << find_id << " 的职工" << endl;
		this->Parray[index]->showInfo();
	}
}

void WorkerManager::Del_Worker()
{
	int find_id;
	int index = -1;
	cout << "请输入要删除职工的编号：";
	cin >> find_id;
	index = this->IsExist(find_id);

	if (index == -1)
	{
		cout << "未找到编号为 " << find_id << " 的职工" << endl;
	}
	else
	{
		int del_num;
		cout << "找到编号为 " << find_id << " 的职工" << endl;
		cout << "确认要删除编号为 " << find_id << " 的职工吗?" << endl;
		cout << "1.Yes" << endl;
		cout << "2.No" << endl;
		cin >> del_num;
		if (del_num == 1)
		{
			for (int i = index; i < this->m_EmpNum; i++)
			{
				this->Parray[i] = this->Parray[i + 1];
			}
			this->m_EmpNum--;
			this->save_file();
			cout << "删除成功" << endl;
		}
		else if (del_num == 2)
		{
			cout << "退出删除" << endl;
			return;
		}
	}
}

void WorkerManager::Mod_Worker()
{
	int find_id;
	int index = -1;

	int new_id=0;
	string new_name;
	int new_DId=0;

	cout << "请输入要修改职工的编号：";
	cin >> find_id;
	index = this->IsExist(find_id);

	if (index == -1)
	{
		cout << "未找到编号为 " << find_id << " 的职工" << endl;
	}
	else
	{
		cout << "请输入新的职工编号：";
		cin >> new_id;
		while(-1 != this->IsExist(new_id))
		{
			if (find_id == this->Parray[index]->m_Id)
			{
				break;
			}
			cout << "该职工编号已存在，请重新输入编号: ";
			cin >> new_id;
		}
		//this->Parray[index]->m_Id = new_id;

		cout << "请输入新的职工名字：";
		cin >> new_name;
		//this->Parray[index]->m_Name = new_name;

		cout << "请输入新的部门编号："<<endl;
		cout << "1.老板" << endl;
		cout << "2.经理" << endl;
		cout << "3.员工" << endl;
		cin >> new_DId;
		//this->Parray[index]->m_DepartId;

		Person* p1 = NULL;
		if (new_DId == 1)
		{
			p1 = new Boss(new_id, new_name, new_DId);
		}
		else if (new_DId == 2)
		{
			p1 = new Manager(new_id, new_name, new_DId);
		}
		else if (new_DId == 3)
		{
			p1 = new Employees(new_id, new_name, new_DId);
		}
		this->Parray[index] = p1;
		this->save_file();
		cout << "修改成功！" << endl;
	}

}

void WorkerManager::Sort_Worker()
{
	if (this->m_FileIsEmpty==true)
	{
		cout << "文件为空" << endl;
		return;
	}

	int num = 0;
	cout << "请选择排序方式?" << endl;
	cout << "1.升序" << endl;
	cout << "2.降序" << endl;
	cin >> num;


	for (int i = 0; i < this->m_EmpNum; i++)
	{
		int minOrmax = i;
		for (int j = i+i; j < this->m_EmpNum; j++)
		{
			if (num == 1)
			{
				if (this->Parray[minOrmax]->m_Id > this->Parray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
			else if (num == 2)
			{
				if (this->Parray[minOrmax]->m_Id < this->Parray[j]->m_Id)
				{
					minOrmax = j;
				}
			}
		}
		if (i != minOrmax)
		{
			Person* temp = this->Parray[i];
			this->Parray[i] = this->Parray[minOrmax];
			this->Parray[minOrmax] = temp;
		}
	}
	cout << "排序成功, 排序后的结果: "<<endl;
	this->save_file();
	this->Show_Worker();
}

void WorkerManager::Cls_Worker()
{
	int del=0;
	cout << "确认要清空文件吗?" << endl;
	cout << "1.Yes" << endl;
	cout << "2.No" << endl;
	cin >> del;

	if (del == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->Parray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->Parray[i] != NULL)
				{
					delete this->Parray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->Parray;
			this->Parray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空文件完成" << endl;
	}
	else if (del == 2)
	{
		cout << "取消清空文件" << endl;
		return;
	}

}

void WorkerManager::Exit_Menu()
{
	cout << "以已经退出员工管理系统！" << endl;
	exit(0);
}


WorkerManager::~WorkerManager()
{
	if (this->Parray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->Parray[i] != NULL)
			{
				delete this->Parray[i];
			}
		}
		this->m_EmpNum = 0;
		delete[] this->Parray;
		this->Parray = NULL;
		this->m_FileIsEmpty = true;
	}
}