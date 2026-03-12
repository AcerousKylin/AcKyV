#ifndef Student_h
#define Student_h

#include<string>
#include<iostream>

struct Info {
    int math,english,chinese,physical,chemistry;


    Info(int math=0,int english=0,int chinese=0,int physical=0,int chemistry=0) :
        math(math),english(english),chinese(chinese),physical(physical),chemistry(chemistry) {}
        
};

class Student {
private:
    std::string name;
    int id;
    Info info;

public:
    Student(std::string name={},int id={},Info info=Info{}) : name(name),id(id),info(info) {}
    
    bool operator == (const Student& other) const {
        return id==other.id;
    }

    void show() {
        std::cout<<"name: "<<name<<std::endl;
        std::cout<<"id: "<<id<<std::endl;
        std::cout<<"math: "<<info.math<<"    ";
        std::cout<<"english: "<<info.english<<"    ";
        std::cout<<"chinese: "<<info.chinese<<"    ";
        std::cout<<"physical: "<<info.physical<<"    ";
        std::cout<<"chemistry: "<<info.chemistry<<std::endl;
        std::cout<<"show end.\n"<<std::endl;
    }
};

#endif