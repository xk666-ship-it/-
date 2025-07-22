#pragma once
#include<iostream>
#include<algorithm>
#include"Worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
class WorkManager {
public:
	WorkManager();
	~WorkManager();
	void Show_Menu();
	void exitSystem();
	void Add_Emp();
	void Delete_Emp();
	void save();
	//防止程序关闭后，直接对文本文件修改信息，而造成误差
	void Show_Emp();
	//按照职工编号判断想删除的员工是否存在,不存在返回-1
	int isExist(int id);
	void Mod_Emp();
	void Loc_Emp();
	void Sort_Emp();
	void Clean_File();
	int get_EmpNum();
public:
	//记录文件中的员工个数
	int m_EmpNum;
	//员工数组的指针
	Worker** m_EmpArray;
};
