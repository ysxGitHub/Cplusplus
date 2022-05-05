#include"workManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
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
			//cout << "�ļ����ڵ�Ϊ��" << endl;
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
			//cout << "�ļ��Ѵ����Ҳ�Ϊ��" << endl;
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
	cout << "Ա������ϵͳ" << endl;
	cout << "    0: �˳�����ϵͳ" << endl;
	cout << "    1: ��ʾ����ְ����Ϣ" << endl;
	cout << "    2: ������ְְ����Ϣ" << endl;
	cout << "    3: ɾ����ְְ����Ϣ" << endl;
	cout << "    4: ����ְ����Ϣ" << endl;
	cout << "    5: ����ְ����Ϣ" << endl;
	cout << "    6: ���������ְ����Ϣ" << endl;
	cout << "    7: ���ְ����Ϣ" << endl;
}

void WorkerManager::WorkerManagerInit()
{
	//��¼ְ������
	m_EmpNum = 0;
	//��¼ְ�������ָ��
	Parray = NULL;
}

void WorkerManager::Add_Worker()
{
	int num_Emp;
	cout << "������Ҫ��ӵ�ְ��������";
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

			cout << "�������" << i + 1 << "��ְ���ı�ţ�";
			cin >> Id;

			cout << "�������" << i + 1 << "��ְ����������";
			cin >> Name;

			cout << "��" << i + 1 << "��ְ���ĸ�λ��" << endl;
			cout << "1: �ϰ�" << endl;
			cout << "2: ����" << endl;
			cout << "3: Ա��" << endl;
			cout << "���������ֽ���ѡ��";
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

			cout << "��" << i + 1 << "��ְ������Ϣ������ɣ�" << endl;
		}
		delete[] this->Parray;
		this->Parray = new_Parray;
		this->m_EmpNum = new_num;
		this->save_file();
		cout << "������" << endl;
	}
	else
	{
		cout << "�������" << endl;
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
		cout << "�ļ���¼��ԱΪ0��" << endl;
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
	cout << "������Ҫ��ѯְ���ı�ţ�";
	cin >> find_id;
	index = this->IsExist(find_id);
	
	if (index == -1)
	{
		cout << "δ�ҵ����Ϊ " << find_id << " ��ְ��" << endl;
	}
	else
	{
		cout << "�ҵ����Ϊ " << find_id << " ��ְ��" << endl;
		this->Parray[index]->showInfo();
	}
}

void WorkerManager::Del_Worker()
{
	int find_id;
	int index = -1;
	cout << "������Ҫɾ��ְ���ı�ţ�";
	cin >> find_id;
	index = this->IsExist(find_id);

	if (index == -1)
	{
		cout << "δ�ҵ����Ϊ " << find_id << " ��ְ��" << endl;
	}
	else
	{
		int del_num;
		cout << "�ҵ����Ϊ " << find_id << " ��ְ��" << endl;
		cout << "ȷ��Ҫɾ�����Ϊ " << find_id << " ��ְ����?" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else if (del_num == 2)
		{
			cout << "�˳�ɾ��" << endl;
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

	cout << "������Ҫ�޸�ְ���ı�ţ�";
	cin >> find_id;
	index = this->IsExist(find_id);

	if (index == -1)
	{
		cout << "δ�ҵ����Ϊ " << find_id << " ��ְ��" << endl;
	}
	else
	{
		cout << "�������µ�ְ����ţ�";
		cin >> new_id;
		while(-1 != this->IsExist(new_id))
		{
			if (find_id == this->Parray[index]->m_Id)
			{
				break;
			}
			cout << "��ְ������Ѵ��ڣ�������������: ";
			cin >> new_id;
		}
		//this->Parray[index]->m_Id = new_id;

		cout << "�������µ�ְ�����֣�";
		cin >> new_name;
		//this->Parray[index]->m_Name = new_name;

		cout << "�������µĲ��ű�ţ�"<<endl;
		cout << "1.�ϰ�" << endl;
		cout << "2.����" << endl;
		cout << "3.Ա��" << endl;
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
		cout << "�޸ĳɹ���" << endl;
	}

}

void WorkerManager::Sort_Worker()
{
	if (this->m_FileIsEmpty==true)
	{
		cout << "�ļ�Ϊ��" << endl;
		return;
	}

	int num = 0;
	cout << "��ѡ������ʽ?" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
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
	cout << "����ɹ�, �����Ľ��: "<<endl;
	this->save_file();
	this->Show_Worker();
}

void WorkerManager::Cls_Worker()
{
	int del=0;
	cout << "ȷ��Ҫ����ļ���?" << endl;
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
		cout << "����ļ����" << endl;
	}
	else if (del == 2)
	{
		cout << "ȡ������ļ�" << endl;
		return;
	}

}

void WorkerManager::Exit_Menu()
{
	cout << "���Ѿ��˳�Ա������ϵͳ��" << endl;
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