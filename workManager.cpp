#include<iostream>
#include"workManager.h"
#include<fstream>
#define FILENAME  "empFile.txt"
using namespace std;
WorkManager::~WorkManager() {
    if (this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_EmpNum; i++) {
            if (this->m_EmpArray[i] != NULL)
                delete this->m_EmpArray[i];
        }
        delete[] m_EmpArray;
        m_EmpArray = NULL;
    }
};
WorkManager::WorkManager() {
    this->m_EmpNum = get_EmpNum();
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()||this->m_EmpNum==0) {
        this->m_EmpArray = NULL;
    }
    else {
        this->m_EmpArray = new Worker* [this->m_EmpNum];
        int id;
        string name;
        string sex;
        int dId;
        int index = 0;
        while ( ifs >> id &&ifs>>name&& ifs >> dId) {
            Worker* worker = NULL;
            switch (dId) {
            case 1:
                worker = new employee(id, name, dId);
                break;
            case 2:
                worker = new manager(id, name, dId);
                break;
            case 3:
                worker = new boss(id, name, dId);
                break;
            }
            this->m_EmpArray[index] = worker;
            index++;
        }
    }
    ifs.close();
};
void WorkManager::Show_Menu() {
        cout << "*************************************" << endl;
        cout << "******* 欢迎使用职工管理系统 ********" << endl;
        cout << "*********** 0.退出管理程序 **********" << endl;
        cout << "*********** 1.添加职工信息 **********" << endl;
        cout << "*********** 2.显示职工信息 **********" << endl;
        cout << "*********** 3.删除离职职工 **********" << endl;
        cout << "*********** 4.修改职工信息 **********" << endl;
        cout << "*********** 5.查找职工信息 **********" << endl;
        cout << "*********** 6.按照编号排序 **********" << endl;
        cout << "*********** 7.清空所有文档 **********" << endl;
        cout << "*************************************" << endl;
        cout << endl;
}
void WorkManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
void WorkManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++){
        if(this->m_EmpArray[i]!=NULL)
        ofs << this->m_EmpArray[i]->m_num << "  " << this->m_EmpArray[i]->name << "  "
            << this->m_EmpArray[i]->b_num << endl;
    }
    ofs.close();
}
void WorkManager::Add_Emp(){
    int addNum=0;
    while (addNum <= 0) {
        cout << "请输入增加职工数量:" << endl;
        cin >> addNum;
        if (addNum > 0) {
            //计算新空间大小 
            int newsize = this->m_EmpNum + addNum;
            //开辟新空间
            Worker** newSpace = new Worker * [newsize];
            //将原空间内存存放到新空间
            if (this->m_EmpArray != NULL) {
                for (int i = 0; i < m_EmpNum; i++) {
                    newSpace[i] = this->m_EmpArray[i];
                }
                delete[] m_EmpArray;
            }
            m_EmpArray = newSpace;
            newSpace = NULL;
            for (int i = 0; i < addNum; i++) {
                int id;
                string name;
                int dSelect;
                cout << "请输入第" << i + 1 << "个员工的编号:" << endl;
                cin >> id;
                cout << "请输入第" << i + 1 << "个员工的姓名:" << endl;
                cin >> name;
                cout << "请选择该职工的职位:" << endl;
                cout << "1. 普通员工" << endl;
                cout << "2. 经理" << endl;
                cout << "3. 老板" << endl;
                cin >> dSelect;
                Worker* worker = NULL;
                switch (dSelect) {
                case 1:
                    worker = new employee(id, name, dSelect);
                    break;
                case 2:
                    worker = new manager(id, name, dSelect);
                    break;
                case 3:
                    worker = new boss(id, name, dSelect);
                    break;
                default:
                    break;
                }
                m_EmpArray[this->m_EmpNum + i] = worker;
            }
            this->m_EmpNum += addNum;
        }
        else {
            cout << "输入有误,请重新输入" << endl;
            system("pause");
        }
    }
        cout << "添加成功" << addNum << "名新职工" << endl;
        this->save();
        system("pause");
}
void WorkManager::Show_Emp() {
    if (this->m_EmpNum == 0) {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            m_EmpArray[i]->Showinfo();
        }
    }
    system("pause");
}
void WorkManager::Delete_Emp() {
    if (this->m_EmpNum == 0) {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入想删除职工的编号" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            //数据移动
            for (int i = index + 1; i < this->m_EmpNum; i++) {
                this->m_EmpArray[i - 1] = this->m_EmpArray[i];
            }
            this->m_EmpNum--;
            this->save();
            cout << "删除成功" << endl;
        } 
        else {
            cout << "删除失败,未找到该职工" << endl;
        }
    }
    system("pause");
}
int WorkManager::isExist(int id) {
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_num == id) {
            index = i;
            break;
        }
    }
    return index;
}
void WorkManager::Mod_Emp() {
    if (this->m_EmpNum == 0) {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入你要修改的职工编号:" << endl;
        int id;
        cin >> id;
        int index = isExist(id);
        if (index != -1) {
            //因为岗位会改变,所以原来的可能不适用
            delete this->m_EmpArray[index];
            string name;
            int dId;
            cout << "查到: " << id << "号员工，请输入新的职工号：" << endl;
            int new_id;
            cin >> new_id;
            cout << "请输入新姓名：" << endl;
            cin >> name;
            cout << "请选择岗位：" << endl;
            cout << "1. 普通员工" << endl;
            cout << "2. 经理" << endl;
            cout << "3. 老板" << endl;
            cin >> dId;
            Worker* worker = NULL;
            switch (dId) {
            case 1:
                worker = new employee(new_id, name, dId);
                break;
            case 2:
                worker = new manager(new_id, name, dId);
                break;
            case 3:
                worker = new boss(new_id, name, dId);
                break;
            }
            this->m_EmpArray[index] = worker;
            this->save();
            cout << "修改成功" << endl;
        }
        else {
            cout << "输入有误,职工不存在" << endl;
        }
    }
    system("pause");
}
void WorkManager::Loc_Emp() {
    if (this->m_EmpNum == 0) {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入查找方式:" << endl;
        cout << "1. 按职工编号查找" << endl;
        cout << "2. 按职工姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            cout << "请输入你要查找职工的编号：" << endl;
            int id;
            cin >> id;
            int index = isExist(id);
            if (index != -1) {
                cout << "您要查找的职工信息如下:" << endl;
                this->m_EmpArray[index]->Showinfo();
            }
            else {
                cout << "查无此人" << endl;
            }
        }
        else {
            cout << "请输入您要查找职工的姓名:" << endl;
            string name;
            cin >> name;
            int ret = -1;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->name == name) {
                    ret = i;
                    break;
                }
            }
            if (ret == -1) {
                cout << "查无此人" << endl;
            }
            else {
                cout << "查找成功,信息如下:" << endl;
                this->m_EmpArray[ret]->Showinfo();
            }
        }
    }
    system("pause");
}
void WorkManager::Sort_Emp() {
    if (this->m_EmpNum == 0) {
        cout << "文件不存在或记录为空" << endl;
    }
    else {
        cout << "请输入排序方式: " << endl;
        cout << "1. 按职工号升序" << endl;
        cout << "2. 按职工号降序" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum; i++) {
            int minOrMax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++) {
                if (select == 1) {
                    if (this->m_EmpArray[j]->m_num < this->m_EmpArray[minOrMax]->m_num) {
                        minOrMax = j;
                    }
                }
                else {
                    if (this->m_EmpArray[j]->m_num > this->m_EmpArray[minOrMax]->m_num) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                Worker* temp=this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                this->m_EmpArray[minOrMax] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->save();
    }
    system("pause");
}
void WorkManager::Clean_File() {
    cout << "确认清空?" << endl;
    cout << "1. 确认" << endl;
    cout << "2. 返回" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs;
        //打开模式,ios::trunc,如果存在删除文件并重新创建
        ofs.open(FILENAME, ios::trunc);
        ofs.close();
        //注:堆区有两种内存,一个是存放Worker * 的数组，一个是数组指向的内存
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                if(this->m_EmpArray[i]!=NULL)
                delete this->m_EmpArray[i];
            }
            delete[] m_EmpArray;
            this->m_EmpNum = 0;
            this->m_EmpArray = NULL;
        }
        cout << "清除成功" << endl;
    }
    system("pause");
}
int WorkManager::get_EmpNum() {
    int num = 0;
    string name;
    int id;
    int dId;
    ifstream ifs;
    string s;
    ifs.open(FILENAME, ios::in);
    while (ifs>>id&&ifs>>name&&ifs>>dId) {
        num++;
    }
    ifs.close();
    return num;
}