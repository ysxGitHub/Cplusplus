#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"worker.h"

class Employees : public Person
{
public:
	Employees(int id, string name, int DepartId);

	void showInfo();

	string duty();

	~Employees();

};