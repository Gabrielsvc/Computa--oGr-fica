#ifndef FORMAS_H
#define FORMAS_H
#include "GL/gl.h"

typedef struct p{
    int x,y;
    struct p *prox;

}pontos;


class Formas
{
public:
    Formas();    
    void Bresenham(int*, int*);
    int get_num_pontos(){ return num_pontos;};
    char get_tipo(){return tipo;};
    void set_tipo(char tipo){this->tipo = tipo;}
protected :
    char tipo;
    int num_pontos;
};

#endif // FORMAS_H

class Poligono: public Formas
{
protected :
        bool preenchido;
        int* cor;
};

class Plinha : public Formas
{
protected :
    pontos* cab_lista_pontos;
public:
    pontos* get_lista_pontos(){
        return cab_lista_pontos;
    }

    Plinha(){
        cab_lista_pontos = new pontos();
        num_pontos = 0;
        tipo = 'l';
    }
    void desenha_polilinha();
    void add_ponto_lista(int , int);
    void remove_ponto_lista();

};

class Rect : public Poligono
{
protected:
    int* ponto1;
    int* ponto2;
    int* ponto3;
    int* ponto4;

public:
     Rect(){
        tipo = 'r';
        preenchido = false;
        ponto1 = new int[2];
        ponto2 = new int[2];
        ponto3 = new int[2];
        ponto4 = new int[2];

    }

    void set_rect_default(int*,int*);
    void desenharect(int*, int*, int*, int*);


    int *get_ponto1(){
        return ponto1;
    }
    int *get_ponto2(){
        return ponto2;
    }

    int *get_ponto3(){
        return ponto3;
    }

    int *get_ponto4(){
        return ponto4;
    }

    void set_ponto1(int* ponto_entrada){
        ponto1 = ponto_entrada;
    }
    void set_ponto2(int* ponto_entrada){
        ponto2 = ponto_entrada;
    }

    void set_ponto3(int* ponto_entrada){
        ponto3 = ponto_entrada;
    }

    void set_ponto4(int* ponto_entrada){
        ponto4 = ponto_entrada;
    }
};

class Elipse_Circulo : public Poligono
{
    int* centro;
    int raio1;
    int raio2;

public:
    Elipse_Circulo(char tipo){
        preenchido = false;
        this->tipo = tipo;

        centro = new int[2];
        raio1 = 0;
        centro[0]=0;
        centro[1]=0;
   }
    int get_raio1(){
        return raio1;
    }
    void set_raio1(int raio_entrada1){
        raio1 = raio_entrada1;
    }
    int get_raio2(){
        return raio2;
    }
    void set_raio2(int raio_entrada){
        raio2 = raio_entrada;
    }
    void set_centro(int xc,int yc){
        centro[0] = xc;
        centro[1] = yc;
    }
    int* get_centro(){
        return centro;
    }

    void desenha_circulo(int*,int);
    void desenha_elipse(int,int,int*);
};
