#ifndef JANELAPRINCIPAL_H
#define JANELAPRINCIPAL_H

#include <QWidget>

namespace Ui {
class janelaprincipal;
}

class janelaprincipal : public QWidget
{
    Q_OBJECT

public:
    explicit janelaprincipal(QWidget *parent = 0);
    ~janelaprincipal();

private:
    Ui::janelaprincipal *ui;
};

#endif // JANELAPRINCIPAL_H
