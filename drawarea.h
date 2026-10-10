#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QFrame>
#include "displayfile.h"

class DrawArea : public QFrame {
    Q_OBJECT

private:
    DisplayFile* displayFile;

public:
    explicit DrawArea(QWidget *parent = nullptr);
    void setDisplayFile(DisplayFile* df);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // DRAWAREA_H