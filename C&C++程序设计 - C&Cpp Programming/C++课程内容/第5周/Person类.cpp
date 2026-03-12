#include<iostream>
using namespace std;

class Person
{
    private:
        string name;
        int age;
        char sex;
    public:
        void Register(string n, int a, char s);
        void ShowMe();
};

void Person::Register(string n, int a, char s)
{
    name = n;
    age = a;
    sex = s;
}

void Person::ShowMe()
{
    cout<<name<<" "<<age<<" "<<sex<<endl;
}

int main(void)
{
	Person person1, person2;
	char s[50];
	int num;
	char c;
	cin >> s >> num >> c;
	person1.Register(s, num, c);
	person2.Register("Zhang3", 19, 'm');
	person1.ShowMe();
	person2.ShowMe();
	return 0;
}