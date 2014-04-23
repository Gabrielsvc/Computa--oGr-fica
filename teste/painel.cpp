#include "painel.h"

painel::painel(QWidget *parent) :
    QWidget(parent)
{
}
void initialize(){

}

void paint(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void resize(int w, int h){
    glViewport(0,0,w,h);
}
