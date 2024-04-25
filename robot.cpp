#include "robot.h"
#include <sstream>

void Robot::is_valid(){
    if(size.size() != 2){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot size " << size.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if (size[0] < 0 || size[1] < 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid size. Given {" << size[0] << ", " << size[1] << "}";
        throw std::invalid_argument(exeption_str.str());
    }
    if(coordinates.size() != 2){
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of coordintates. Must be 2 (x, y). Given " << coordinates.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if(coordinates[0] < 0 || coordinates[1] < 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid coordintates. Given {" << coordinates[0] << ", " << coordinates[1] << "}";
        throw std::invalid_argument(exeption_str.str());
    }
}

Robot::Robot(std::vector <int> coordinates = {0,0}, std::vector <int> size = {10, 10})
    :coordinates(coordinates), size(size)
{
    is_valid();
}

int Robot::get_length() const{
    return size[0];
}

int Robot::get_width() const{
    return size[1];
}


std::vector <int> Robot::get_coordinates() const{
    return coordinates;
}

void Robot::set_length(int new_length){
    if(new_length <= 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot length to set " << new_length;
        throw std::invalid_argument(exeption_str.str());
    }
    size[0] = new_length;
}

void Robot::set_width(int new_width){
    if(new_width <= 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot width to set " << new_width;
        throw std::invalid_argument(exeption_str.str());
    }
    size[1] = new_width;
}

void Robot::set_coordinates(std::vector <int> new_coordinates){
    if(new_coordinates.size() != 2){
        std::stringstream exeption_str;
        exeption_str << "Invalid amount of new coordintates. Given " << new_coordinates.size();
        throw std::invalid_argument(exeption_str.str());
    }
    if(new_coordinates[0] < 0 || new_coordinates[1] < 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid coordintates to set. Given {" << new_coordinates[0] << ", " << new_coordinates[1] << "}";
        throw std::invalid_argument(exeption_str.str());
    }
    coordinates = new_coordinates;
}