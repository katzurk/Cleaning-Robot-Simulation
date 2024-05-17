#include "simulation.h"

Simulation::Simulation(QObject* parent) : QGraphicsScene(parent), robotObject(nullptr), currentPositionId(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::moveRobot);
    timer->start(100);
}

void Simulation::setRoom(const Room& room) {
    this->room = room;
    clear(); // Clear the scene
    // Draw the room
    addRect(0, 0, room.getLength(), room.getWidth(), QPen(Qt::black), QBrush(Qt::white));
    // Draw the dust
    for (const auto& dust : room.get_dirty_places())
    {
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(dust[0], dust[1], 1, 1);
        point->setBrush(QBrush(Qt::black));
        addItem(point);
    };
    // Draw the furniture
    for (const auto& furniture : room.getFurniture()) {
        addRect(furniture.get_coordinates()[0], furniture.get_coordinates()[1],
            furniture.getLength(), furniture.getWidth(), QPen(Qt::black), QBrush(Qt::blue));
    }
}

void Simulation::setRobot(const Robot& robot) {
    this->robot = robot;
    // Draw the robot
    robotObject = addRect(robot.get_coordinates()[0], robot.get_coordinates()[1],
        robot.get_length(), robot.get_width(), QPen(Qt::black), QBrush(Qt::red));
}

void Simulation::generatePath(const Room& room) {
    path = robot.make_path(room);
}

void Simulation::moveRobot() {
    if (robotObject == nullptr || path.empty())
        return;

    if (currentPositionId < 0 || currentPositionId >= path.size())
        return;

    const std::vector<int>& currentPosition = path[currentPositionId];
    int x = currentPosition[0];
    int y = currentPosition[1];

    robotObject->setPos(x, y);

    currentPositionId++;
}