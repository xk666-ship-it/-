#include<iostream>
#include"boss.h"
using namespace std;
void boss::Showinfo() {
	cout << this->m_num << " " << this->name << " " << this->b_num << endl;
}
string boss::getPersitionName() {
	return "�ϰ�";
}
boss::boss(int m_num, string name, int b_num) {
	this->m_num = m_num;
	this->name = name;
	this->b_num = b_num;
}