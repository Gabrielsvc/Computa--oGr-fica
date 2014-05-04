#include "painelnovo.h"
#include <QtGui/QMouseEvent>
#include <stdio.h>

PainelNovo::PainelNovo(QWidget *parent) :
    QGLWidget(parent)
{
    p=new Elipse_Circulo('c');
    r=new Rect();
    c = new Elipse_Circulo('c');
    pl = new Plinha();

    e = new Elipse_Circulo('e');

    ponto_final_mouse = new int[2];
    modo_desenha_ret=false;
    modo_desenha_pll=false;
    modo_desenha_circ=false;
    modo_desenha_elip=false;
    modo_desenha_ponto=false;
    ponto_corrente_mouse = new int[2];
    ponto_inicial_mouse = new int[2];

    setMouseTracking(true);
    mouse_pressionado = false;
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

    if(modo_desenha_ret){
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();
        r->set_rect_default(ponto_inicial_mouse,ponto_inicial_mouse);
    }

    if(modo_desenha_circ){
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1]=this->height() - event->y();
        c->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);
        c->set_raio1(1);
    }
    if(modo_desenha_elip){
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();

        e->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);
        e->set_raio1(1);
        e->set_raio2(1);
    }
    if( modo_desenha_pll && event->button()==Qt::LeftButton){

        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();
        ponto_corrente_mouse[0]=ponto_inicial_mouse[0];
        ponto_corrente_mouse[1]=ponto_inicial_mouse[1];
    }
    if(modo_desenha_pll && event->button()==Qt::RightButton){
        modo_desenha_pll=false;

    }
    if(modo_desenha_ponto && event->button()==Qt::LeftButton){
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1]=this->height() - event->y();
        p->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);
        p->set_raio1(1);
        updateGL();
    }
}

void PainelNovo :: mouseReleaseEvent(QMouseEvent *event){

    if(modo_desenha_ret==true){
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_ret=false;
        r->set_rect_default(ponto_inicial_mouse,ponto_final_mouse);
    }
    if(modo_desenha_pll){
        pl->add_ponto_lista(ponto_corrente_mouse[0], ponto_corrente_mouse[1]);

    }

    if(modo_desenha_circ){
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_circ=false;
    }
    if(modo_desenha_elip){
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_elip=false;
    }
    mouse_pressionado=false;
}
void PainelNovo::mouseMoveEvent(QMouseEvent *event) {

    ponto_corrente_mouse[0]=event->x();
    ponto_corrente_mouse[1]=this->height()-event->y();

    if(mouse_pressionado==true && modo_desenha_ret==true){

        r->set_rect_default(ponto_inicial_mouse,ponto_corrente_mouse);
        updateGL();
    }

    if(!mouse_pressionado && modo_desenha_pll && pl->get_num_pontos()!=0){

        pl->add_ponto_lista(ponto_corrente_mouse[0],ponto_corrente_mouse[1]);
        updateGL();
        pl->remove_ponto_lista();
    }

    if(mouse_pressionado && modo_desenha_circ){

        int r_aux = (int)sqrt((ponto_corrente_mouse[0]-c->get_centro()[0])*
                              (ponto_corrente_mouse[0]-c->get_centro()[0])+
                              (ponto_corrente_mouse[1]-c->get_centro()[1])*
                              (ponto_corrente_mouse[1]-c->get_centro()[1]));

        c->set_raio1(r_aux);

        r->set_rect_default(ponto_inicial_mouse,ponto_corrente_mouse);

        updateGL();

    }
    if(mouse_pressionado && modo_desenha_elip){

        e->set_raio1((int)abs(ponto_corrente_mouse[0]-e->get_centro()[0]));
        e->set_raio2((int)abs(ponto_corrente_mouse[1]-e->get_centro()[1]));

        updateGL();

    }
}



void PainelNovo :: paintGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    //r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());

    //c->desenha_circulo(c->get_centro(),c->get_raio1());

    pl->desenha_polilinha();
    //p->desenha_circulo(p->get_centro(),p->get_raio1());

    //e->desenha_elipse(e->get_raio1(),e->get_raio2(),e->get_centro());

    glFlush();

}
