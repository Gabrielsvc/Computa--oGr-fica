#include "painelnovo.h"
#include <QtGui/QMouseEvent>

PainelNovo::PainelNovo(QWidget *parent) :
    QGLWidget(parent)
{
    r=new Rect();
    ponto_final_mouse = new int[2];
    modo_desenha_ret=false;
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
        glClearColor(0,0,0,0);
}

void PainelNovo :: initializeGL( void )
{
  glDisable(GL_TEXTURE_2D);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_COLOR_MATERIAL);
  glEnable(GL_BLEND);
  glEnable(GL_POLYGON_SMOOTH);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glClearColor(0,0,0,0);
}


void PainelNovo::mousePressEvent(QMouseEvent *event) {
    mouse_pressionado=true;

    if(modo_desenha_ret==true){
        ponto_inicial_mouse[0]=event->x();
        ponto_inicial_mouse[1]=event->y();
        r->set_rect_default(ponto_inicial_mouse,ponto_inicial_mouse);
    }
}
void PainelNovo :: mouseReleaseEvent(QMouseEvent *event){
    if(modo_desenha_ret==true){
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = event->y();
        modo_desenha_ret=false;
        r->set_rect_default(ponto_inicial_mouse,ponto_final_mouse);
    }
    mouse_pressionado=false;
}
void PainelNovo::mouseMoveEvent(QMouseEvent *event) {

    ponto_corrente_mouse[0]=event->x();
    ponto_corrente_mouse[1]=event->y();

    if(mouse_pressionado==true && modo_desenha_ret==true){
        printf("entrou\n");
        r->set_rect_default(ponto_inicial_mouse,ponto_corrente_mouse);
        updateGL();
    }
    //printf("%d\t%d\n",ponto_corrente_mouse[0],ponto_corrente_mouse[1]);
}


void PainelNovo :: paintGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    //r = new Rect();
    r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());
    //r->desenharect_default(ponto_inicial_mouse,ponto_corrente_mouse);

    glColor3f(1,0,0);

    /*glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(100,500);
    glVertex2f(100,100);
    glEnd();*/
    // Flush the pipeline, swap the buffers
    glFlush();

}
