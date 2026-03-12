#include <iostream>
using namespace std;

/********* Begin *********/

class Virus
{
	//病毒类的声明
    public:
        int Gen;
        Virus():Gen(0) {}
        Virus(int g):Gen(g) {}
        Virus(const Virus &v);
        friend bool operator==(const int &g, const Virus &v);
};

//病毒类的定义以及其他内容

Virus::Virus(const Virus &v)
{
    Gen = v.Gen+1;
}

bool operator==(const int &g, const Virus &v)
{
    return v.Gen==g; 
}

/********* End *********/

int main(void)
{
	int i, j;
	cin >> i >> j;
	Virus vs[3];
	vs[0] = Virus();
	vs[1] = Virus(vs[i]);
	vs[2] = Virus(vs[j]);
	for (int g = 0; g < 3; g++) {
		int count = 0;
		for (int i = 0; i < 3; i++) {
			if (g == vs[i])
				count++;
		}
		cout << "年龄：" << g << " 数量：" << count << endl;
	}
}