#ifndef PAINEL_H
#define PAINEL_H
#include "rect.h"

#include <QWidget>

class painel : public QWidget
{
    //modificacao recente
    rect r;

    Q_OBJECT
public:
    explicit painel(QWidget *parent = 0);
    void init();
    void resize(int w, int h);
    void redesenha();
signals:

public slots:
    void criarect(void){

        r = new rect();
    }
};



#endif // PAINEL_H
