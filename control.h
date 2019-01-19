#ifndef CONTROL_H
#define CONTROL_H

#include "field.h"
#include <QObject>
#include <QMediaPlayer>

class Field;

class Control : public QObject
{
    Q_OBJECT
private:
    Field *field;
    QMediaPlayer *  music;
public:

    Control(Field * field);

    ~Control();


};

#endif // CONTROL_H
