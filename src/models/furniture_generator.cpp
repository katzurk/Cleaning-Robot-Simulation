#include "furniture_generator.h"

FurnitureGenerator::FurnitureGenerator() : minSize(10), maxSize(100), minCoord(0), maxCoord(500) {
	srand(static_cast<unsigned>(time(0)));
}

void FurnitureGenerator::setSizeRange(int min, int max) {
	if (min <= 0) {
		std::stringstream exeption_str;
		exeption_str << "Invalid furniture min size " << min;
		throw std::invalid_argument(exeption_str.str());
	}
	if (max <= 0) {
		std::stringstream exeption_str;
		exeption_str << "Invalid furniture max size " << max;
		throw std::invalid_argument(exeption_str.str());
	}
	if (min > max) {
		std::stringstream exeption_str;
		exeption_str << "Invalid size range";
		throw std::invalid_argument(exeption_str.str());
	}
	minSize = min;
	maxSize = max;
}

void FurnitureGenerator::setCoordRange(int min, int max) {
	if (min < 0) {
		std::stringstream exeption_str;
		exeption_str << "Invalid furniture min coordinate " << min;
		throw std::invalid_argument(exeption_str.str());
	}
	if (max < 0) {
		std::stringstream exeption_str;
		exeption_str << "Invalid furniture max coordinate " << max;
		throw std::invalid_argument(exeption_str.str());
	}
	if (min > max) {
		std::stringstream exeption_str;
		exeption_str << "Invalid coordinates range";
		throw std::invalid_argument(exeption_str.str());
	}
	minCoord = min;
	maxCoord = max;
}

int FurnitureGenerator::generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int FurnitureGenerator::generateRandomNumber20(int min, int max) {
	int randomNum = generateRandomNumber(min, max);
	return (randomNum / 20) * 20;

}

std::vector<int> FurnitureGenerator::generateRandomNumbers(int min, int max) {
	std::vector<int> v(2);
	for (int& dim : v) {
		dim = generateRandomNumber20(min, max);
	}
	return v;
}

std::string FurnitureGenerator::generateRandomName() {
	static const std::vector<std::string> names = {
			"Chair", "Table", "Sofa", "Cabinet", "Desk"
	};
	int index = generateRandomNumber(0, names.size() - 1);
	return names[index];
}

Furniture FurnitureGenerator::createRandomFurniture() {
	std::string name = generateRandomName();
	std::vector<int> size = { 0, 0 };
	while (size[0] == 0 || size[1] == 0) {
		size = generateRandomNumbers(minSize, maxSize);
	}

	std::vector<int> coordinates = generateRandomNumbers(minCoord, maxCoord);

	return Furniture(name, size, coordinates);
}

Cat FurnitureGenerator::createRandomCat() {
	std::string name = "Cat";
	std::vector<int> size = { 0, 0 };
	while (size[0] == 0 || size[1] == 0) {
		size = generateRandomNumbers(minSize, maxSize);
	}
	std::vector<int> coordinates = generateRandomNumbers(minCoord, maxCoord);

	return Cat(name, size, coordinates);
}