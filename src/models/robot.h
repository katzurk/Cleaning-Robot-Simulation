/*
   autor: Weronika Maslana
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <string>
#include "room.h"

class Robot{
    private:
        std::vector<int> size;
        std::vector <int> coordinates;
        void is_valid();
        void adjust_x_pos(int delta_x);
        void adjust_y_pos(int delta_y);



        void traverse_horizontal(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction, bool& is_next_last_row);

        void move_back_to_check_for_moving_object(Room_info& room_info, std::vector<std::vector<int>> &path, int x_direction, int y_direction);
        void go_to_touch_object(Room_info &room_info, std::vector<std::vector<int>> &path, int x_direction, int y_direction);

        void object_detour(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction);
        void object_detour_down(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction, int& begining_y);
        void object_detour_horizontal(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction, int& begining_y);
        void object_detour_up(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction, int& begining_y);

        void detour_object_below_next_to_wall(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction, int& begining_y);
        void south_object_detour_up(Room_info& room_info, std::vector<std::vector<int>>& path, int& x_direction);
        void detour_object_below_down_finish(Room_info& room_info, std::vector<std::vector<int>>& path, int begining_y);


    public:
        Robot(std::vector <int> coordinates,std::vector<int> size);
        Robot() : size(0), coordinates({ 0, 0 }) {}
        int get_length() const;
        int get_width() const;
        std::vector <int> get_coordinates() const;

        void set_length(int length);
        void set_width(int width);
        void set_coordinate_x(int new_x);
        void set_coordinate_y(int new_y);

        std::vector<std::vector<int>> make_path(Room_info &room_info);
};

#endif