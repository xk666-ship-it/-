#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;
class manager :  public Worker {
public:
	manager(int m_num, string name, int b_num);
	void Showinfo();
	string getPersitionName();
	/*virtual ~manager()=0;*/
};