#include "visualiser.h"

Visualizer::Visualizer(QWidget* parent) : QGraphicsView(parent) {
    scene = new Simulation(this);
    setScene(scene);
}

void Visualizer::setRoom(Room* room) {
    scene->setRoom(room);
}

void Visualizer::setRobot(const Robot& robot) {
    scene->setRobot(robot);
}

void Visualizer::generatePath(const Room& room) {
    scene->generatePath(room);
}