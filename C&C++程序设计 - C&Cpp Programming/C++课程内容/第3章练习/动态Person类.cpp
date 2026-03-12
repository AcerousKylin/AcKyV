#include<iostream>
#include<string>
using namespace std;

class Person
{
    private:
        string name;
        int age;
        char gender;
    public:
        Person():name("XXX"), age(0), gender('m') {}
        void Register(string n, int a, char g)
        {   name = n;   age = a;    gender = g; }
        void Showme()
        {   cout<<name<<" "<<age<<" "<<gender<<endl;    }
        ~Person()   {   cout<<"Now destroying the instance of Person";  }
};

int main() {
	char nn[20];
	int aa;
	char sex;
	cin >> nn;
	cin >> aa >> sex;

	Person *p1, * p2;
	p1 = new Person;
	p2 = new Person;
	cout << "person1:";
	p1->Showme();
	cout << "person2:";
	p2->Showme();

	p1->Register(nn, aa, sex);
	*p2 = *p1;
	cout << "person1:";
	p1->Showme();
	cout << "person2:";
	p2->Showme();

	delete p1;
	delete p2;
	return 0;
}