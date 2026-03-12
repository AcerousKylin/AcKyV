#include <iostream>
using namespace std;

class Long{
	
private://这是访问控制——私有的 
    long value; //这是数据成员，我们称Long是基本类型long的包装类，就是因为Long里面只有一个long类型的数据成员 
               
public:	//这是公有的 
    //请在以下空白书写构造函数重载，须提供3个构造函数
    /********** Begin **********/
	Long():value(0) {}
	Long(const Long &x) // 常引用
	{
	    value = x.getValue();
	}
    Long(long x):value(x) {}
    /********** End **********/

    //请不要改动以下成员函数
    long getValue() const {
		return value;
	} 
  
};//记住这里有一个分号 

int main(void)
{  
	long x;  
    cin >> x;  
    Long a;  
    Long b(x);  
    Long c(b);  
    cout << a.getValue() << " " << b.getValue() << " " << c.getValue() << endl; 
    return 0;  
}