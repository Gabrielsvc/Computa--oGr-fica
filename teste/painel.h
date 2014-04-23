#ifndef PAINEL_H
#define PAINEL_H

#include <QWidget>

class painel : public QWidget
{
    Q_OBJECT
public:
    explicit painel(QWidget *parent = 0);
    void alteralado(int l);
private:
    int x1,y1,x2,y2;

protected:
    void initialize();
    void paint();
    void resize(int w, int h);

private:
signals:
    
public slots:
    
};

#endif // PAINEL_H
