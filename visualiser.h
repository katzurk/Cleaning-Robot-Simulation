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
#include "room.h"
#include "robot.h"
#include "furniture.h"
#include "simulation.h"

class Visualizer : public QGraphicsView {
    Q_OBJECT

public:
    explicit Visualizer(QWidget* parent = nullptr);
    void setRoom(Room* room);
    void setRobot(const Robot& robot);
    void generatePath(const Room& room);

private:
    Simulation* scene;

};

#endif // VISUALIZER_H