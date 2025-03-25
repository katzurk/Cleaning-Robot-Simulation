/*
   autor: Katarzyna Kanicka
*/
#ifndef SIMULATION_H
#define SIMULATION_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <vector>
#include "../models/room.h"
#include "../models/robot.h"
#include "../models/furniture.h"
#include "../models/cat.h"

class Simulation : public QGraphicsScene {
    Q_OBJECT

public:
    explicit Simulation(QObject* parent = nullptr);
    void setRoom(Room* room);
    void setRobot(const Robot& robot);
    void generatePath(Room& room);
    void moveRobot();
    void cleanRoom();
    void updateCats();

private:
    Room* room;
    Robot robot;
    QGraphicsRectItem* robotObject;
    QTimer* timer;
    int currentPositionId;
    std::vector<std::vector<int>> path;
    std::vector<std::pair<Cat*, std::unique_ptr<QGraphicsRectItem>>> catItems;
};

#endif // SIMULATION_H