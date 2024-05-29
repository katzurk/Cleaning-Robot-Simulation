#include "cat.h"

Cat::Cat(std::string name, std::vector<int> size, std::vector<int> coordinates) : Furniture(name, size, coordinates) {
	path.push_back(coordinates);
}

void Cat::move(int deltaX, int deltaY) {
	int x = coordinates[0];
	int y = coordinates[1];
	x += deltaX;
	y += deltaY;
	set_coordinates({ x, y });
	path.push_back(coordinates);
}

void Cat::updatePath(std::vector<int> new_coordinates) {
	path.push_back(new_coordinates);
}