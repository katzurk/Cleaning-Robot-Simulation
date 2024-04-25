#include "visualiser.h"

Visualizer::Visualizer(QWidget* parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void Visualizer::setRoom(const Room& room) {
    this->room = room;
    scene->clear(); // Clear the scene
    // Draw the room
    scene->addRect(0, 0, room.getLength(), room.getWidth(), QPen(Qt::black), QBrush(Qt::white));
    // Draw the furniture
    for (const auto& furniture : room.getFurniture()) {
        scene->addRect(furniture.get_coordinates()[0], furniture.get_coordinates()[1],
            furniture.getLength(), furniture.getWidth(), QPen(Qt::black), QBrush(Qt::blue));
    }
    update(); // Trigger repaint
}

void Visualizer::setRobot(const Robot& robot) {
    this->robot = robot;
    // Draw the robot
    scene->addRect(robot.get_coordinates()[0], robot.get_coordinates()[1],
        robot.get_length(), robot.get_width(), QPen(Qt::black), QBrush(Qt::red));
    update(); // Trigger repaint
}
