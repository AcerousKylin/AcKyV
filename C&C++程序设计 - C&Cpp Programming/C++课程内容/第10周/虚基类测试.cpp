#include <iostream>
using namespace std;

/********** Begin **********/

class Vehicle
{
    public:
        void run()
        {
            cout<<"run"<<endl;
            
        }
        void stop()
        {
            cout<<"stop"<<endl;
            
        }
        Vehicle()
        {}
};

class Bicycle:public Vehicle
{
    public:
        Bicycle():Vehicle()
        {
            cout<<"Bicycle ";
        }
};

class Motorcar:public Vehicle
{
    public:
        Motorcar():Vehicle() {}
        
        void Run()
        {
            Vehicle::run();
        }
        void Stop()
        {
            cout<<"Motorcar ";
            Vehicle::stop();
        }
};

/********** End **********/

class Motorcycle : public Bicycle, public Motorcar {
};

int main(void)
{
	Motorcycle motorcycle;
	motorcycle.Run();
	motorcycle.Stop();
	return 0;
}