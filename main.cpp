#include "robot.h"
#include <iostream>

int main(){
    std::cout << "HERE" << std::endl;
    std::vector <int> pos = {1,5};
    Robot rob {pos, 10};
    std::cout << rob.get_size() << ", " << rob.get_coordinates()[0] << " " << rob.get_coordinates()[1] << std::endl;

}