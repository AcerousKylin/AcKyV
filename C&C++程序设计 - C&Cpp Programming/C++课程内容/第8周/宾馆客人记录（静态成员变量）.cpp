#include<iostream>
#include<string>
using namespace std;

class Guest
{
    private:
        int Num;
        string Name;
        string Room;
        int fee;
        static int Count;
    public:
        Guest(string n, string r, int f);
        Guest():Name("Invalid Name"),Room("000"),fee(-1) {}
        ~Guest();
        void setOrder();
        void Display();
        static void GetCount();
};

int Guest::Count = 0;

Guest::Guest(string n, string r, int f)
{
    Name = n;
    Room = r;
    fee = f;
    Num = ++Count;
    //cout<<"Date set."<<endl;
}

Guest::~Guest()
{
    Count--;
    //cout<<"Destruct called."<<endl;
}

void Guest::Display()
{
    cout<<Num<<" "<<Name<<" "<<Room<<" "<<fee<<endl;
}

void Guest::GetCount()
{
    cout<<"Total="<<Count<<endl;
}

int main(void)
{
    string n, r;
    int f;

    cin>>n>>r>>f;
    Guest g1 = Guest(n, r, f);

    cin>>n>>r>>f;
    Guest g2 = Guest(n, r, f);

    cin>>n>>r>>f;
    Guest *g3 = new Guest(n, r, f);
    
    g1.GetCount();

    g1.Display();
    g2.Display();
    g3->Display();
    
    delete g3;
    g1.GetCount();
    
    g1.Display();
    g2.Display();
    return 0;
}