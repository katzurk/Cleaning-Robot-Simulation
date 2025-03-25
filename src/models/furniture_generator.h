/*
   autor: Katarzyna Kanicka
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include "furniture.h"
#include "cat.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

class FurnitureGenerator {
private:
	int minSize, maxSize, minCoord, maxCoord;
	int generateRandomNumber(int min, int max);
	int generateRandomNumber20(int min, int max); // get int divisible by 20
	std::vector<int> generateRandomNumbers(int min, int max);
	std::string generateRandomName();
public:
	FurnitureGenerator();
	void setSizeRange(int min, int max);
	void setCoordRange(int min, int max);
	Furniture createRandomFurniture();
	Cat createRandomCat();
};

#endif // GENERATOR_H