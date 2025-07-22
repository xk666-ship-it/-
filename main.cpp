#include<iostream>
#include"workManager.h"
using namespace std;
//void test() {
//	Worker* worker=NULL;
//	worker = new employee(1,"张三",1,"男");
//	worker->Showinfo();
//	delete worker;
//	worker = new manager(1, "张三", 2,"男");
//	worker->Showinfo();
//	delete worker;
//	worker = new boss(1, "张三", 3,"男");
//	worker->Showinfo();
//	delete worker;
//}
int main() {
	WorkManager vm;
	int choice = -1;
	while (true) {
		vm.Show_Menu();
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice) {
		case 0://退出管理系统
			vm.exitSystem();
			break;
		case 1://添加职工
			vm.Add_Emp();
			break;
		case 2://显示职工信息
			cout << "职工编号 " << "姓名 " <<"部门编号 "  << endl;
			vm.Show_Emp();
			break;
		case 3://删除离职职工
			vm.Delete_Emp();
			break;
		case 4://修改职工信息
			vm.Mod_Emp();
			break;
		case 5://查找职工信息
			vm.Loc_Emp();
			break;
		case 6://按照编号排序
			vm.Sort_Emp();
			break;
		case 7://清空所有文档
			vm.Clean_File();
			break;
		default:
			cout << "输入有误,请重新输入" << endl;
			system("pause");
			break;
		}
		system("cls");
	}
}