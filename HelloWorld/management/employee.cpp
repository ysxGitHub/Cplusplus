#include"employee.h"


Employees::Employees(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Employees::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->duty()
		<< "\tְ��ְ����ɾ�����������!" << endl;
}

string Employees::duty()
{
	return string("Ա��");
}

Employees::~Employees()
{

}