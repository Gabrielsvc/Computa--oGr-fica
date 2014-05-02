#include "painelnovo.h"
#include <QtGui/QMouseEvent>
#include <stdio.h>

PainelNovo::PainelNovo(QWidget *parent) :
    QGLWidget(parent)
{
    /*r=new Rect();*/
    c = new Elipse_Circulo('c');
    pl = new Plinha();
    ponto_final_mouse = new int[2];
    modo_desenha_ret=false;
    modo_desenha_pll=false;
    ponto_corrente_mouse = new int[2];
    ponto_inicial_mouse = new int[2];
    setMouseTracking(true);
}


void PainelNovo :: resizeGL( int w, int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0,w,0,h, -1.0,1.0);
        glMatrixMode(GL_MODELVIEW);
        glClearColor(1,1,1,0);
}

void PainelNovo :: initializeGL( void )
{

  glDisable(GL_TEXTURE_2D);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_COLOR_MATERIAL);
  glEnable(GL_BLEND);
  glEnable(GL_POLYGON_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(1,1,1,0);

}


void PainelNovo::mousePressEvent(QMouseEvent *event) {
    mouse_pressionado=true;

    if(modo_desenha_ret==true){
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1]=this->height() - event->y();
        //r->set_rect_default(ponto_inicial_mouse,ponto_inicial_mouse);
    }
}

void PainelNovo :: mouseReleaseEvent(QMouseEvent *event){
    if(modo_desenha_ret==true){
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_ret=false;
        //r->set_rect_default(ponto_inicial_mouse,ponto_final_mouse);
    }
    if(modo_desenha_pll){
        ponto_corrente_mouse[0] = event->x();
        ponto_corrente_mouse[1] = this->height() - event->y();

    }
    mouse_pressionado=false;
}
void PainelNovo::mouseMoveEvent(QMouseEvent *event) {

    ponto_corrente_mouse[0]=event->x();
    ponto_corrente_mouse[1]=this->height()-event->y();

    if(mouse_pressionado==true && modo_desenha_ret==true){
        //r->set_rect_default(ponto_inicial_mouse,ponto_corrente_mouse);
        updateGL();
    }

    if(!mouse_pressionado && modo_desenha_pll){
        pl->addppl(ponto_corrente_mouse[0], ponto_corrente_mouse[1]);
        updateGL();

    }
}


void PainelNovo :: paintGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    //r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());

    //glColor3f(1,0,0);
    //Utilização do loop do OpenGL
    /*glBegin(GL_POLYGON);
    glVertex2d(r->get_ponto1()[0],r->get_ponto1()[1]);

    glVertex2d(r->get_ponto2()[0],r->get_ponto2()[1]);

    glVertex2d(r->get_ponto3()[0],r->get_ponto3()[1]);

    glVertex2d(r->get_ponto4()[0],r->get_ponto4()[1]);
    glEnd();
    */
    glFlush();

}
