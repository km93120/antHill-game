
#include <QApplication>
#include "field.h"





int main(int argc, char *argv[])
{


    QApplication a(argc, argv);
    Field * field = new Field();
    Control control(field);
    field->show();


    return a.exec();
}
