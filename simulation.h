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

class Simulation : public QGraphicsScene {
    Q_OBJECT

public:
    explicit Simulation(QObject* parent = nullptr);
    void setRoom(const Room& room);
    void setRobot(const Robot& robot);
    void generatePath(const Room& room);
    void moveRobot();

private:
    Room room;
    Robot robot;
    QGraphicsRectItem* robotObject;
    QTimer* timer;
    int currentPositionId;
    std::vector<std::vector<int>> path;
};

#endif // SIMULATION_H