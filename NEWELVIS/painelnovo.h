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
    bool modo_desenha_ret = false;
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

signals:

public slots:
    void iteracaorect(){
        modo_desenha_ret = true;
    }

};

#endif // PAINELNOVO_H
