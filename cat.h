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
	virtual void move(int deltaX, int deltaY);
	virtual void updatePath(std::vector<int> coordinates);
};

#endif