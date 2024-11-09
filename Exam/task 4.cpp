#include <iostream>

class Car{
    private:
        int speed{};
    public:
        int increase(int add_speed){
            speed += add_speed;
            return speed;
        }
        int decrease(int add_speed){
            if (speed <= add_speed){
                std::cout<<"Speed can`t be less that zero!"<<std::endl;
            }
            else{
                speed -= add_speed;
            }
            return speed;
        }
        void show_speed(){
            std::cout<<"Speed: "<<speed<<std::endl;
        }
};

int main(){
    Car Hyunday;
    Hyunday.decrease(10);
    Hyunday.show_speed();
    Hyunday.increase(100);
    Hyunday.show_speed();
    Hyunday.decrease(10);
    Hyunday.show_speed();
}