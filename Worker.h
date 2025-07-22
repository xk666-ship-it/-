#pragma once
#include<iostream>
using namespace std;
class Worker {
public:
	virtual void Showinfo()=0;
	virtual string getPersitionName()=0;
public:
	int m_num;
	string name;
	int b_num;
};