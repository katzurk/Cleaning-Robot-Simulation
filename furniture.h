#include <iostream>
#include <vector>
#include <sstream>

class Furniture {
private:
    std::string name;
    std::vector<int> size;
    std::vector<int> coordinates;
    void is_valid();

public:
    Furniture(std::string name, std::vector<int> size, std::vector<int> coordinates);

    // Getters
    std::string getName() const { return name; }
    int getLength() const { return size[0]; }
    int getWidth() const { return size[1]; }
    std::vector <int> get_coordinates() const { return coordinates; }

    // setters
    void setName(const std::string& name) { this->name = name; }
    void setLength(int length) { this->size[0] = length; }
    void setWidth(int width) { this->size[1] = width; }
    void set_coordinates(const std::vector <int> new_coordinates);
};
