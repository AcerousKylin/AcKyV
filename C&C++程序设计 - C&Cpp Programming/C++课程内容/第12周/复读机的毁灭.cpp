#include <iostream>
using namespace std;

class Repeater;
class ForRepeater;
class RevRepeater;
Repeater *CreateRepeater(int type);

/********* Begin *********/
//复读机基类的声明
class Repeater
{
    public:
        virtual void Play() {}
        virtual ~Repeater();
};

//复读机基类的定义
Repeater::~Repeater()
{
    cout<<"砰！"<<endl;
}
//正向复读机的声明
class ForRepeater : public Repeater
{
    virtual void Play();
    virtual ~ForRepeater();
};

//正向复读机的定义
void ForRepeater::Play()
{
    cout<<"没想到你也是一个复读机"<<endl;
}

ForRepeater::~ForRepeater()
{
    cout<<"正·复读机 炸了"<<endl;
}
//反向复读机的声明
class RevRepeater : public Repeater
{
    virtual void Play();
    virtual ~RevRepeater();
};

//反向复读机的定义
void RevRepeater::Play()
{
    cout<<"机读复个一是也你到想没"<<endl;
}

RevRepeater::~RevRepeater()
{
    cout<<"机读复·反 炸了"<<endl;
}
//普通函数
Repeater *CreateRepeater(int type)
{
    if (!type)
    {
        ForRepeater* f/*=new ForRepeater*/;
        return f;
    }
    else
    {
        RevRepeater* r/*=new RevRepeater*/;
        return r;
    }
}

/********* End *********/
int main(void)
{
	int i;
	cin >> i;
	Repeater *ptr = CreateRepeater(i);
	ptr->Play();
	delete ptr;
	return 0;
}