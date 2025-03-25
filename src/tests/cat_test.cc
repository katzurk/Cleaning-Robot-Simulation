#include "../models/cat.h"
#include <gtest/gtest.h>

TEST(CatTest, ConstructorCatTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Cat cat("Cat", size, coordinates);
    EXPECT_EQ(cat.getName(), "Cat");
    EXPECT_EQ(cat.getLength(), 1);
    EXPECT_EQ(cat.getWidth(), 2);
    EXPECT_EQ(cat.get_coordinates()[0], 3);
    EXPECT_EQ(cat.get_coordinates()[1], 4);
    EXPECT_EQ(cat.getPath().size(), 1);
}

TEST(CatTest, MoveCatTest) {
    std::vector<int> size = { 1, 2 };
    std::vector<int> coordinates = { 3, 4 };
    Cat cat("Cat", size, coordinates);
    EXPECT_EQ(cat.getName(), "Cat");
    EXPECT_EQ(cat.getLength(), 1);
    EXPECT_EQ(cat.getWidth(), 2);
    EXPECT_EQ(cat.get_coordinates()[0], 3);
    EXPECT_EQ(cat.get_coordinates()[1], 4);

    cat.move(1, -1);
    EXPECT_EQ(cat.get_coordinates()[0], 4);
    EXPECT_EQ(cat.get_coordinates()[1], 3);
    EXPECT_EQ(cat.getPath().size(), 2);
}

