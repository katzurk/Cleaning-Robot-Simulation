#include <QApplication>
#include "visualiser.h"
#include "robot.h"
#include "room.h"
#include <iostream>


int main(int argc, char* argv[]) {
    try {
        std::vector <int> pos = { 50,10 };
        std::vector <int> size = { 20, 20 };
        Robot rob{ pos, size };
        std::cout << rob.get_length() << " " << rob.get_width() << ", " << rob.get_coordinates()[0] << " " << rob.get_coordinates()[1] << std::endl;
        std::vector <int> room_size = { 120, 40 };
        Room room(room_size);
        room.setLength(800);
        room.setWidth(600);
        Furniture furniture1("Chair", { 50, 50 }, { 100, 100 });
        room.addFurniture(furniture1);
        Furniture furniture2("Table", { 70, 100 }, { 100, 200 });
        room.addFurniture(furniture2);

        std::cout << "room's length: " << room.getLength() << std::endl;
        std::cout << "room's width: " << room.getWidth() << std::endl;
        std::cout << "furniture in room: " << std::endl;
        for (const auto& item : room.getFurniture()) {
            std::cout << item.getName() << " " << item.getLength() << " " << item.getWidth() << " " << item.get_coordinates()[0] << " " << item.get_coordinates()[1] << std::endl;
        }

        // path
        std::cout << "----------------path-----------------" << std::endl;
        std::vector<std::vector<int>> path = rob.make_path(room);
        for (int i = 0; i < path.size(); i++) {
            std::cout << "{" << path[i][0]  << ", " << path[i][1] << "}, ";
        }
        std::cout << std::endl;

        QApplication app(argc, argv);
        Visualizer visualizer;
        visualizer.setGeometry(100, 100, 800, 600);
        visualizer.setRoom(room);
        visualizer.setRobot(rob);

        visualizer.show();

        return app.exec();

        /*for (const auto& bp : room.get_busy_places())
        {
            std::cout << bp[0] << " " << bp[1] << std::endl;
        }
        std::cout << std::endl;*/
        /*room.deleteFurniture(furniture1);
        for (const auto& item : room.getFurniture()) {
            std::cout << item.getName() << " " << item.getLength() << " " << item.getWidth() << " " << item.get_coordinates()[0] << " " << item.get_coordinates()[1] << std::endl;
        }
        for (const auto& bp : room.get_busy_places())
        {
            std::cout << bp[0] << " " << bp[1] << std::endl;
        }
        std::cout << std::endl;
        room.dust();
        for (const auto& d : room.get_durty_places())
        {
            std::cout << d[0] << " " << d[1] << std::endl;
        }*/
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}