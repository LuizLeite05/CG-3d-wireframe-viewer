#include "displayfile.h"

DisplayFile::DisplayFile() {}

DisplayFile::~DisplayFile() {
    clear();
}

void DisplayFile::addObject(Object* obj) {
    objects.append(obj);
}

QList<Object*> DisplayFile::getObjects() const {
    return objects;
}

void DisplayFile::clear() {
    qDeleteAll(objects);
    objects.clear();
}