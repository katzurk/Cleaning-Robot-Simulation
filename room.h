/*
   autor: Alesia Filinkova
*/

#ifndef ROOM_H
#define ROOM_H

#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "furniture.h"

class Robot;

class Room {
private:
    std::vector<int> room_size;
    std::vector<Furniture> furniture;
    std::vector<std::vector<int>> taken_places;
    std::vector<std::vector<int>> dirty_places;
    void is_valid();


public:
    bool is_place_in_room(const std::vector<int>& coordinates) const ;
    bool is_place_free_for_object(const std::vector<int>& coordinates) const;
    Room(std::vector <int> room_size = { 1, 1 });

    // Getters
    int getLength() const { return room_size[0]; }
    int getWidth() const { return room_size[1]; }
    const std::vector<Furniture>& getFurniture() const { return furniture; }
    std::vector<std::vector<int>> get_taken_places() const { return taken_places; }
    std::vector<std::vector<int>> get_dirty_places() const { return dirty_places; }

    // Setters
    void setLength(int length);
    void setWidth(int width);

    // method to work with furniture
    void addFurniture(const Furniture& furniture);
    void deleteFurniture(const Furniture& furn);

    // method to create dust
    void dust();
    // void clean(const Robot &robot);
};

#endif