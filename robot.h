/*
   autor: Weronika Maslana
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <string>

class Robot{
    private:
        int size;
        std::vector <int> coordinates;
        void is_valid();

    public:
        Robot(std::vector <int> coordinates, int size);
        Robot() : size(0), coordinates({ 0, 0 }) {}
        int get_size() const;
        std::vector <int> get_coordinates() const;
        void set_size(int new_size);
        void set_coordinates(std::vector <int> new_coordinates);
};

#endif