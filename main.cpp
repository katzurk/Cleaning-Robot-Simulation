#include <QApplication>
#include "visualiser.h"
#include "robot.h"
#include "room.h"
#include "furniture_generator.h"
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


        // generate random furniture
        FurnitureGenerator generator;
        int n = 3; // number of furniture to generate
        generator.setSizeRange(20, 70);
        generator.setCoordRange(50, 200);

        while (room.getFurniture().size() != n) {
            Furniture furniture = generator.createRandomFurniture();
            int length = furniture.getLength();
            int width = furniture.getWidth();
                if (room.is_place_free_for_object(furniture.get_coordinates(), {length, width})) {
                    room.addFurniture(furniture);
            }
        }
        // random furniture placement can make the program sometimes loop longer, sometimes shorter

        room.dust();

        std::cout << "room's length: " << room.getLength() << std::endl;
        std::cout << "room's width: " << room.getWidth() << std::endl;
        std::cout << "furniture in room: " << std::endl;
        for (const auto& item : room.getFurniture()) {
            std::cout << item.getName() << " " << item.getLength() << " " << item.getWidth() << " " << item.get_coordinates()[0] << " " << item.get_coordinates()[1] << std::endl;
        }

        QApplication app(argc, argv);
        Visualizer visualizer;
        visualizer.setGeometry(100, 100, 800, 600);
        visualizer.setRoom(room);
        visualizer.setRobot(rob);
        visualizer.generatePath(room);

        visualizer.show();

        return app.exec();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}