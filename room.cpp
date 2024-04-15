#include "room.h"

Room::Room(std::vector <int> room_size) : room_size(room_size) {
    is_valid();
}

void Room::is_valid() {
    if (room_size.size() != 2) {
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of size. Must be 2 (x, y). Given " << room_size.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (room_size[0] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid room length " << room_size[0];
        throw std::invalid_argument(exeption_str.str());
    }
    if (room_size[1] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid room width " << room_size[1];
        throw std::invalid_argument(exeption_str.str());
    }
}

bool Room::is_possible_to_add_object(const std::vector<int>& coordinates) 
{
    for (size_t i = 0; i < busy_places.size(); i++) {
        if (busy_places[i] == coordinates) {
            return false;
        }
    }
    return true;
}

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
    if (is_possible_to_add_object(furniture.get_coordinates()) || busy_places.size() == 0)
    {
        this->furniture.push_back(furniture);
        for (int i = 0; i <= furniture.getLength(); i++)
        {
            for (int j = 0; j <= furniture.getWidth(); j++) {
                busy_places.push_back({ furniture.get_coordinates()[0] + i, furniture.get_coordinates()[1] + j });
            }
        }
    }
    else
    {
        std::stringstream exeption_str;
        exeption_str << "Impossible to place this object ";
        throw std::invalid_argument(exeption_str.str());
    }
}

void Room::deleteFurniture(const Furniture& furn) {
    
    for (int i = 0; i <= furn.getLength(); i++)
    {
        for (int j = 0; j <= furn.getWidth(); j++)
        {
            std::vector<int> coordinate = { furn.get_coordinates()[0] + i, furn.get_coordinates()[1] + j };
            for (int g = 0; g < busy_places.size(); g++)
            {
                if (busy_places[g] == coordinate) {
                    busy_places.erase(busy_places.begin() + g);
                }
            }
        }
    }
    int k = 0;
    for (const auto& f : furniture)
    {
        if (f.get_coordinates() == furn.get_coordinates())
        {
            furniture.erase(furniture.begin() + k);
        }
        k += 1;
    }
}

void Room::dust() {
    srand(time(NULL));
    for (int i = 0; i < (rand() % (getLength() * getWidth())); i++)
    {
        std::vector<int> dust_coordinate = { rand() % getLength(), rand() % getWidth() };
        bool empty_place = true;
        for (size_t i = 0; i < busy_places.size(); i++) {
            if (busy_places[i] == dust_coordinate) {
                empty_place = false;
            }
        }
        if (empty_place) {
            durty_places.push_back(dust_coordinate);
        }
    }
}