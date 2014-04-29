#ifndef FORMAS_H
#define FORMAS_H

class Formas
{
public:
    Formas();
protected :
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
    int* pontos;
public:
    int* get_pontos(){
        return pontos;
    }
    void set_pontos(int* pontos_entrada){
        pontos = pontos_entrada;
    }

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
        preenchido = false;

        ponto1 = new int[2];
        ponto1[0]=0;
        ponto1[1]=0;

        ponto2 = new int[2];
        ponto2[0] = 10;
        ponto2[1] = 0;

        ponto3 = new int[2];
        ponto3[0] = 10;
        ponto3[1] = 10;

        ponto4 = new int[2];
        ponto4[0] = 0;
        ponto4[1] = 10;
        this->desenharect(ponto1,ponto2,ponto3,ponto4);
    }

    void desenharect(int*, int*, int*, int*);
    void Bresenham(int*, int*);


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
