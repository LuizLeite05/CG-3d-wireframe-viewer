#include "object.h"

Object::Object(QString name, TypeObject type) : name(name), type(type) {}

QString Object::getName() const {return name;}
TypeObject Object::getType() const {return type;}
QList<QPointF> Object::getPoints() const {return points;}

void Object::addPoint(const QPointF& point){
    points.append(point);
}
// Método central que multiplica a matriz pelos pontos do objeto
void Object::transform(const QTransform& matrix) {
    for (int i = 0; i < points.size(); ++i) {
        // O método map() do QTransform aplica a matriz ao ponto (matemática de coordenadas homogéneas)
        points[i] = matrix.map(points[i]);
    }
}

// Calcula o centro geométrico do objeto (necessário para a escala)
QPointF Object::getCenter() const {
    if (points.isEmpty()) return QPointF(0, 0);

    double cx = 0, cy = 0;
    for (const QPointF& p : points) {
        cx += p.x();
        cy += p.y();
    }
    return QPointF(cx / points.size(), cy / points.size());
}

// a) Translação de objetos da cena
void Object::translate(double dx, double dy) {
    QTransform t;
    t.translate(dx, dy); // Matriz de translação
    transform(t);
}

// b) Escala em torno do centro geométrico do objeto
void Object::scale(double sx, double sy) {
    QPointF center = getCenter();

    QTransform t;
    // Composição de matrizes (a ordem das chamadas no Qt é inversa, lida de baixo para cima)
    t.translate(center.x(), center.y());    // 3. Retorna ao centro original
    t.scale(sx, sy);                        // 2. Aplica a escala
    t.translate(-center.x(), -center.y());  // 1. Move para a origem

    transform(t);
}

// c) Rotação em torno de um ponto escolhido pelo utilizador
void Object::rotate(double angle, const QPointF& referencePoint) {
    QTransform t;
    // Composição de matrizes para rotação
    t.translate(referencePoint.x(), referencePoint.y());
    t.rotate(angle); // O QTransform espera o ângulo em graus
    t.translate(-referencePoint.x(), -referencePoint.y());

    transform(t);
}