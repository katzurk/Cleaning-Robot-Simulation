/*
   autor: Alesia Filinkova
*/

#ifndef ROOM_H
#define ROOM_H

#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "room_info.h"
#include "furniture.h"


class Room : virtual public Room_info {
private:
    std::vector<int> room_size;
    std::vector<Furniture> furniture;
    std::vector<std::vector<int>> taken_places;
    std::vector<std::vector<int>> dirty_places;
    void is_valid();


public:
    bool is_place_free_for_object(const std::vector<int>& coordinates, const std::vector<int>& size) const;
    bool is_next_move_south_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const {if(getWidth() - (coordinates[1] + size[1]) < size[1]){return true;} return false;};
    bool is_next_move_east_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const {if(getLength() - (coordinates[0] + size[0]) < size[0]){return true;} return false;};
    bool is_now_east_wall (const std::vector<int>& coordinates, const std::vector<int>& size) const {if(getLength() - coordinates[0] <= size[0]){return true;} return false;};


    Room(std::vector <int> room_size = { 1, 1 });

    // Getters
    int getLength() const { return room_size[0]; }
    int getWidth() const { return room_size[1]; }
    const std::vector<Furniture>& getFurniture() const { return furniture; }
    std::vector<std::vector<int>> getTakenPlaces() const { return taken_places; }
    std::vector<std::vector<int>> getDirtyPlaces() const { return dirty_places; }

    // Setters
    void setLength(int length);
    void setWidth(int width);

    // method to work with furniture
    void addFurniture(const Furniture& furniture);
    void deleteFurniture(const Furniture& furn);

    // method to create and delete dust
    void dust();
    void cleanDirty(std::vector<int> dust);
};

#endif