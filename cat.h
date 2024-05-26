/*
   autor: Katarzyna Kanicka
*/
#ifndef CAT_H
#define CAT_H

#include "furniture.h"

class Cat : public Furniture {
private:
	std::vector<std::vector<int>> path;
public:
	Cat(std::string name, std::vector<int> size, std::vector<int> coordinates);
	std::vector<std::vector<int>> getPath() const { return path; }
	void moveCat(int deltaX, int deltaY);
};

#endif