#include "furniture.h"
#include <gtest/gtest.h>

TEST(FurnitureTest, ConstructorTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Furniture furniture("Table", size, coordinates);
    EXPECT_EQ(furniture.getName(), "Table");
    EXPECT_EQ(furniture.getLength(), 1);
    EXPECT_EQ(furniture.getWidth(), 2);
    EXPECT_EQ(furniture.get_coordinates()[0], 3);
    EXPECT_EQ(furniture.get_coordinates()[1], 4);
}

TEST(FurnitureTest, SetNameTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Furniture furniture("Table", size, coordinates);
    furniture.setName("Chair");
    EXPECT_EQ(furniture.getName(), "Chair");
}

TEST(FurnitureTest, SetLengthTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Furniture furniture("Table", size, coordinates);
    furniture.setLength(3);
    EXPECT_EQ(furniture.getLength(), 3);
}

TEST(FurnitureTest, SetWidthTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Furniture furniture("Table", size, coordinates);
    furniture.setWidth(4);
    EXPECT_EQ(furniture.getWidth(), 4);
}

TEST(FurnitureTest, SetCoordinatesTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Furniture furniture("Table", size, coordinates);
    std::vector<int> new_coordinates = { 5, 6 };
    furniture.set_coordinates(new_coordinates);
    EXPECT_EQ(furniture.get_coordinates()[0], 5);
    EXPECT_EQ(furniture.get_coordinates()[1], 6);
}

TEST(FurnitureTest, InvalidArgumentsTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };

    // Test invalid size
    std::vector<int> invalid_size = { 1 };
    EXPECT_THROW(Furniture furniture("Table", invalid_size, coordinates), std::invalid_argument);

    // Test invalid coordinates
    std::vector<int> invalid_coordinates = { -1, 4 };
    EXPECT_THROW(Furniture furniture("Table", size, invalid_coordinates), std::invalid_argument);

    // Test invalid set_coordinates
    std::vector<int> invalid_new_coordinates = { -1, 4 };
    Furniture furniture2("Table", size, coordinates);
    EXPECT_THROW(furniture2.set_coordinates(invalid_new_coordinates), std::invalid_argument);
}