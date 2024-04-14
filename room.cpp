#include "room.h"

Room::Room(std::vector <int> room_size) : room_size(room_size) {}

void Room::setLength(int length) {
    if (length > 0) {
        this->room_size[0] = length;
    }
    else {
        std::cerr << "Error: wrong length" << std::endl;
    }
}

void Room::setWidth(int width) {
    if (width > 0) {
        this->room_size[1] = width;
    }
    else {
        std::cerr << "Error: wrong width" << std::endl;
    }
}

void Room::addFurniture(const Furniture& furniture) {
    this->furniture.push_back(furniture);
}

void Room::deleteFurniture(std::string name, std::vector<int> position) {
    int i = 0;
    for (const auto& f : furniture)
    {
        if (f.getName() == name && f.get_coordinates()[0] == position[0] && f.get_coordinates()[1] == position[1])
        {
            furniture.erase(furniture.begin() + i);
        }
        i += 1;
    }
}