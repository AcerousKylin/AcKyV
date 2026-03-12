#include<iostream>
#include<string>
#include<cmath>

using namespace std;
const double PI = 3.14159;

class Shape
{
    public:
        virtual double getArea()=0;
        virtual double getPerimeter()=0;
        virtual void show()=0;
        virtual string getClassName()
        {
            return "Shape";
        }
};

class Circle:public Shape
{
    private:
        double radius;
    public:
        Circle(double r):radius(1)
        {   radius = r;     }
        double getRadius()
        {   return radius;  }
        void setRadius(double r)
        {   radius = r;     }
        double getArea()
        {   return PI*radius*radius;    }
        double getPerimeter()
        {   return 2*PI*radius;         }
        string getClassName()
        {   return "Circle";            }
        void show()
        {
            cout<<getClassName()<<":"<<endl;
            cout<<"Radius:"<<radius<<endl;
            cout<<"Area:"<<getArea()<<", Perimeter:"<<getPerimeter()<<endl;
        }
};

class Rectangle:public Shape
{
    private:
        double height;
        double width;
    public:
        Rectangle(double h, double w):height(1), width(1)
        {   height = h;     width = w;  }
        double getWidth()
        {   return width;   }
        double getHeight()
        {   return height;  }
        void setWidth(double w)
        {   width = w;  }
        void setHeight(double h)
        {   height = h; }
        double getArea()
        {   return height*width;    }
        double getPerimeter()
        {   return 2*(height+width);    }
        string getClassName()
        {   return "Rectangle";    }
        void show()
        {
            cout<<getClassName()<<":"<<endl;
            cout<<"Width:"<<width<<", "<<"Height:"<<height<<endl;
            cout<<"Area:"<<getArea()<<", Perimeter:"<<getPerimeter()<<endl;
        }
};

class Triangle:public Shape
{
    private:
        double side1;
        double side2;
        double side3;
    public:
        Triangle(double s1, double s2, double s3):side1(s1), side2(s2), side3(s3) {}
        double getArea()
        {   double p = (side1+side2+side3)/2;
            return sqrt(p*(p-side1)*(p-side2)*(p-side3));
        }
        double getPerimeter()
        {   return side1+side2+side3;   }
        string getClassName()
        {   return "Triangle";  }
        void show()
        {
            cout<<getClassName()<<":"<<endl;
            cout<<"Side:"<<side1<<", "<<side2<<", "<<side3<<endl;
            cout<<"Area:"<<getArea()<<", Perimeter:"<<getPerimeter()<<endl;
        }
};

int main(void)
{
    Shape* s;
    double r, w, h, s1, s2, s3;
    cin>>r>>w>>h>>s1>>s2>>s3;
    Circle C(r);
    Rectangle R(h, w);
    Triangle T(s1, s2, s3);

    s = &C;
    s->show();
    s = &R;
    s->show();
    s = &T;
    s->show();
    return 0;
}