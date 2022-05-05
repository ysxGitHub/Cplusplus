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
	//��¼ְ������
	int m_EmpNum;
	//��¼ְ�������ָ��
	Person** Parray;
	//��־�ļ��Ƿ�Ϊ��
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