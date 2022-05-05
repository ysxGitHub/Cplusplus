#include"boss.h"

Boss::Boss(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->duty()
		<< "\t职工职责：管理公司所有事物!" << endl;
}

string Boss::duty()
{
	return string("老板");
}

Boss::~Boss()
{

}