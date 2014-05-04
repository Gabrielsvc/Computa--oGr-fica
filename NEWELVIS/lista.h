#ifndef LISTA_H
#define LISTA_H
#include <formas.h>

typedef struct f{
    struct f *prox;
    Formas *forma;

}figura;

class Lista
{
public:
    figura* cab;
    Lista(){
        cab = new figura();
    }
    void add_figura(Formas*);
    void remove_figura();
};



#endif // LISTA_H
