#include<iostream>
using namespace std;

class Dog
{
    private:
        string name;
        int age;
        char sex;
        double weight;
    public:
        void setdata();
        void GetName();
        void GetAge();
        void GetSex();
        void GetWeight();
};

void Dog::setdata()
{
    cin>>name>>age>>sex>>weight;
}

void Dog::GetName()
{
    cout<<"Its name is "<<name<<"."<<endl;
}

void Dog::GetAge()
{
    cout<<"It is "<<age<<" years old."<<endl;
}

void Dog::GetSex()
{
    if (sex=='m')
        cout<<"It is male."<<endl;
    if (sex=='f')
        cout<<"It is female."<<endl;
}

void Dog::GetWeight()
{
    cout<<"It is "<<weight<<" kg.";
}

int main(void)
{
	Dog dog;
	dog.setdata();
	cout << "It is my dog." << endl;
	dog.GetName();
	dog.GetAge();
	dog.GetSex();
	dog.GetWeight();
	return 0;
}