/*
   autor: Weronika Maslana
*/

#ifndef ROOM_INFO
#define ROOM_INFO_H
#include <vector>

class Room_info {
    private:

    public:
        virtual bool is_place_free_for_object(const std::vector<int>& coordinates, const std::vector<int>& size) const  = 0;
        virtual void update() = 0;

        virtual bool is_next_move_south_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const = 0;
        virtual bool is_next_move_east_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const = 0;
        virtual bool is_now_east_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const = 0;
};

#endif