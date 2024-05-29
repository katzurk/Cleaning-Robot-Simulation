#include "simulation.h"

Simulation::Simulation(QObject* parent) : QGraphicsScene(parent), room(nullptr), robotObject(nullptr), currentPositionId(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Simulation::moveRobot);
    connect(timer, &QTimer::timeout, this, &Simulation::cleanRoom);
    connect(timer, &QTimer::timeout, this, &Simulation::updateCats);
    timer->start(100);
}

void Simulation::setRoom(Room* room) {
    this->room = std::move(room);
    clear(); // Clear the scene
    // Draw the room
    addRect(0, 0, room->getLength(), room->getWidth(), QPen(Qt::black), QBrush(Qt::white));
    // Draw the dust
    for (const auto& dust : room->getDirtyPlaces())
    {
        QGraphicsEllipseItem* point = new QGraphicsEllipseItem(dust[0], dust[1], 1, 1);
        point->setBrush(QBrush(Qt::black));
        point->setZValue(1);
        addItem(point);
    };
    // Draw the furniture
    for (const auto& furniture : room->getFurniture()) {
        QGraphicsRectItem* furn = addRect(furniture->get_coordinates()[0], furniture->get_coordinates()[1],
            furniture->getLength(), furniture->getWidth(), QPen(Qt::black), QBrush(Qt::blue));
        furn->setZValue(2);

        if (Cat* cat = dynamic_cast<Cat*>(furniture.get()))
        {
            catItems.emplace_back(cat, std::move(furn));
        }

    }
}

void Simulation::setRobot(const Robot& robot) {
    this->robot = robot;
    // Draw the robot
    robotObject = addRect(robot.get_coordinates()[0], robot.get_coordinates()[1],
        robot.get_length(), robot.get_width(), QPen(Qt::black), QBrush(Qt::red));
}

void Simulation::moveRobot() {
    if (robotObject == nullptr || path.empty())
        return;

    if (currentPositionId < 0 || currentPositionId >= path.size())
        return;

    const std::vector<int>& currentPosition = path[currentPositionId];
    int x = currentPosition[0];
    int y = currentPosition[1];

    int prevPosX;
    int prevPosY;
    if (currentPositionId == 0) {
        prevPosX = 0;
        prevPosY = 0;
    }
    else
    {
        std::vector<int>& prevPosition = path[currentPositionId - 1];
        prevPosX = prevPosition[0];
        prevPosY = prevPosition[1];
    }
    //generatePath
    QGraphicsLineItem* line = new QGraphicsLineItem(prevPosX+ robot.get_width() / 2, prevPosY+ robot.get_length() / 2, x + robot.get_width() / 2, y + robot.get_length() / 2);
    line->setPen(QPen(Qt::green, robot.get_width()));
    line->setZValue(0); // Set path lines to be behind the robot
    addItem(line);

    robotObject->setPos(x, y);
    robotObject->setZValue(1);

    currentPositionId++;
}

void Simulation::generatePath(Room& room) {
    path = robot.make_path(room);
}

void Simulation::cleanRoom() {
    if (!robotObject)
        return;

    QList<QGraphicsItem*> collidingItems = robotObject->collidingItems();
    for (QGraphicsItem* item : collidingItems) {
        if (QGraphicsEllipseItem* ellipse = dynamic_cast<QGraphicsEllipseItem*>(item)) {
            int x = ellipse->x();
            int y = ellipse->y();
            room->cleanDirty({x, y});
            removeItem(ellipse);
            delete ellipse;
        }
    }
}

void Simulation::updateCats() {
    std::cout << currentPositionId << std::endl;
    for (auto& catItemPair : catItems) {
        Cat* cat = catItemPair.first;
        QGraphicsRectItem* catItem = catItemPair.second.get();
        std::vector<std::vector<int>> catPath = cat->getPath();
        if (currentPositionId < 0 || currentPositionId >= catPath.size()) {
            continue;
        }
        std::vector<int> currentPosition = catPath[currentPositionId];
        std::cout << currentPosition[0] << " " << currentPosition[1] << std::endl;
        int x = currentPosition[0];
        int y = currentPosition[1];
        /*catItem->setPos(x, y);*/ //makes the cat appear outside of room (?)

        if (catItem) {
            removeItem(catItem);
        }

        QGraphicsRectItem* newCatItem = addRect(x, y,
            cat->getLength(), cat->getWidth(), QPen(Qt::black), QBrush(Qt::blue));
        newCatItem->setZValue(2);
        // Update the pointer in the catItems map
        catItemPair.second.reset(newCatItem);
    }
}