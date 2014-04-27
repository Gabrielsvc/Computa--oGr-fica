#ifndef PAINEL_H
#define PAINEL_H

#include <QWidget>

class painel : public QWidget
{
    Q_OBJECT
public:
    explicit painel(QWidget *parent = 0);
    void init();
    void resize(int w, int h);
    void redesenha();
signals:

public slots:
    criarect();
};



#endif // PAINEL_H
