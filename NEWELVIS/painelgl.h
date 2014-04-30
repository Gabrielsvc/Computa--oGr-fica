#ifndef PAINELGL_H
#define PAINELGL_H
#include "formas.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include <QWidget>

class PainelGL : public QWidget
{
    //Rect* r;
    Q_OBJECT
public:
    explicit PainelGL(QWidget *parent = NULL);
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

signals:

public slots:
};

#endif // PAINELGL_H
