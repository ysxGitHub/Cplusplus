#include"boss.h"

Boss::Boss(int id, string name, int DepartId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DepartId = DepartId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ��������" << this->m_Name
		<< "\tְ����λ��" << this->duty()
		<< "\tְ��ְ�𣺹���˾��������!" << endl;
}

string Boss::duty()
{
	return string("�ϰ�");
}

Boss::~Boss()
{

}