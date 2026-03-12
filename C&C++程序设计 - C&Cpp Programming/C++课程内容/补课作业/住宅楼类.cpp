#include<iostream>
using namespace std;

class Building
{
    private:
        int floors;
        int rooms;
        int area;
    public:
        Building(int f, int r, int a):floors(f), rooms(r), area(a) {}
        void disp()
        {
            cout<<"住宅楼："<<endl;
            cout<<"楼层层数："<<floors<<"层"<<endl;
            cout<<"房间数："<<rooms<<"间"<<endl;
            cout<<"楼房总面积："<<area<<"平方米"<<endl;
        }
};

class Home_Arch:public Building
{
    private:
        int bedrooms;
        int halls;
        int toliets;
        int kitchens;
    public:
        Home_Arch(int f, int r, int a, int b, int h, int t, int k):Building(f, r, a), bedrooms(b), halls(h), toliets(t), kitchens(k) {}
        void disp()
        {
            Building::disp();
            cout<<"其中："<<endl;
            cout<<"卧室数："<<bedrooms<<"间"<<endl;
            cout<<"客厅数："<<halls<<"间"<<endl;
            cout<<"卫生间数："<<toliets<<"间"<<endl;
            cout<<"厨房数："<<kitchens<<"间"<<endl;
        }
};

int main(void)
{
    int f, r, a, b, h, t, k;
    cin>>f>>r>>a>>b>>h>>t>>k;
    Home_Arch MyHome(f, r, a, b, h, t, k);
    MyHome.disp();
    return 0;
}