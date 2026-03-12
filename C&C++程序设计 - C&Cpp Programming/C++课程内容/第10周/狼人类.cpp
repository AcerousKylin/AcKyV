#include <iostream>
#include <string>
using namespace std;

/********* Begin *********/
class Wolf {
		//狼类成员的声明
    public:
        string Name;
        int Shape;
        void PrintState();
};
//狼类成员的定义

void Wolf::PrintState()
{
    cout<<"姓名："<<Name<<"，爪子锋利度为："<<Shape<<endl;
}

class Human {
		//人类成员的声明
    public:
        string Name;
        int Intell;
        void PrintState();
};
//人类成员的定义

void Human::PrintState()
{
    cout<<"姓名："<<Name<<"，智力为："<<Intell<<endl;
}

// 记得在这里写上要继承的类
class Werewolf:virtual public Wolf, virtual public Human {
		//狼人类成员的声明

    public:
        void SetName(string n);
        void SetState(int s, int i);
        void PrintAllState();

};
//狼人类成员的定义

void Werewolf::SetName(string n)
{
    Wolf::Name = Human::Name = n;
}

void Werewolf::SetState(int s, int i)
{
    Shape = s;
    Intell = i;
}

void Werewolf::PrintAllState()
{
    Wolf::PrintState();
    Human::PrintState();
}

/********* End ****/

//主函数
int main() {
	int i, j;
	string name;
	cin >> i >> j >> name;
	Werewolf ww;
	ww.SetName(name);
	ww.SetState(i, j);
	ww.PrintAllState();
}