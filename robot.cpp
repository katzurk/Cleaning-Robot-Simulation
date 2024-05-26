#include "robot.h"
#include <sstream>
// #include <iostream>

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

void Robot::adjust_x_pos(int delta_x){
    set_coordinate_x(coordinates[0] + delta_x);
}

void Robot::adjust_y_pos(int delta_y){
    set_coordinate_y(coordinates[1] + delta_y);
}

std::vector<std::vector<int>> Robot::make_path(Room_info &room_info){
    int x_direction = 1;
    bool is_last_row = false;
    std::vector<std::vector<int>> path;
    path.push_back(coordinates);

    // find_room_size (room_info, path);

    while (coordinates[1] + size[1] <= room_info.getWidth()) {
        traverse_horizontal(room_info, path, x_direction);

        x_direction *= -1;
        if(is_last_row){
            break;
        }

        if(room_info.getWidth() - (coordinates[1] + size[1]) < size[1]){
            set_coordinate_y(room_info.getWidth() - size[1]);
            is_last_row = true;
        }
        else {
            adjust_y_pos(size[1]);
        }

        if(! room_info.is_place_free_for_object(coordinates, size)){
            detour_object_below_next_to_wall(room_info, path, x_direction);
        }

        path.push_back(coordinates);
    }
    return path;
}

void Robot::traverse_horizontal(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction){
    while((coordinates[0] < room_info.getLength() - size[0] && x_direction > 0) || (coordinates[0] > 0 && x_direction < 0)) {
        if(room_info.getLength() - (coordinates[0] + size[0]) < size[0] && x_direction > 0){
            set_coordinate_x(room_info.getLength() - size[0] * x_direction);
        }
        else if(coordinates[0] < size[0] && x_direction < 0){
            set_coordinate_x(0);
        }
        else {
            adjust_x_pos(size[0]* x_direction);
        }

        if(! room_info.is_place_free_for_object(coordinates, size)){
            object_detour(room_info, path, x_direction);
        }
        path.push_back(coordinates);
    }
}

void Robot::find_room_size(Room_info &room_info, std::vector<std::vector<int>> &path) {
    go_round_to_get_room_size(room_info, path, 1, 0);
    go_round_to_get_room_size(room_info, path, 0, 1);
    go_round_to_get_room_size(room_info, path, -1, 0);
    go_round_to_get_room_size(room_info, path, 0, -1);
    return;
}

