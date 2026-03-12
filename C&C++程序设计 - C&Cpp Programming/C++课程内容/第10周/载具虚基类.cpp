#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
    public:
        int max_speed;
        int weight;

        void run()
        {cout<<"class vehicle is running!"<<endl; }

        void stop()
        {cout<<"class vehicle has stopped!"<<endl;}

        void SetMaxSpeed(int m_s)
        {max_speed = m_s;}

        void SetWeight(int w)
        {weight = w;}

        Vehicle(int m_s, int w):max_speed(m_s), weight(w)
        {}
};

class Bicycle:virtual public Vehicle
{
    public:
        int height;
        Bicycle(int m_s, int w, int h):Vehicle(m_s, w), height(h)
        {}
};

class Motorcar:virtual public Vehicle
{
    public:
        int seatnum;
        Motorcar(int m_s, int w, int s):Vehicle(m_s, w), seatnum(s)
        {}
};

class MotorCycle:public Bicycle, public Motorcar
{
    public:
        MotorCycle(int m_s, int w, int h, int s):
            Vehicle(m_s, w), Bicycle(m_s, w, h), Motorcar(m_s, w, s)
        {}
        void Show()
        {
            cout<<"MaxSpeed:"<<max_speed<<endl;
            cout<<"Weight:"<<weight<<endl;
            cout<<"Height:"<<height<<endl;
            cout<<"SeatNum:"<<seatnum<<endl;
        }
        void run()  {Vehicle::run();}
        void stop() {Vehicle::stop();}
};

int main(void)
{
    cout<<"输入MaxSpeed、Weight 、Height、SeatNum的值"<<endl;
    int max_speed, weight, height, seat_num;
    cin>>max_speed>>weight>>height>>seat_num;
    MotorCycle harry(max_speed, weight, height, seat_num);
    harry.Show();
    harry.run();
    harry.stop();
    harry.SetMaxSpeed(200);
    harry.SetWeight(300);
    harry.Show();
    return 0;
}