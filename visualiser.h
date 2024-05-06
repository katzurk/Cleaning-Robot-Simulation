/*
   autor: katarzyna Kanicka
*/
#ifndef VISUALIZER_H
#define VISUALIZER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <vector>
#include "room.h"
#include "robot.h"
#include "furniture.h"

class Visualizer : public QGraphicsView {
    Q_OBJECT

public:
    explicit Visualizer(QWidget* parent = nullptr);
    void setRoom(const Room& room);
    void setRobot(const Robot& robot);

private:
    QGraphicsScene* scene;
    Room room;
    Robot robot;
    QGraphicsRectItem* robotObject;
    QTimer* timer;
    int currentPosition;
    std::vector<std::vector<int>> path;

public slots:
    void moveToNextPosition();
};

#endif // VISUALIZER_H