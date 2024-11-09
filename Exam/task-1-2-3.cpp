#include <iostream>



//Task 2
class Renctangle{
    private:
        int width{};
        int height{};
    public:
        Renctangle(int w, int h){
            width = w;
            height = h;
        }
        int culculateArea(){
            return width*height;
        }
};

//Task 3
class Animal{
    public:
        virtual void makeSound() {
            std::cout << "Sound" << std::endl;
        }
};
class Dog: public Animal{
    public:
    void makeSound() override {
        std::cout << "Bark!" << std::endl;
    }
};

int main(){
    // Task 1
    std::cout<<"Програмування з використанням мови C++ "<<std::endl;
    std::cout<<"Бажанна оцінка: 12"<<std::endl;

    Renctangle object_1(5,10);
    object_1.culculateArea();
    Animal object_2;
    object_2.makeSound();
    Dog object_3;
    object_3.makeSound();

}