#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include "furniture.h"

class Room {
private:
    std::vector<int> room_size;
    std::vector<Furniture> furniture;

public:
    Room(std::vector <int> room_size={0, 0});

    // Getters
    int getLength() const { return room_size[0]; }
    int getWidth() const { return room_size[1]; }
    const std::vector<Furniture>& getFurniture() const { return furniture; }

    // Setters
    void setLength(int length);
    void setWidth(int width);

    // method to work with furniture
    void addFurniture(const Furniture& furniture);
    void deleteFurniture(std::string name, std::vector<int> position);
};