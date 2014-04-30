#include "painelgl.h"
#include "stdio.h"

PainelGL::PainelGL(QWidget *parent) :
    QWidget(parent)
{
    //this->r = new Rect();
    //setFormat(DoubleBuffer|DepthBuffer);
}

void PainelGL :: resizeGL( int w, int h )
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,0,h,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0,0,0,0);
}
void PainelGL :: initializeGL( void )
{
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_COLOR_MATERIAL);
  glEnable(GL_BLEND);
  glEnable(GL_POLYGON_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0,0,0,0);
}


void PainelGL :: paintGL( void )
{
    // Clear the rendering window

    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f(1,0,0);

    //r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());

    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,500);
    glVertex2f(100,100);
    glEnd();
    // Flush the pipeline, swap the buffers
    glFlush();
}


