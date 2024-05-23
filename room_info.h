/*
   autor: Weronika Maslana
*/

#ifndef ROOM_INFO
#define ROOM_INFO_H

#include "room.h"

class Room_info {
    private:

    public:
        int get_room_x_size(const Room &room) const { return room.getLength(); }
        int get_room_y_size(const Room &room) const { return room.getWidth(); }
        bool is_place_free_for_robot(const Room &room, const std::vector<int>& coordinates) const { return room.is_place_free_for_object(coordinates); }
};

#endif