#include <iostream>
#include <string>

class Student{
    private:
        std::string name;
        std::string second_name;
        int age;
        std::string Speciality;
        std::string well;
        double grade{};

        void set_grade(double new_grade){
            grade = new_grade;
        } 
        double get_grade(){
            return grade;
        }

    public:
    void start(){
        double user_grade;
        std::cout<<"Write what grade you need: "<<std::endl;
        std::cin>> user_grade;
        set_grade(user_grade);
    }
    void show_grade(){
        std::cout<<"Your grade: "<<grade<<std::endl;
    }
};

int main(){
    Student hwh;
    hwh.start();
    hwh.show_grade();
}