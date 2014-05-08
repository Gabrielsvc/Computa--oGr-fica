#include "painelnovo.h"
#include <QtGui/QMouseEvent>
#include <QtGui/QKeyEvent>
#include <stdio.h>

PainelNovo::PainelNovo(QWidget *parent) :
    QGLWidget(parent)
{
    ret_aux = new Rect();
    poli_aux = new Plinha();
    list = new Lista();
    circ_aux= new Elipse_Circulo('c');
    elipse_aux = new Elipse_Circulo('e');
    ponto_aux = new Elipse_Circulo('p');

    desenha_auxiliar = false;
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
void PainelNovo::keyPressEvent(QKeyEvent *eventKey){
    // Por que não entra aqui ?!
    if(modo_desenha_pll){
        modo_desenha_pll = false;
        delete(poli_aux);
        poli_aux = new Plinha();
        updateGL();
    }
}

void PainelNovo::mousePressEvent(QMouseEvent *event) {

    mouse_pressionado=true;

    if(modo_desenha_ret){

        ret_aux = new Rect();
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();
        ret_aux->set_rect_default(ponto_inicial_mouse,ponto_inicial_mouse);
    }

    if(modo_desenha_circ){

        circ_aux = new Elipse_Circulo('c');
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1]=this->height() - event->y();
        circ_aux->set_raio1(1);
        circ_aux->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);

    }

    if(modo_desenha_elip){
        elipse_aux = new Elipse_Circulo('e');
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();

        elipse_aux->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);
        elipse_aux->set_raio1(1);
        elipse_aux->set_raio2(1);
    }

    if( modo_desenha_pll && event->button()==Qt::LeftButton){

        ponto_corrente_mouse[0] = event->x();
        ponto_corrente_mouse[1] = this->height() - event->y();
        poli_aux->add_ponto_lista(ponto_corrente_mouse[0],ponto_corrente_mouse[1]);

    }

    if(modo_desenha_pll && event->button()==Qt::MidButton){

        poli_aux->add_ponto_lista(ponto_corrente_mouse[0],ponto_corrente_mouse[1]);
        list->add_figura(poli_aux);
        poli_aux = new Plinha();
        modo_desenha_pll=false;
    }

    if(modo_desenha_pll && event->button() == Qt::RightButton ){
            //delete(poli_aux);
            modo_desenha_pll = false;
            delete(poli_aux);
            poli_aux = new Plinha();
            updateGL();
    }

    if(modo_desenha_ponto && event->button()==Qt::LeftButton){

        ponto_aux = new Elipse_Circulo('p');
        ponto_inicial_mouse[0] = event->x();
        ponto_inicial_mouse[1] = this->height() - event->y();
        ponto_aux->set_centro(ponto_inicial_mouse[0],ponto_inicial_mouse[1]);
        ponto_aux->set_raio1(1);
        list->add_figura(ponto_aux);
        updateGL();
        modo_desenha_ponto = false;
    }
}

void PainelNovo :: mouseReleaseEvent(QMouseEvent *event){

    mouse_pressionado=false;

    if(modo_desenha_ret==true){

        modo_desenha_ret=false;
        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        ret_aux->set_rect_default(ponto_inicial_mouse,ponto_final_mouse);

        list->add_figura(ret_aux);
    }

    if(modo_desenha_circ){

        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_circ=false;
        list->add_figura(circ_aux);
    }
    if(modo_desenha_elip){

        ponto_final_mouse[0] = event->x();
        ponto_final_mouse[1] = this->height()-event->y();
        modo_desenha_elip=false;
        list->add_figura(elipse_aux);
    }
}
void PainelNovo::mouseMoveEvent(QMouseEvent *event) {

    ponto_corrente_mouse[0]=event->x();
    ponto_corrente_mouse[1]=this->height()-event->y();

    if(mouse_pressionado && modo_desenha_ret){

        ret_aux->set_rect_default(ponto_inicial_mouse,ponto_corrente_mouse);
        list->add_figura(ret_aux);
        updateGL();
        list->remove_figura();
    }

    if(modo_desenha_pll && !mouse_pressionado && poli_aux->get_num_pontos()!=0){

        poli_aux->add_ponto_lista(ponto_corrente_mouse[0],ponto_corrente_mouse[1]);

        //list->add_figura(poli_aux);
        desenha_auxiliar = true;
        updateGL();
        desenha_auxiliar = false;
        poli_aux->remove_ponto_lista();
    }

    if(mouse_pressionado && modo_desenha_circ){

        int r_aux = (int)sqrt((ponto_corrente_mouse[0]-circ_aux->get_centro()[0])*
                              (ponto_corrente_mouse[0]-circ_aux->get_centro()[0])+
                              (ponto_corrente_mouse[1]-circ_aux->get_centro()[1])*
                              (ponto_corrente_mouse[1]-circ_aux->get_centro()[1]));

        circ_aux->set_raio1(r_aux);
        list->add_figura(circ_aux);
        updateGL();
        list->remove_figura();
    }
    if(mouse_pressionado && modo_desenha_elip){

        elipse_aux->set_raio1((int)abs(ponto_corrente_mouse[0]-elipse_aux->get_centro()[0]));
        elipse_aux->set_raio2((int)abs(ponto_corrente_mouse[1]-elipse_aux->get_centro()[1]));

        list->add_figura(elipse_aux);
        updateGL();
        list->remove_figura();
    }
}



void PainelNovo :: paintGL( void )
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    if(desenha_auxiliar){
        poli_aux->desenha_polilinha();
    }
    list->desenha_lista();

    glFlush();

}
