#include <iostream>


class ENGINE{
    public:
        int i;      //回転数
        std::string name;
        ENGINE() {
        }
        void print(){
            std::cout << name << "の回転数" << i << std::endl;
        }
};


int main() {
    ENGINE E1,E2;
    E1.name = "ENGINE1";
    E2.name = "ENGINE2";
    E1.i = 1000;
    E2.i = 2000;
    E1.print();
    E2.print();
    return 0;
}