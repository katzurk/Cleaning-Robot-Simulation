#include "../models/room.h"
#include <gtest/gtest.h>


TEST(RoomTest, Dust) {
    Room room({ 10, 10 });
    room.dust();

    ASSERT_GE(room.getDirtyPlaces().size(), 0);
    ASSERT_LE(room.getDirtyPlaces().size(), 10 * 10);

    for (const auto& dirty_place : room.getDirtyPlaces()) {
        ASSERT_GE(dirty_place[0], 0);
        ASSERT_LT(dirty_place[0], 10);
        ASSERT_GE(dirty_place[1], 0);
        ASSERT_LT(dirty_place[1], 10);

        bool is_area_empty = true;
        for (const auto& taken_place : room.getTakenPlaces()) {
            if (taken_place == dirty_place) {
                is_area_empty = false;
            }
        }
        ASSERT_TRUE(is_area_empty);
    }
}

TEST(RoomTest, GetLength) {
    Room room({ 5, 5 });
    ASSERT_EQ(room.getLength(), 5);
}

TEST(RoomTest, GetWidth) {
    Room room({ 5, 5 });
    ASSERT_EQ(room.getWidth(), 5);
}


TEST(RoomTest, GetTakenPlaces) {
    Room room({ 5, 5 });
    auto furniture = std::make_unique<Furniture>("Sofa", std::vector<int>{1, 2}, std::vector<int>{0, 0});
    room.addFurniture(std::move(furniture));

    std::vector<std::vector<int>> expected_taken_places = { {0, 0}, {0, 1} };
    ASSERT_EQ(room.getTakenPlaces(), expected_taken_places);
}

TEST(RoomTest, GetDirtyPlaces) {
    Room room({ 5, 5 });

    std::vector<std::vector<int>> expected_dirty_places = {};
    ASSERT_EQ(room.getDirtyPlaces(), expected_dirty_places);
}

TEST(RoomTest, SetLength) {
    Room room({ 5, 5 });
    room.setLength(10);

    ASSERT_EQ(room.getLength(), 10);
}

TEST(RoomTest, SetWidth) {
    Room room({ 5, 5 });
    room.setWidth(10);

    ASSERT_EQ(room.getWidth(), 10);
}

// Test addFurniture method
TEST(RoomTest, AddFurnitureTest) {
    Room room({ 10, 10 });
    auto furniture = std::make_unique<Furniture>("Table", std::vector<int>{3, 2}, std::vector<int>{1, 1});

    room.addFurniture(std::move(furniture));
    EXPECT_EQ(room.getFurniture().size(), 1);
    EXPECT_EQ(room.getTakenPlaces().size(), 3 * 2);
}

// Test deleteFurniture method
TEST(RoomTest, DeleteFurnitureTest) {
    Room room({ 10, 10 });
    auto furniture = std::make_unique<Furniture>("Table", std::vector<int>{3, 2}, std::vector<int>{1, 1});
    room.addFurniture(std::move(furniture));

    room.deleteFurniture("Table");
    EXPECT_EQ(room.getFurniture().size(), 0);
    EXPECT_EQ(room.getTakenPlaces().size(), 0);
}

TEST(RoomTest, DustTest) {
    Room room({ 10, 10 });
    room.dust();
    EXPECT_GT(room.getDirtyPlaces().size(), 0); // Assuming at least one dust particle is added
    EXPECT_FALSE(room.getDirtyPlaces().empty());
}
