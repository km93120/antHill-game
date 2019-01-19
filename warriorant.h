#ifndef WARRIORANT_H
#define WARRIORANT_H

#include <QObject>
#include "Ant.h"
#include "field.h"
#include "enemy.h"

class WarriorAnt : public Ant
{
    Q_OBJECT
public:
    WarriorAnt(Field * field);

public slots:
     void attack();


};

#endif // WARRIORANT_H
