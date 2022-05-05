#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "employeeFile.txt"

class WorkerManager
{
public:
	//记录职工人数
	int m_EmpNum;
	//记录职工数组的指针
	Person** Parray;
	//标志文件是否为空
	bool m_FileIsEmpty;

	WorkerManager();

	void Show_Menu();

	void Exit_Menu();

	void WorkerManagerInit();

	void Add_Worker();

	void save_file();

	void Show_Worker();

	int IsExist(int id);

	void Del_Worker();

	void Find_Worker();

	void Mod_Worker();

	void Sort_Worker();

	void Cls_Worker();

	~WorkerManager();

};