/*
   autor: Katarzyna Kanicka
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class FurnitureGenerator {
private:
	int minSize, maxSize, minCoord, maxCoord;
public:
	FurnitureGenerator();
	void setSizeRange(int min, int max);
	void setCoordRange(int min, int max);
};

#endif // GENERATOR_H