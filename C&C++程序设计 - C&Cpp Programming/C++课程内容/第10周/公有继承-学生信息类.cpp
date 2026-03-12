#include <iostream>
#include <string>

using namespace std;

class People {
	public:
		string Name;
		void PrintName();
};

void People::PrintName() {
	cout << "姓名：" << Name << endl;
}

/**********  Begin **********/
//公有继承 People
class Student:public People {
	public:
        int SID;
		void PrintSID();
};
/**********  End **********/

void Student::PrintSID() {
	/********* Begin *********/
	//输出 SID

    cout << "学号：" << SID << endl;

	/********* End *********/
}

//普通函数
void Set(int sid, string name, Student *ptr) {
	/********* Begin *********/
	//给 ptr 对象的两个属性赋值

    ptr->SID = sid;
    ptr->Name = name;

	/********* End *********/
}

// 主函数
int main() {
	int id;
	string name;
	cin >> id >> name ;
	Student st;
	Set(id, name, &st);
	st.PrintSID();
	st.PrintName();
}