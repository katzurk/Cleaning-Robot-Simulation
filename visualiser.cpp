#include "visualiser.h"

Visualizer::Visualizer(QWidget* parent) : QGraphicsView(parent) {
    scene = new Simulation(this);
    setScene(scene);
}

void Visualizer::setRoom(const Room& room) {
    scene->setRoom(room);
}

void Visualizer::setRobot(const Robot& robot) {
    scene->setRobot(robot);
}

void Visualizer::generatePath() {
    scene->generatePath();
}