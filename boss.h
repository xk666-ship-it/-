#pragma once
#include<iostream>
#include<string>
#include"Worker.h"
using namespace std;
class boss : public Worker {
public:
	boss(int m_num, string name, int b_num);
	void Showinfo();
	string getPersitionName();
};