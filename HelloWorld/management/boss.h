#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"worker.h"

class Boss : public Person
{
public:

	Boss(int id, string name, int DepartId);

	void showInfo();

	string duty();

	~Boss();

};
