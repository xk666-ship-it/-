#include<iostream>
#include"employee.h"

void employee::Showinfo() {
	cout <<  this->m_num << " "<<this->name << " " << this->b_num << endl;
}
string employee::getPersitionName() {
	return "ÆÕÍ¨Ô±¹¤";
}
employee::employee(int m_num, string name, int b_num) {
	this->m_num = m_num;
	this->name = name;
	this->b_num = b_num;
}