#include "robot.h"
#include "room.h"
#include <iostream>

int main(){
    std::vector <int> pos = {1,5};
    Robot rob {pos, 10};
    std::cout << rob.get_size() << ", " << rob.get_coordinates()[0] << " " << rob.get_coordinates()[1] << std::endl;
    std::vector <int> room_size = { 120, 40 };
    Room room(room_size);
    room.setLength(80);
    room.setWidth(60);
    Furniture furniture1("Chair", { 5, 5 }, { 10, 10 });
    room.addFurniture(furniture1);
    Furniture furniture2("Table", { 15, 15 }, { 10, 10 });
    room.addFurniture(furniture2);

    std::cout << "room's length: " << room.getLength() << std::endl;
    std::cout << "room's width: " << room.getWidth() << std::endl;
    std::cout << "furniture in room: " << std::endl;
    for (const auto& item : room.getFurniture()) {
        std::cout << item.getName() << " " << item.getLength() << " " << item.get_coordinates()[0] << std::endl;
    }
    room.deleteFurniture("Chair", { 10, 10 });
    std::cout << std::endl;
}