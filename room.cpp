#include "room.h"
#include "robot.h"

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
    if (coordinates[0] < 0 || coordinates[0] > room_size[0] || coordinates[1] < 0 || coordinates[1] > room_size[1]) {
        return false;
    }
    for (size_t i = 0; i < taken_places.size(); i++) {
        if (taken_places[i] == coordinates) {
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
    if (is_possible_to_add_object(furniture.get_coordinates()) || taken_places.size() == 0)
    {
        this->furniture.push_back(furniture);
        for (int i = 0; i <= furniture.getLength() - 1; i++)
        {
            for (int j = 0; j <= furniture.getWidth() - 1; j++) {
                taken_places.push_back({ furniture.get_coordinates()[0] + i, furniture.get_coordinates()[1] + j });
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

    for (int i = 0; i <= furn.getLength() - 1; i++)
    {
        for (int j = 0; j <= furn.getWidth() - 1; j++)
        {
            std::vector<int> coordinate = { furn.get_coordinates()[0] + i, furn.get_coordinates()[1] + j };
            for (int g = 0; g < taken_places.size(); g++)
            {
                if (taken_places[g] == coordinate) {
                    taken_places.erase(taken_places.begin() + g);
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
        bool is_area_empty = true;
        for (size_t i = 0; i < taken_places.size(); i++) {
            if (taken_places[i] == dust_coordinate) {
                is_area_empty = false;
            }
        }
        if (is_area_empty) {
            dirty_places.push_back(dust_coordinate);
        }
    }
}

void Room::clean(const Robot &robot) {
    int rx = robot.get_coordinates()[0];
    int ry = robot.get_coordinates()[1];
    int width = robot.get_length() - 1;
    int height = robot.get_width() - 1;


    for (auto it = dirty_places.begin(); it != dirty_places.end();) {
        const std::vector<int>& dust_coordinate = *it;
        int x = dust_coordinate[0];
        int y = dust_coordinate[1];

        // Check if dust coordinate is on furniture
        if ((x <= rx || x > (rx + width)) && (y <= ry || y > (ry + height))) {
            dirty_places.erase(it);
        }
        else {
            ++it;
        }
    }
}
