#ifndef PAINELNOVO_H
#define PAINELNOVO_H

#include "lista.h"
#include <math.h>
#include <stdio.h>
#include <cmath>
#include <QGLWidget>
#include <iostream>
#include <QtGui/QKeyEvent>

class PainelNovo : public QGLWidget
{
    Q_OBJECT
public:

    Rect* ret_aux;
    Plinha* poli_aux;
    Elipse_Circulo* circ_aux;
    Elipse_Circulo* elipse_aux;
    Elipse_Circulo* ponto_aux;

    char tipo_atual;
    Lista* list;


    explicit PainelNovo(QWidget *parent = 0);
protected:
    bool desenha_auxiliar;
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
    void keyPressEvent(QKeyEvent *eventKey);
signals:

public slots:
    void iteracaorect(){
        tipo_atual = 'r';
        modo_desenha_ret = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_pll = false;
        modo_desenha_ponto = false;
    }
    void iteracaopll(){
        tipo_atual = 'l';
        modo_desenha_pll = true;
        modo_desenha_circ = false;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
        modo_desenha_ponto = false;
    }
    void iteracaocirc(){
        tipo_atual = 'c';
        modo_desenha_circ = true;
        modo_desenha_elip = false;
        modo_desenha_ret = false;
        modo_desenha_pll = false;
        modo_desenha_ponto = false;
    }
    void iteracaoelip(){
        tipo_atual = 'e';
        modo_desenha_elip = true;
        modo_desenha_circ = false;
        modo_desenha_ret=false;
        modo_desenha_pll = false;
        modo_desenha_ponto=false;
    }
    void iteracaoponto(){
        tipo_atual = 'p';
        modo_desenha_elip = false;
        modo_desenha_circ = false;
        modo_desenha_ret=false;
        modo_desenha_pll = false;
        modo_desenha_ponto = true;
    }
};

#endif // PAINELNOVO_H
