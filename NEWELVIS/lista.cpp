#include "lista.h"

Lista::Lista()
{
}
void Lista :: add_figura(Formas* f){
    figura* aux;
    Formas* newForma;

    aux = this->cab;

    newForma = new pontos();
    newForma->x = x;
    newForma->y = y;
    newForma->prox = NULL;

    while(aux->prox != NULL)
        aux=aux->prox;

    aux->prox = newPoint;
    this->num_pontos += 1;
}
