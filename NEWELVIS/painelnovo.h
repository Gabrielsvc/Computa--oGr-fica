#ifndef PAINELNOVO_H
#define PAINELNOVO_H

#include <math.h>
#include <stdio.h>
#include <cmath>
#include "formas.h"
#include <QGLWidget>

class PainelNovo : public QGLWidget
{
    Q_OBJECT
public:
    figura *list_fig;
    char tipo_atual;
    /*
    Rect *r;
    Elipse_Circulo* p;
    Elipse_Circulo* c;
    Elipse_Circulo* e;
    Plinha *pl;
    */
    explicit PainelNovo(QWidget *parent = 0);
protected:
    bool modo_desenha_elip;
    bool modo_desenha_circ;
    bool modo_desenha_ret;
    bool modo_desenha_pll;
    bool modo_desenha_ponto;
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
signals:

public slots:
    void iteracaorect(){
        tipo_atual =
        modo_desenha_ret = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_pll = false;
        modo_desenha_ponto = true;
    }
    void iteracaopll(){
        modo_desenha_pll = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
        modo_desenha_ponto = false;
    }
    void iteracaocirc(){
        modo_desenha_circ = true;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
        modo_desenha_pll = false;
        modo_desenha_ponto = false;
    }
    void iteracaoelip(){
        modo_desenha_elip = true;
        modo_desenha_circ = false;
        modo_desenha_ret=false;
        modo_desenha_pll = false;
        modo_desenha_ponto=false;
    }
    void iteracaoponto(){
        modo_desenha_elip = false;
        modo_desenha_circ = false;
        modo_desenha_ret=false;
        modo_desenha_pll = false;
        modo_desenha_ponto = true;
    }
};

#endif // PAINELNOVO_H
