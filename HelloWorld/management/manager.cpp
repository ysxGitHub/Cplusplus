#include"manager.h"

Manager::Manager(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Manager::showInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t职工岗位：" << this->duty()
		<< "\t职工职责：完成老板交给的任务，并下发任务给员工!" << endl;
}

string Manager::duty()
{
	return string("经理");
}

Manager::~Manager()
{

}