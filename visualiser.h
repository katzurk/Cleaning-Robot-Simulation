/*
   autor: katarzyna Kanicka
*/
#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include <vector>
#include "room.h"
#include "robot.h"
#include "furniture.h"
#include "simulation.h"

class Visualizer : public QGraphicsView {
    Q_OBJECT

public:
    explicit Visualizer(QWidget* parent = nullptr);
    void setRoom(const Room& room);
    void setRobot(const Robot& robot);
    void generatePath();

private:
    Simulation* scene;

};

#endif // VISUALIZER_H