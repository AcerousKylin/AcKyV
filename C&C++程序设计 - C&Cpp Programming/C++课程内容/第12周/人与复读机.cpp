#include <iostream>
using namespace std;

/********* Begin *********/
//人类的声明
class Chinese
{
	public:
		virtual void greet();
};
//人类的定义

void Chinese::greet()
{
	cout<<"你好"<<endl;
}

//英语学生类的声明
class EnglishLearner : public Chinese
{
	public:
		void greet();
};
//英语学生类的定义
void EnglishLearner::greet()
{
	cout<<"Hello"<<endl;
}
//复读机类的声明
class Repeater : public Chinese
{
	public:
		void greet();
};
//复读机类的定义
void Repeater::greet()
{
	Chinese::greet();
}
/********* End *********/

int main(void)
{
	Chinese ce;
	EnglishLearner le;
	Repeater re;
	ce.greet();
	le.greet();
	re.greet();
	return 0;
}