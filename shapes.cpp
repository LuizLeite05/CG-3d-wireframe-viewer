#include "shapes.h"

// --- Point ---
Point::Point(QString name, const QPointF& p) : Object(name, POINT) {
    addPoint(p);
}

void Point::draw(QPainter* painter) {
    painter->drawPoint(points.first());
}

// --- Line ---
Line::Line(QString name, const QPointF& p1, const QPointF& p2) : Object(name, LINE) {
    addPoint(p1);
    addPoint(p2);
}

void Line::draw(QPainter* painter) {
    painter->drawLine(points[0], points[1]);
}

// --- Polygon ---
Polygon::Polygon(QString name, const QList<QPointF>& polygonPoints) : Object(name, POLYGON) {
    for (const QPointF& p : polygonPoints) {
        addPoint(p);
    }
}

void Polygon::draw(QPainter* painter) {
    if (points.size() < 3) return;
    painter->drawPolygon(points.data(), points.size());
}