#include "simulation.h"

Simulation::Simulation(QObject* parent) : QGraphicsScene(parent), robotObject(nullptr) {
    
}

void Simulation::setRoom(const Room& room) {
    this->room = room;
    clear(); // Clear the scene
    // Draw the room
    addRect(0, 0, room.getLength(), room.getWidth(), QPen(Qt::black), QBrush(Qt::white));
    // Draw the furniture
    for (const auto& furniture : room.getFurniture()) {
        addRect(furniture.get_coordinates()[0], furniture.get_coordinates()[1],
            furniture.getLength(), furniture.getWidth(), QPen(Qt::black), QBrush(Qt::blue));
    }
}

void Simulation::setRobot(const Robot& robot) {
    this->robot = robot;
    // Draw the robot
    robotObject = new QGraphicsRectItem(robot.get_coordinates()[0], robot.get_coordinates()[1],
        robot.get_length(), robot.get_width());
    robotObject->setPen(QPen(Qt::black));
    robotObject->setBrush(QBrush(Qt::red));
    addItem(robotObject);
}
