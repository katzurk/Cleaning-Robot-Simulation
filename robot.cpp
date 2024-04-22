#include "robot.h"
#include <sstream>

void Robot::is_valid(){
    if(size <= 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot size " << size;
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

Robot::Robot(std::vector <int> coordinates = {0,0}, int size=10)
    :coordinates(coordinates), size(size)
{
    is_valid();
}

int Robot::get_size() const{
    return size;
}

std::vector <int> Robot::get_coordinates() const{
    return coordinates;
}

void Robot::set_size(int new_size){
    if(new_size <= 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot size to set " << new_size;
        throw std::invalid_argument(exeption_str.str());
    }
    size = new_size;
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