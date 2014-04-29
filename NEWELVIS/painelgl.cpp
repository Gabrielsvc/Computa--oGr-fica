#include "painelgl.h"

PainelGL::PainelGL(QWidget *parent) :
    QWidget(parent)
{
    this->r = new Rect();
}

void PainelGL :: resize( int width, int height )
{
    double menorX = 0,maiorX = 10,menorY = 0,maiorY = 10;
    glViewport(0,0,(GLint)width,(GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2d(-1,1,-1,1);
    if(width > height){
        height = height?height:1;
        double novaLargura = (maiorX - menorX)*width/height;
        double difLargura = novaLargura - (maiorX - menorX);
        menorX = 0.0 - difLargura / 2.0;
        maiorX = 10 + difLargura / 2.0;
    }
    else
    {
        width = width?width:1;
        double novaAltura = (maiorY - menorY)*height/width;
        double difAltura = novaAltura - (maiorY - menorY);
        menorY = 0.0 - difAltura / 2.0;
        maiorY = 10 + difAltura / 2.0;
    }
    //gluOrtho2D(menorX,maiorX,menorY,maiorY);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void PainelGL :: init( void )
{
  glShadeModel(GL_SMOOTH);

  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClearDepth(1.0f);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}


void PainelGL :: redesenha( void )
{
    // Clear the rendering window
    glClearColor( 0.f, 0.f, 0.f, 0.f );
    glClear( GL_COLOR_BUFFER_BIT );
    r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());
    glPushMatrix( );
    glPopMatrix( );

    // Flush the pipeline, swap the buffers
    glFlush();
}


