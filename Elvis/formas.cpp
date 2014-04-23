#include "formas.h"

formas::formas()
{

}
rect::desenharect(int *ponto1, int *ponto2){
    glBegin(GL_QUAD);
        glVertex2i(ponto1[0],ponto1[1]);
}
