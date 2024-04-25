/*
   autor: Weronika Maslana
*/

#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <string>

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
        void set_coordinates(std::vector <int> new_coordinates);
};

#endif