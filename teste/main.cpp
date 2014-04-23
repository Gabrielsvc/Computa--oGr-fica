#include <QtGui/QApplication>
#include "janelaprincipal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JanelaPrincipal w;
    w.show();
    /*estudar é nada*/
    return a.exec();
}
