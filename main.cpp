#include <string>
#include <iostream>
#include <memory>
#include "UniquePointer.h"

struct Student {
    int age;
    std::string name;
    std::string surname;
    Student(int age, std::string name, std::string surname) {
        this->age = age;
        this->name = name;
        this->surname = surname;
        if (age < 0) {
            throw std::logic_error("error: negative age");
        }
        std::cout << "Student constructed\n";
    }
    ~Student() {
        std::cout << "Student destructed\n";
    }
    void print() {
        std::cout << age << " " << name << " " << surname << std::endl;
    }
};

int main() {
    {
        try {
            auto pErrorStudent = SoftwarePorting::make_unique<Student>(-1, "Bob", "Dylan");
        } catch(const std::bad_alloc& e) {
            std::cerr << "not enough memory for object construction" << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << "\n";
        }

        try {
            auto pStudent = SoftwarePorting::make_unique<Student>(20, "Bob", "Dylan");
            pStudent->print();
            (*pStudent).age = 30;
            pStudent->surname = "Ross";
            pStudent->print();
        } catch(const std::bad_alloc& e) {
            std::cerr << "not enough memory for object construction" << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    }
    std::cout << std::endl;
    {
        try {
            auto pErrorStudent = std::make_unique<Student>(-1, "Bob", "Dylan");
        } catch(const std::bad_alloc& e) {
            std::cerr << "not enough memory for object construction" << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << "\n";
        }

        try {
            auto pStudent = std::make_unique<Student>(20, "Bob", "Dylan");
            pStudent->print();
            (*pStudent).age = 30;
            pStudent->surname = "Ross";
            pStudent->print();
        } catch(const std::bad_alloc& e) {
            std::cerr << "not enough memory for object construction" << '\n';
        } catch(const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    }
    
    return 0;
}