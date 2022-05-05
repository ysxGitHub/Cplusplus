#include"employee.h"


Employees::Employees(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Employees::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->duty()
		<< "\t职工职责：完成经理交给的任务!" << endl;
}

string Employees::duty()
{
	return string("员工");
}

Employees::~Employees()
{

}