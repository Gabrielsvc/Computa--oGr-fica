#ifndef PAINELNOVO_H
#define PAINELNOVO_H

#include "formas.h"
#include <QGLWidget>

class PainelNovo : public QGLWidget
{
    Q_OBJECT
public:
    Rect *r;
    explicit PainelNovo(QWidget *parent = 0);
protected:
    bool modo_desenha_ret ;
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
        modo_desenha_ret = true;
    }

};

#endif // PAINELNOVO_H