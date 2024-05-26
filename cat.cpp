#include "cat.h"

Cat::Cat(std::string name, std::vector<int> size, std::vector<int> coordinates) : Furniture(name, size, coordinates) {
	path.push_back(coordinates);
}

void Cat::moveCat(int deltaX, int deltaY) {
	int x = coordinates[0];
	int y = coordinates[1];
	x += deltaX;
	y += deltaY;
	set_coordinates({ x, y });
	path.push_back(coordinates);
}