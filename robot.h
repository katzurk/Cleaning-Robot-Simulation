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

        std::vector<std::vector<int>> make_path(const Room &room);

};

#endif