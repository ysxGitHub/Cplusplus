#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"worker.h"

class Manager : public Person
{
public:
	Manager(int id, string name, int DepartId);

	void showInfo();

	string duty();

	~Manager();

};

