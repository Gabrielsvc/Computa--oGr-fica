#ifndef LISTA_H
#define LISTA_H
#include "formas.h"

typedef struct f{
    struct f *prox;
    Formas *forma;

}figura;

class Lista
{
public:
    figura* cab;
    int num_figuras;

    Lista(){
        num_figuras = 0;
        cab = new figura();
    }
    int get_num_figuras(){return num_figuras;};
    void add_figura(Formas*);
    void remove_figura();
    void desenha_lista();
    figura* get_cabeca(){
        return cab;
    }

};



#endif // LISTA_H
