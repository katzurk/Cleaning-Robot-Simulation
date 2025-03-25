#include "furniture.h"

Furniture::Furniture(std::string name, std::vector<int> size, std::vector<int> coordinates) :
    name(name), size(size), coordinates(coordinates) {
    is_valid();
};

void Furniture::is_valid() {
    if (size.size() != 2) {
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of size. Must be 2 (x, y). Given " << coordinates.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (size[0] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid furniture length " << size[0];
        throw std::invalid_argument(exeption_str.str());
    }
    if (size[1] <= 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid furniture width " << size[1];
        throw std::invalid_argument(exeption_str.str());
    }
    if (coordinates.size() != 2) {
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of coordintates. Must be 2 (x, y). Given " << coordinates.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (coordinates[0] < 0 || coordinates[1] < 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid coordintates. Given {" << coordinates[0] << ", " << coordinates[1] << "}";
        throw std::invalid_argument(exeption_str.str());
    }
}

void Furniture::set_coordinates(const std::vector <int> new_coordinates) {
    if (new_coordinates.size() != 2) {
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of new coordintates. Given " << new_coordinates.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (new_coordinates[0] < 0 || new_coordinates[1] < 0) {
        std::stringstream exeption_str;
        exeption_str << "Invalid coordintates to set. Given {" << new_coordinates[0] << ", " << new_coordinates[1] << "}";
        throw std::invalid_argument(exeption_str.str());
    }
    this->coordinates = new_coordinates;
}