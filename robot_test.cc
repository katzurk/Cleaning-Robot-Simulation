#include "robot.h"
#include <gtest/gtest.h>

std::vector <int> pos = {0,0};
std::vector <int> size = {10,10};
Robot rob {pos, size};

// getters
TEST (Robot_Test, GetLength_ReturnsProperSize){
    EXPECT_EQ(rob.get_length(), 10);
}

TEST (Robot_Test, GetWidth_ReturnsProperSize){
    EXPECT_EQ(rob.get_width(), 10);
}


TEST (Robot_Test, GetCoordinates_ReturnsProperCoordinates){
    EXPECT_EQ(rob.get_coordinates(), pos);
}


// setters
TEST (Robot_Test, SetCoordinates_ReturnsProperCoordinates){
    EXPECT_EQ(rob.get_coordinates(), pos);
    std::vector <int> pos2 = {1,5};

    rob.set_coordinates(pos2);
    EXPECT_EQ(rob.get_coordinates(), pos2);
}

TEST (Robot_Test, SetLength_ReturnsProperSize){
    EXPECT_EQ(rob.get_length(), 10);

    rob.set_length(5);
    EXPECT_EQ(rob.get_length(), 5);
    rob.set_length(10);
}

TEST (Robot_Test, SetWidth_ReturnsProperSize){
    EXPECT_EQ(rob.get_width(), 10);

    rob.set_width(5);
    EXPECT_EQ(rob.get_width(), 5);
    rob.set_width(10);
}


// invalid Robot
TEST (Robot_Test, RobotWrongSize_ReturnsError){
    std::vector <int> pos = {0,0};
    std::vector <int> size = {1,-2};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, size);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid size. Given {1, -2}", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, RobotWrongPosition_ReturnsError){
    std::vector <int> pos = {-1,0};
    std::vector <int> size = {10,10};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, size);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid coordintates. Given {-1, 0}", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, RobotTooLittlePosArgs_ReturnsError){
    std::vector <int> size = {10,10};
    std::vector <int> pos = {0};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, size);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid amount of coordintates. Must be 2 (x, y). Given 1", e.what());
            throw;
        }

    }, std::invalid_argument);
}

// invalid setters
TEST (Robot_Test, SetInvalidLength_ReturnsError){
    EXPECT_THROW({
        try {
            rob.set_length(-2);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid robot length to set -2", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, SetInvalidWidth_ReturnsError){
    EXPECT_THROW({
        try {
            rob.set_width(-3);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid robot width to set -3", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, SetInvalidCoordinatesAmount_ReturnsError){
    std::vector <int> pos = {0};
    EXPECT_THROW({
        try {
            rob.set_coordinates(pos);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid amount of new coordintates. Given 1", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, SetInvalidCoordinates_ReturnsError){
    std::vector <int> pos = {0, -3};
    EXPECT_THROW({
        try {
            rob.set_coordinates(pos);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid coordintates to set. Given {0, -3}", e.what());
            throw;
        }

    }, std::invalid_argument);
}