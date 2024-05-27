#include "furniture_generator.h"
#include "furniture.h"
#include <gtest/gtest.h>

TEST(FurnitureGeneratorTest, DefaultConstructor) {
    FurnitureGenerator generator;
    Furniture furniture = generator.createRandomFurniture();
    ASSERT_FALSE(furniture.getName().empty());
    int length = furniture.getLength();
    int width = furniture.getWidth();
    ASSERT_EQ(furniture.get_coordinates().size(), 2);

    EXPECT_GE(length, 1);
    EXPECT_LE(length, 100);
    EXPECT_GE(width, 1);
    EXPECT_LE(width, 100);

    for (int coord : furniture.get_coordinates()) {
        EXPECT_GE(coord, 0);
        EXPECT_LE(coord, 500);
    }
}

TEST(FurnitureGeneratorTest, SetSizeRangeValid) {
    FurnitureGenerator generator;
    generator.setSizeRange(10, 50);

    Furniture furniture = generator.createRandomFurniture();
    int length = furniture.getLength();
    int width = furniture.getWidth();

    EXPECT_GE(length, 10);
    EXPECT_LE(length, 50);
    EXPECT_GE(width, 10);
    EXPECT_LE(width, 50);
}

TEST(FurnitureGeneratorTest, SetSizeRangeInvalid) {
    FurnitureGenerator generator;
    EXPECT_THROW(generator.setSizeRange(0, 50), std::invalid_argument);
    EXPECT_THROW(generator.setSizeRange(10, -50), std::invalid_argument);
    EXPECT_THROW(generator.setSizeRange(50, 10), std::invalid_argument);
}

TEST(FurnitureGeneratorTest, SetCoordRangeValid) {
    FurnitureGenerator generator;
    generator.setCoordRange(100, 200);

    Furniture furniture = generator.createRandomFurniture();
    for (int coord : furniture.get_coordinates()) {
        EXPECT_GE(coord, 100);
        EXPECT_LE(coord, 200);
    }
}

TEST(FurnitureGeneratorTest, SetCoordRangeInvalid) {
    FurnitureGenerator generator;
    EXPECT_THROW(generator.setCoordRange(-100, 200), std::invalid_argument);
    EXPECT_THROW(generator.setCoordRange(100, -200), std::invalid_argument);
    EXPECT_THROW(generator.setCoordRange(200, 100), std::invalid_argument);
}

TEST(FurnitureGeneratorTest, CreateRandomFurniture) {
    FurnitureGenerator generator;

    for (int i = 0; i < 20; ++i) {
        Furniture furniture = generator.createRandomFurniture();
        ASSERT_FALSE(furniture.getName().empty());
        int length = furniture.getLength();
        int width = furniture.getWidth();
        ASSERT_EQ(furniture.get_coordinates().size(), 2);

        EXPECT_GE(length, 1);
        EXPECT_LE(length, 100);
        EXPECT_GE(width, 1);
        EXPECT_LE(width, 100);

        for (int coord : furniture.get_coordinates()) {
            EXPECT_GE(coord, 0);
            EXPECT_LE(coord, 500);
        }
    }
}
