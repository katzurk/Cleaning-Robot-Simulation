/*
   autor: Alesia Filinkova
*/

#ifndef ROOM_H
#define ROOM_H

#include <random>
#include <cstdlib>
#include <ctime>
#include "furniture.h"

class Room {
private:
    std::vector<int> room_size;
    std::vector<Furniture> furniture;
    std::vector<std::vector<int>> busy_places;
    std::vector<std::vector<int>> durty_places;
    void is_valid();
    bool is_possible_to_add_object(const std::vector<int>& coordinates);
    

public:
    Room(std::vector <int> room_size = { 1, 1 });

    // Getters
    int getLength() const { return room_size[0]; }
    int getWidth() const { return room_size[1]; }
    const std::vector<Furniture>& getFurniture() const { return furniture; }
    std::vector<std::vector<int>> get_busy_places() const { return busy_places; }
    std::vector<std::vector<int>> get_durty_places() const { return durty_places; }

    // Setters
    void setLength(int length);
    void setWidth(int width);

    // method to work with furniture
    void addFurniture(const Furniture& furniture);
    void deleteFurniture(const Furniture& furn);

    // method to create dust
    void dust();
};

#endif