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
#include "room.h"
#include "robot.h"
#include "furniture.h"
#include "cat.h"

class Simulation : public QGraphicsScene {
    Q_OBJECT

public:
    explicit Simulation(QObject* parent = nullptr);
    void setRoom(Room* room);
    void setRobot(const Robot& robot);
    void generatePath(Room& room);
    void moveRobot();
    void cleanRoom();

private:
    Room* room;
    Robot robot;
    QGraphicsRectItem* robotObject;
    QTimer* timer;
    int currentPositionId;
    std::vector<std::vector<int>> path;
};

#endif // SIMULATION_H