#ifndef OBJECT_H
#define OBJECT_H

#include <QString>
#include <QList>
#include <QPointF>
#include <QPainter>
#include <QTransform>

enum TypeObject { POINT, LINE, POLYGON };

class Object
{
protected:
    QString name;
    TypeObject type;
    QList<QPointF> points;

public:
    Object(QString name, TypeObject type);
    virtual ~Object() {}

    QString getName() const;
    TypeObject getType() const;
    QList<QPointF> getPoints() const;
    void addPoint(const QPointF& point);

    virtual void draw(QPainter * painter) = 0;

    void transform(const QTransform& matrix);
    QPointF getCenter() const;

    void translate(double dx, double dy);
    void scale(double sx, double sy);
    void rotate(double angle, const QPointF& referencePoint);
};

#endif // OBJECT_H