void Robot::go_round_to_get_room_size(Room_info &room_info, std::vector<std::vector<int>> &path, int x_direction, int y_direction){
    std::vector<int> possible_cords = {coordinates[0] + size[0] * x_direction, coordinates[1] + size[1] * y_direction};
    while(room_info.is_place_free_for_object(possible_cords, size)){
        adjust_x_pos(size[0] * x_direction);
        adjust_y_pos(size[1] * y_direction);
        possible_cords[0] += size[0] * x_direction;
        possible_cords[1] += size[1] * y_direction;
        path.push_back(coordinates);
        // std::cout << "------------go round: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    }

    possible_cords = coordinates;
    for (int i = 1; i < size[0]; i++){
        if(! room_info.is_place_free_for_object(possible_cords, size)){
            break;
        }
        possible_cords[0] += x_direction;
        possible_cords[1] += y_direction;
        // std::cout << "------------corection go round: " << coordinates[0] << ", " << coordinates[1] << std::endl;
    }
    possible_cords[0] -= x_direction;
    possible_cords[1] -= y_direction;
    set_coordinate_x(possible_cords[0]);
    set_coordinate_y(possible_cords[1]);
    path.push_back(coordinates);

    return;
}

void Robot::go_to_touch_object(Room_info &room_info, std::vector<std::vector<int>> &path, int x_direction, int y_direction){
    for (int i = 0; i < size[0]; i++){
        if(room_info.is_place_free_for_object(coordinates, size)){
            break;
        }
        adjust_x_pos(-x_direction);
        adjust_y_pos(-y_direction);
    }
    path.push_back(coordinates);
    return;
}

void Robot::detour_object_below_next_to_wall(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction){
    int begining_y = coordinates[1];
    go_to_touch_object(room_info, path, 0, 1);

    std::vector<int> possible_cords_down = {coordinates[0], coordinates[1] + 1};
    while(! room_info.is_place_free_for_object(possible_cords_down, size)){
        adjust_x_pos(x_direction);
        if(! room_info.is_place_free_for_object(coordinates, size)) {
            adjust_x_pos(-x_direction);
            south_object_detour_up(room_info, path, x_direction);
            possible_cords_down = {coordinates[0], coordinates[1] + 1};
        }
        possible_cords_down[0] += x_direction;
        path.push_back(coordinates);
    }

    // go down
    while (coordinates[1] < begining_y) {
        adjust_y_pos(1);
        path.push_back(coordinates);
    }
}

void Robot::south_object_detour_up(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction){
    std::vector<int> possible_cords = {coordinates[0] + x_direction, coordinates[1]};

    while(! room_info.is_place_free_for_object(possible_cords, size)){
        adjust_y_pos(-1);
        possible_cords[1] -= 1;
        path.push_back(coordinates);
        if(! room_info.is_place_free_for_object(coordinates, size)) {
            adjust_y_pos(1);
            break; // no way around the object, what should little robot do?
        }
    }
}


void Robot::object_detour(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction){
    int begining_y = coordinates[1];

    go_to_touch_object(room_info, path, x_direction, 0);

    object_detour_down(room_info, path, x_direction, begining_y);

    // go left or right to be under object
    adjust_x_pos(x_direction);
    path.push_back(coordinates);

    object_detour_horizontal(room_info, path, x_direction, begining_y);

    object_detour_up(room_info, path, x_direction, begining_y);
}

void Robot::object_detour_up(Room_info &room_info, std::vector<std::vector<int>> &path,int &x_direction, int &begining_y){
    while (coordinates[1] > begining_y) {
        adjust_y_pos(-1);
        if(! room_info.is_place_free_for_object(coordinates, size)) {
            adjust_y_pos(1);
            object_detour_horizontal(room_info, path, x_direction, begining_y);
        }
        path.push_back(coordinates);
    }
}

void Robot::object_detour_down(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction, int &begining_y){
    std::vector<int> possible_cords = {coordinates[0] + x_direction, coordinates[1]};
    do {
        adjust_y_pos(1);
        possible_cords[1] += 1;
        if(! room_info.is_place_free_for_object(coordinates, size)){
            adjust_y_pos(-1);
            path.pop_back();
            detour_object_below_next_to_wall(room_info, path, x_direction);
            return;
        }
        path.push_back(coordinates);
    } while(! room_info.is_place_free_for_object(possible_cords, size));
}

void Robot::object_detour_horizontal(Room_info &room_info, std::vector<std::vector<int>> &path, int &x_direction, int &begining_y){
    std::vector<int> possible_cords_up = {coordinates[0], coordinates[1] - 1};
    while(! room_info.is_place_free_for_object(possible_cords_up, size)) {
        if(room_info.getLength() - coordinates[0] <= size[0] && x_direction > 0) {
            set_coordinate_x(room_info.getLength() - size[0] * x_direction);
            path.push_back(coordinates);
            x_direction *= -1;
            begining_y += size[1];
        } else if(coordinates[0] < size[0] && x_direction < 0) {
            set_coordinate_x(0);
            path.push_back(coordinates);
            x_direction *= -1;
            begining_y += size[1];
        } else {
            adjust_x_pos(x_direction);
            if(! room_info.is_place_free_for_object(coordinates, size)) {
                adjust_x_pos(-x_direction);
                object_detour_down(room_info, path, x_direction, begining_y);
                possible_cords_up[1] = coordinates[1] - 1;
            }
        }
        possible_cords_up[0] += x_direction;
        path.push_back(coordinates);
    }
}

