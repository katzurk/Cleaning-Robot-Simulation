/*
   autor: Katarzyna Kanicka
*/
#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <vector>
#include "../models/room.h"
#include "../models/robot.h"
#include "../models/furniture.h"
#include "../models/cat.h"
#include "simulation.h"

class Visualizer : public QGraphicsView {
    Q_OBJECT

public:
    explicit Visualizer(QWidget* parent = nullptr);
    void setRoom(Room* room);
    void setRobot(const Robot& robot);
    void generatePath(Room& room);

private:
    Simulation* scene;

};

#endif // VISUALIZER_H