#pragma once
#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
	int m_Id;
	int m_DepartId;
	string  m_Name;
	
	virtual string duty() = 0;
	virtual void showInfo() = 0;
};

