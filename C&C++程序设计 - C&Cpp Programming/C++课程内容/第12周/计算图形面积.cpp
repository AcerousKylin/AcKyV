#include <iostream>
using namespace std;

/********* Begin *********/
//基类的声明
class Shape
{
    public:
        virtual void PrintArea() {}
};

//矩形类的声明
class Rectangle : public Shape
{
    private:
        float width;
        float height;
    public:
        Rectangle(float w, float h):width(w), height(h) {}
        void PrintArea();
};
//矩形类的定义
void Rectangle::PrintArea()
{
    cout << "矩形面积 = " << width * height << endl;
}
//圆形类的声明
class Circle : public Shape
{
    private:
        float radius;
    public:
        Circle(float r):radius(r) {}
        void PrintArea();
};
//圆形类的定义
void Circle::PrintArea()
{
    cout << "圆形面积 = " << radius * radius * 3.14 << endl;
}
/********* End *********/
int main(void)
{
	float i, j;
	cin >> i >> j;
	Shape *ptr = new Rectangle(i, j);
	ptr->PrintArea();
	delete ptr;

	ptr = new Circle(i);
	ptr->PrintArea();
	delete ptr;
	return 0;
}