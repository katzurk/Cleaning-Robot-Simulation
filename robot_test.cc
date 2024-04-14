#include "robot.h"
#include <gtest/gtest.h>

std::vector <int> pos = {0,0};
Robot rob {pos, 10};

// getters
TEST (Robot_Test, GetSize_ReturnsProperSize){
    EXPECT_EQ(rob.get_size(), 10);
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

TEST (Robot_Test, SetSize_ReturnsProperSize){
    EXPECT_EQ(rob.get_size(), 10);

    rob.set_size(5);
    EXPECT_EQ(rob.get_size(), 5);
}

// invalid Robot
TEST (Robot_Test, RobotWrongSize_ReturnsError){
    std::vector <int> pos = {0,0};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, -2);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid robot size -2", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, RobotWrongPosition_ReturnsError){
    std::vector <int> pos = {-1,0};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, 10);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid coordintates. Given {-1, 0}", e.what());
            throw;
        }

    }, std::invalid_argument);
}

TEST (Robot_Test, RobotTooLittlePosArgs_ReturnsError){
    std::vector <int> pos = {0};
    EXPECT_THROW({
        try {
            Robot wrong_rob (pos, 10);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid amount of coordintates. Must be 2 (x, y). Given 1", e.what());
            throw;
        }

    }, std::invalid_argument);
}

// invalid setters
TEST (Robot_Test, SetInvalidSize_ReturnsError){
    EXPECT_THROW({
        try {
            rob.set_size(-2);
        }
        catch (const std::invalid_argument &e){
            EXPECT_STREQ("Invalid robot size to set -2", e.what());
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