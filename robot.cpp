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

void Robot::set_coordinate_x(int new_x){
    if(new_x < 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot coordinate X to set " << new_x;
        throw std::invalid_argument(exeption_str.str());
    }
    coordinates[0] = new_x;
}

void Robot::set_coordinate_y(int new_y){
    if(new_y < 0){
        std::stringstream exeption_str;
        exeption_str << "Invalid robot coordinate Y to set " << new_y;
        throw std::invalid_argument(exeption_str.str());
    }
    coordinates[1] = new_y;
}


std::vector<std::vector<int>> Robot::make_path(const Room &room){
    std::vector<std::vector<int>> path;

    while (coordinates[1] < room.getWidth()){
        while(coordinates[0] < room.getLength() - size[0]){
            path.push_back(coordinates);
            set_coordinate_x(coordinates[0] + size[0]);

        }
        path.push_back(coordinates);
        set_coordinate_y(coordinates[1] + size[1]);

        if(coordinates[1] > room.getWidth()){
            break;
        }

        while(coordinates[0] > 0){
            path.push_back(coordinates);
            set_coordinate_x(coordinates[0] - size[0]);
        }
        path.push_back(coordinates);
        set_coordinate_y(coordinates[1] + size[1]);

    }
    // room.clean(*this);
    return path;
}
