#include "furniture_generator.h"

FurnitureGenerator::FurnitureGenerator() : minSize(1), maxSize(100), minCoord(0), maxCoord(500) {
	srand(static_cast<unsigned>(time(0)));
}

void FurnitureGenerator::setSizeRange(int min, int max) {
	minSize = min;
	maxSize = max;
}

void FurnitureGenerator::setCoordRange(int min, int max) {
	minCoord = min;
	maxCoord = max;
}