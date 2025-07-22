#include<iostream>
#include"manager.h"
using namespace std;
void manager::Showinfo() {
	cout << this->m_num << " " << this->name << " " << this->b_num << endl;
}
string manager::getPersitionName() {
	return "¾­Àí";
}
manager::manager(int m_num, string name, int b_num) {
	this->m_num = m_num;
	this->name = name;
	this->b_num = b_num;
}