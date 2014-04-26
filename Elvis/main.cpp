#include "janelaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    janelaprincipal w;
    w.show();

    return a.exec();
}
