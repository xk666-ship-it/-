#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;
class employee:public Worker {
public:
	employee(int m_num, string name, int b_num);
	void Showinfo();
	string getPersitionName();
};