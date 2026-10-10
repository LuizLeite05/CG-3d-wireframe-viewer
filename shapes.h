#ifndef SHAPES_H
#define SHAPES_H

#include "object.h"

class Point : public Object {
public:
    Point(QString name, const QPointF& p);
    void draw(QPainter* painter) override;
};

class Line : public Object {
public:
    Line(QString name, const QPointF& p1, const QPointF& p2);
    void draw(QPainter* painter) override;
};

class Polygon : public Object {
public:
    Polygon(QString name, const QList<QPointF>& polygonPoints);
    void draw(QPainter* painter) override;
};

#endif // SHAPES_H