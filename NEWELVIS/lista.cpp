#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

/*Lista::Lista()
{
}*/
void Lista :: add_figura(Formas* f){
   figura* aux = this->cab;
   figura* newFigura;

   newFigura = new figura();
   newFigura->forma = f;
   newFigura->prox = NULL;

    while(aux->prox != NULL){
        aux=aux->prox;
    }
    aux->prox = newFigura;
    this->num_figuras += 1;
}

void Lista :: remove_figura(){
    figura *aux1,*aux2;

    aux1 = this->cab;
    aux2 = aux1->prox;

    if(aux2 != NULL){
        while(aux2 -> prox != NULL){
            aux1 = aux2;
            aux2 = aux2->prox;
        }
        delete(aux2);
        aux1->prox = NULL;
    }
    else{
        printf("Underflow\n");
        exit(0);
    }
    this->num_figuras--;
}

void Lista :: desenha_lista(){

    figura* aux = this->cab->prox;
    Rect* r;
    Elipse_Circulo *c,*p,*e;
    Plinha *pl;

    while(aux != NULL){

         if(aux->forma->get_tipo()=='r'){

            r = static_cast <Rect*> (aux->forma);
            r->desenharect(r->get_ponto1(),r->get_ponto2(),r->get_ponto3(),r->get_ponto4());
         }
         else if(aux->forma->get_tipo()=='c'){

             c = static_cast <Elipse_Circulo*> (aux->forma);
             c->desenha_circulo(c->get_centro(),c->get_raio1());
         }
         else if(aux->forma->get_tipo()=='p'){

             p = static_cast <Elipse_Circulo*> (aux->forma);
             p->desenha_circulo(p->get_centro(),p->get_raio1());
         }
         else if(aux->forma->get_tipo()=='e'){

             e = static_cast <Elipse_Circulo*> (aux->forma);
             e->desenha_elipse(e->get_raio1(),e->get_raio2(),e->get_centro());
         }
         else if(aux->forma->get_tipo()=='l'){

             pl = static_cast <Plinha*> (aux->forma);
             pl->desenha_polilinha();
         }

         aux=aux->prox;
    }
}
