#ifndef Management_System_h
#define Management_System_h

#include <iostream>
#include <windows.h>
#include "List.h"
#include "Student.h"

namespace Management_System {

    void start() {
        std::cout << "Loading..." << std::endl;
        List<Student> stu;
        // 刷新控制台
        system("cls");

        std::cout << "Welcome to Student Performence Management System!" << std::endl;
        std::cout << "Any key to continue" <<std::endl;
        char c; 
        std::cin >> c;

        auto pause=[]()->void {
            std::string s; 
            getline(std::cin, s);
            std::cout << "Press enter to continue." << std::endl;
            getline(std::cin, s);
        };

        auto outputSelection=[]()->void {
            std::cout << "Please select an option:" << std::endl;
            std::cout << "0. Entry student information in batch" << std::endl;
            std::cout << "1. Add a student" << std::endl;
            std::cout << "2. Delete a student" << std::endl;
            std::cout << "3. Show all students" << std::endl;
            std::cout << "4. Exit" << std::endl << std::endl;
        };

        auto get_student=[]()->Student {
            std::string name;
            int id;
            int math, english, chinese, physical, chemistry;
            std::cout << "Please input the student's name: "; std::cin >> name;
            std::cout << "Please input the student's id: "; std::cin >> id;
            std::cout << "Please input the student's Math score: "; std::cin >> math;
            std::cout << "Please input the student's English score: "; std::cin >> english;
            std::cout << "Please input the student's Chinese score: "; std::cin >> chinese;
            std::cout << "Please input the student's Physical score: "; std::cin >> physical;
            std::cout << "Please input the student's Chemistry score: "; std::cin >> chemistry;
            return Student(name, id, Info(math, english, chinese, physical, chemistry));
        };

        auto EntryInBatch=[&]()->void {
            std::cout << "Please select an option:" << std::endl;
            std::cout << "0. Manual input" << std::endl;
            std::cout << "1. Input from file" << std::endl;
            int op; std::cin >> op;
            if(op == 0) {
                int num; std::cout << "Please input the number of students: "; std::cin >> num;
                for (int i=0; i<num; i++) {
                    stu.push_back(get_student());
                }
                std::cout << "Entry student information in batch successfully!" << std::endl;
            }
            else if(op == 1) {
                std::string filename; std::cout << "Please input the filename: "; std::cin >> filename;
                std::ifstream fin(filename);
                if (fin.is_open()) {
                    std::string line;
                    while (getline(fin, line)) {
                        std::istringstream iss(line);
                        std::string name, id_str;
                        int id, math, english, chinese, physical, chemistry;
                        iss >> name >> id_str >> math >> english >> chinese >> physical >> chemistry;
                        id = stoi(id_str);
                        stu.push_back(Student(name, id, Info(math, english, chinese, physical, chemistry)));
                    }
                    std::cout << "Entry student information in batch successfully!" << std::endl;
                }
                else std::cout << "Failed to open file!" << std::endl;     
            }
            else std::cout << "Invalid option!" << std::endl;
        };

        auto EntryOne=[&]()->void {
            stu.push_back(get_student());
            std::cout << "Add a student successfully!" << std::endl;
        };

        auto DeleteOne=[&]()->void {
            std::cout << "Please input the student's id: " << std::endl;
            int id; std::cin >> id;
            if (stu.earse(Student("", id))) std::cout << "Delete a student successfully!" << std::endl;
            else std::cout << "No such student!" << std::endl;
        };

        auto PrintAll=[&]()->void {
            std::cout << "The number of students : " << stu.size() << std::endl << std::endl;
            for (auto &it : stu) 
                it.show();
        };

        while (true) {
            system("cls");  

            outputSelection();

            int option; std::cin >> option;

            switch (option) {
                case 0: { EntryInBatch(); } break;

                case 1: { EntryOne(); } break;

                case 2: { DeleteOne(); } break;

                case 3: { PrintAll(); } break;

                case 4: {
                    std::cout << "Exit successfully!" << std::endl;
                    return;
                }
            }
            pause();

        }

    }

}

#endif