#include"manager.h"

Manager::Manager(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->duty()
		<< "\tְ��ְ������ϰ彻�������񣬲��·������Ա��!" << endl;
}

string Manager::duty()
{
	return string("����");
}

Manager::~Manager()
{

}