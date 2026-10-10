#include "drawarea.h"
#include <QPainter>

DrawArea::DrawArea(QWidget *parent) : QFrame(parent), displayFile(nullptr) {
    setStyleSheet("background-color: white;");
}

void DrawArea::setDisplayFile(DisplayFile* df) {
    displayFile = df;
}

void DrawArea::paintEvent(QPaintEvent *event) {
    QFrame::paintEvent(event);

    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 2));
    painter.drawRect(0, 0, width() - 1, height() - 1);

    if (!displayFile) return;

    painter.setPen(QPen(Qt::blue, 2));

    for (Object* obj : displayFile->getObjects()) {
        obj->draw(&painter);
    }
}