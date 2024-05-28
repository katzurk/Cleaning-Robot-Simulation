/*
   autor: Katarzyna Kanicka
*/

#ifndef GENERATOR_H
#define GENERATOR_H

#include "furniture.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>

class FurnitureGenerator {
private:
	int minSize, maxSize, minCoord, maxCoord;
	int generateRandomNumber(int min, int max);
	int generateRandomNumber10(int min, int max); // get int divisible by 10
	std::vector<int> generateRandomNumbers(int min, int max);
	std::string generateRandomName();
public:
	FurnitureGenerator();
	void setSizeRange(int min, int max);
	void setCoordRange(int min, int max);
	Furniture createRandomFurniture();
};

#endif // GENERATOR_H