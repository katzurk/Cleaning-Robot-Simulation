#include "robot.h"
#include <sstream>
#include <iostream>

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

void Robot::object_detour(const Room &room, std::vector<int> &coordinates, std::vector<std::vector<int>> &path, int &x_direction){
    std::cout << "colision!!" << std::endl;
    int begining_y = coordinates[1];

    for (int i = 1; i < size[0]; i++){
        set_coordinate_x(coordinates[0] - x_direction);
        if(room.is_place_free_for_object(coordinates)){
            break;
        }
    }
    path.push_back(coordinates);
    std::cout << "----NEW CORDS: " << coordinates[0] << ", " << coordinates[1] << std::endl;

    //go up
    std::vector<int> possible_cords = {coordinates[0]+size[0] * x_direction, coordinates[1]};
    while(not room.is_place_free_for_object(possible_cords)){
        set_coordinate_y(coordinates[1] - size[1]);
        possible_cords[1] -= size[1];
        path.push_back(coordinates);
        std::cout << "--------going up: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    }
    path.pop_back();

    for (int i = 1; i < size[1]; i++){
        // std::cout << "------------up correction possibility: " << possible_cords[0] << ", " << possible_cords[1] << std::endl;
        possible_cords[1] += 1;
        if(not room.is_place_free_for_object(possible_cords)){
            break;
        }
    }
    possible_cords[1] -= 1;
    set_coordinate_y(possible_cords[1]);
    path.push_back(coordinates);
    std::cout << "----corrected to go left/right NEW CORDS: " << coordinates[0] << ", " << coordinates[1] << std::endl;

    // go left or right
    set_coordinate_x(coordinates[0] + size[0] * x_direction);
    path.push_back(coordinates);
    std::cout << "----NEXT CORDS: " << coordinates[0] << ", " << coordinates[1] << std::endl;

    std::vector<int> possible_cords_down = {coordinates[0], coordinates[1] + size[1]};
    while(not room.is_place_free_for_object(possible_cords_down)){
        set_coordinate_x(coordinates[0] + size[0] * x_direction);
        possible_cords_down[0] += size[0] * x_direction;
        path.push_back(coordinates);
        std::cout << "--------going left/right: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    }
    path.pop_back();

    for (int i = 1; i < size[0]; i++){
        // std::cout << "------------left/right correction possibility: " << possible_cords_down[0] << ", " << possible_cords_down[1] << std::endl;
        possible_cords_down[0] -= x_direction;
        if(not room.is_place_free_for_object(possible_cords_down)){
            break;
        }
    }
    possible_cords_down[0] += x_direction;
    set_coordinate_x(possible_cords_down[0]);
    path.push_back(coordinates);
    std::cout << "----corrected to go down NEW CORDS: " << coordinates[0] << ", " << coordinates[1] << std::endl;

    // go down

    while (coordinates[1] < begining_y) {
        set_coordinate_y(coordinates[1] + size[1]);
        path.push_back(coordinates);
        std::cout << "----going down: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    }
    path.pop_back();
    set_coordinate_y(begining_y);
    path.push_back(coordinates);


    std::cout << "----FINAL CORDS: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    return;
}

std::vector<std::vector<int>> Robot::make_path(const Room &room){
    int x_direction = 1;
    bool is_last_row = false;
    std::vector<std::vector<int>> path;
    path.push_back(coordinates);

    while (coordinates[1] + size[1] <= room.getWidth()) {
        while((coordinates[0] < room.getLength() - size[0] and x_direction > 0) or (coordinates[0] > 0 and x_direction < 0)){
            if(room.getLength() - (coordinates[0] + size[0]) < size[0] and x_direction > 0){
                set_coordinate_x(room.getLength() - size[0] * x_direction);
            }
            else if(coordinates[0] < size[0] and x_direction < 0){
                set_coordinate_x(0);
            }
            else {
                set_coordinate_x(coordinates[0] + size[0]* x_direction);
            }
            if(not room.is_place_free_for_object(coordinates)){
                object_detour(room, coordinates, path, x_direction);
            }
            else{
                std::cout << "I am FREE" << std::endl;
            }
            path.push_back(coordinates);
            std::cout << coordinates[0] << ", " << coordinates[1] << std::endl;

        }
        x_direction *= -1;
        if(is_last_row){
            break;
        }

        if(room.getWidth() - (coordinates[1] + size[1]) < size[1]){
            set_coordinate_y(room.getWidth() - size[1]);
            is_last_row = true;
        }
        else {
            set_coordinate_y(coordinates[1] + size[1]);
        }
        if(not room.is_place_free_for_object(coordinates)){
            object_detour(room, coordinates, path, x_direction);
        }
        else{
            std::cout << "I am FREE" << std::endl;
        }


        path.push_back(coordinates);
        std::cout << coordinates[0] << ", " << coordinates[1] << std::endl;
    }
    return path;
}