#ifndef PAINELNOVO_H
#define PAINELNOVO_H

#include <math.h>
#include <cmath>
#include "formas.h"
#include <QGLWidget>

class PainelNovo : public QGLWidget
{
    Q_OBJECT
public:
    Rect *r;
    Elipse_Circulo* c;
    Elipse_Circulo* e;
    Plinha *pl;

    explicit PainelNovo(QWidget *parent = 0);
protected:
    bool modo_desenha_elip;
    bool modo_desenha_circ;
    bool modo_desenha_ret;
    bool modo_desenha_pll;
    bool mouse_pressionado;
    int* ponto_inicial_mouse;
    int* ponto_final_mouse;
    int* ponto_corrente_mouse;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseLeftButton(QMouseEvent* event);
signals:

public slots:
    void iteracaorect(){
        modo_desenha_ret = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_pll = false;
    }
    void iteracaopll(){
        modo_desenha_pll = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
    }
    void iteracaocirc(){
        modo_desenha_circ = true;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
        modo_desenha_pll = false;
    }
    void iteracaoelip(){
        modo_desenha_elip = true;
        modo_desenha_circ = false;
        modo_desenha_ret=false;
        modo_desenha_pll = false;
    }
};

#endif // PAINELNOVO_H
