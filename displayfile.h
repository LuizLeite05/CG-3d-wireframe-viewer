#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <QList>
#include "object.h"

class DisplayFile {
private:
    QList<Object*> objects;

public:
    DisplayFile();
    ~DisplayFile();

    void addObject(Object* obj);
    QList<Object*> getObjects() const;
    void clear();
};

#endif // DISPLAYFILE_H