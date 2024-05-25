#include <QApplication>
#include "visualiser.h"
#include "robot.h"
#include "room.h"
#include <iostream>


int main(int argc, char* argv[]) {
    try {
        std::vector <int> pos = { 0,0 };  // nessesary strating pos {0, 0}
        std::vector <int> size = { 20, 20 };
        Robot rob{ pos, size };
        std::cout << rob.get_length() << " " << rob.get_width() << ", " << rob.get_coordinates()[0] << " " << rob.get_coordinates()[1] << std::endl;
        std::vector <int> room_size = { 1200, 400 };
        Room room(room_size);
        room.setLength(190);
        room.setWidth(210);
        // Furniture furniture1("Chair mid", { 50, 50 }, { 30, 30 });   //TODO: y %robot.size[1] != 0 how to handle tops?
        auto furniture1 = std::make_unique<Furniture>("Chair mid", std::vector<int>{ 50, 50 }, std::vector<int>{ 40, 40 });
        room.addFurniture(std::move(furniture1));
        auto furnitureE = std::make_unique<Furniture>("Chair to E wall", std::vector<int>{ 50, 80 }, std::vector<int>{ 140, 70 });
        room.addFurniture(std::move(furnitureE));
        auto furnitureN = std::make_unique<Furniture>("Chair to N wall", std::vector<int>{ 30, 30 }, std::vector<int>{ 145, 0 });
        room.addFurniture(std::move(furnitureN));
        auto furnitureW = std::make_unique<Furniture>("Chair to W wall", std::vector<int>{ 37, 37 }, std::vector<int>{ 0, 50 });
        room.addFurniture(std::move(furnitureW));
        // Furniture furnitureS("Chair to S wall", { 50, 50 }, { 50, 180 });
        auto furnitureS = std::make_unique<Furniture>("Chair to S wall", std::vector<int>{ 50, 50 }, std::vector<int>{ 50, 155 });
        room.addFurniture(std::move(furnitureS));

        // Furniture furniture2("Table", { 70, 100 }, { 100, 200 });
        // room.addFurniture(furniture2);
        room.dust();

        std::cout << "room's length: " << room.getLength() << std::endl;
        std::cout << "room's width: " << room.getWidth() << std::endl;
        std::cout << "furniture in room: " << std::endl;
        for (const auto& item : room.getFurniture()) {
            std::cout << item->getName() << " " << item->getLength() << " " << item->getWidth() << " " << item->get_coordinates()[0] << " " << item->get_coordinates()[1] << std::endl;
        }

        // path
        // std::cout << "----------------path-----------------" << std::endl;
        // std::vector<std::vector<int>> path = rob.make_path(room);
        // for (int i = 0; i < path.size(); i++) {
        //     std::cout << "{" << path[i][0]  << ", " << path[i][1] << "}, ";
        // }
        // std::cout << std::endl;

        QApplication app(argc, argv);
        Visualizer visualizer;
        visualizer.setGeometry(100, 100, 800, 600);
        visualizer.setRoom(&room);
        visualizer.setRobot(rob);
        visualizer.generatePath(room);

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