#include<iostream>
#include<string>
using namespace std;

class Wheel
{
    public:
        Wheel(string s="W"):name(s) { cout<<name; }
        ~Wheel() { cout<<name; }
    private:
        string name;
};

class Bicycle
{
    public:
        Bicycle(string br="G", string f="F", string r="R"):
            brand(br), rear(r), front(f) { cout<<brand; }
        ~Bicycle() { cout<<brand; }
    private:
        Wheel front, rear;
        string brand;
};

int main(void)
{
    Bicycle bike;
    return 0;
}