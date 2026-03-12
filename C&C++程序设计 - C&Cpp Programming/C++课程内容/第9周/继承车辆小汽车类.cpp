#include<iostream>
#include<string>
using namespace std;

class Vehicles
{
    private:
        string brand;
        string color;
    public:
        Vehicles(string b, string c):brand(b), color(c) {}
        void run()
        {
            cout<<"我已开动了"<<endl;
        }
        void showInfo()
        {
            cout<<"商标："<<brand<<endl;
            cout<<"颜色："<<color<<endl;
        }
};

class Car:public Vehicles
{
    private:
        int seats;
    public:
        Car(string b, string c, int s):Vehicles(b, c), seats(s) {}
        void showCar()
        {
            Vehicles::showInfo();
            cout<<"座位："<<seats<<"个"<<endl;
        }
};

int main(void)
{
	string brand, color;
	int seats;
	cin >> brand >> color;
	Vehicles v(brand, color);
	v.showInfo();
	cin >> brand >> color >> seats;
	Car c(brand, color, seats);
	c.showCar();
	return 0;
}