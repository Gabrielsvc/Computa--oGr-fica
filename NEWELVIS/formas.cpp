#include "formas.h"
#include "cmath"
#include "stdlib.h"
#include <stdio.h>


Formas::Formas()
{
}

void Rect :: set_rect_default(int* p_a,int* p_b){
    int *p_c,*p_d;

    p_c = new int[2];
    p_d = new int[2];

    if(p_a[0] < p_b[0]){
        p_c[0] = p_b[0];
        p_c[1] = p_a[1];
        p_d[0] = p_a[0];
        p_d[1] = p_b[1];
    }
    else{
        p_c[0] = p_a[0];
        p_c[1] = p_b[1];
        p_d[0] = p_b[0];
        p_d[1] = p_a[1];
    }
    this->ponto1=p_a;
    this->ponto2=p_c;
    this->ponto3=p_b;
    this->ponto4=p_d;

    /*delete(p_c);
    delete(p_d);*/
}
void Plinha :: addppl(int x1, int y1){
    ponto *aux = new ponto();
    aux = pontos;
    ponto *aux2 = new ponto();
    while(pontos->prox != NULL){
        pontos = pontos->prox;
    }
    pontos->prox = aux2;
    pontos->prox->x = x1;
    pontos->prox->y = y1;
    pontos = aux;
}

void Plinha :: desenhappl(ponto *pontos){
    while(pontos->prox != NULL){
        int ponto1[2],ponto2[2];
        ponto1[0]= pontos->x;
        ponto1[1]= pontos->y;
        ponto2[0]= pontos->prox->x;
        ponto2[1]= pontos->prox->y;
        Bresenham(ponto1,ponto2);
        pontos = pontos->prox;
    }
}

void Rect :: desenharect(int *ponto1, int *ponto2, int *ponto3, int *ponto4){
    Bresenham(ponto1,ponto2);
    Bresenham(ponto2,ponto3);
    Bresenham(ponto3,ponto4);
    Bresenham(ponto4,ponto1);
}


void Formas :: Bresenham(int *ponto1,int *ponto2) {

    typedef struct{
        int x;
        int y;
    }vetor;

    vetor T[2];
    int delta_x,delta_y,p_k,x,y;
    int i,j;
        float  m;

    T[0].x=ponto1[0];
    T[0].y=ponto1[1];
    T[1].x=ponto2[0];
    T[1].y=ponto2[1];

    delta_x=T[1].x-T[0].x;
    delta_y=T[1].y-T[0].y;
    m=((float)(delta_y))/delta_x;


    /*Se a reta for vertical*/

    if(T[0].x==T[1].x){
        if(T[0].y < T[1].y){
            for(i=T[0].y;i<=T[1].y;i++){
                glBegin( GL_POINTS );
                glVertex2i( T[0].x,i);
                    glEnd( );
            }
        }
        else{
            for(i=T[0].y;i>=T[1].y;i--){
                glBegin( GL_POINTS );
                glVertex2i( T[0].x,i);
                    glEnd( );
            }
        }
     }

     /*Se a reta for horizontal*/

     else if(T[0].y == T[1].y){
        if(T[0].x<T[1].x){
            for(i=T[0].x;i<=T[1].x;i++){
                glBegin( GL_POINTS );
                glVertex2i( i,T[0].y);
                    glEnd( );
            }
        }
        else{
            for(i=T[0].x;i>=T[1].x;i--){
                glBegin( GL_POINTS );
                glVertex2i( i,T[0].y);
                    glEnd( );
            }
        }
        }

      /*Se for diagonal perfeita.*/

      else if(abs(T[0].x-T[1].x)==abs(T[0].y-T[1].y)){
        if(m>0){
            if(T[0].x < T[1].x){
                for(i=T[0].x,j=T[0].y;i<=T[1].x;i++,j++){
                    glBegin( GL_POINTS );
                    glVertex2i( i,j);
                        glEnd( );
                }
            }
            else{
                for(i=T[0].x,j=T[0].y;i>=T[1].x;i--,j--){
                    glBegin( GL_POINTS );
                    glVertex2i( i,j);
                        glEnd( );
                }
            }
        }
        else{
            if(T[0].x < T[1].x){
                for(i=T[0].x,j=T[0].y;i<=T[1].x;i++,j--){
                    glBegin( GL_POINTS );
                    glVertex2i( i,j);
                        glEnd( );
                }
            }
            else{
                for(i=T[0].x,j=T[0].y;i>=T[1].x;i--,j++){
                    glBegin( GL_POINTS );
                    glVertex2i( i,j);
                        glEnd( );
                }
            }
        }
           }
       /*Se o módulo do coeficiente angular for menor que 1.*/

       else if((1-fabs(m))>0.00001){
        y=T[0].y;
        x=T[0].x;

        glBegin( GL_POINTS );
        glVertex2i(x,y);
        glEnd( );

        if(m>0){
            if(T[0].x<T[1].x){
                p_k=2*delta_y-delta_x;

                for(x=T[0].x+1;x<=T[1].x;x++){

                    if(p_k < 0){
                        p_k+=2*delta_y;
                    }
                    else{
                        y++;
                        p_k+= 2*delta_y-2*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
            else{
                p_k=(-2)*delta_y+delta_x;

                for(x=T[0].x-1;x>=T[1].x;x--){

                    if(p_k < 0){
                        p_k+=(-2)*delta_y;
                    }
                    else{
                        y--;
                        p_k+= (-2)*delta_y+2*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
        }
        else{
            if(T[0].x<T[1].x){
                p_k=(-2)*delta_y-delta_x;

                for(x=T[0].x+1;x<=T[1].x;x++){

                    if(p_k < 0){
                        p_k+=(-2)*delta_y;
                    }
                    else{
                        y--;
                        p_k+= (-2)*delta_y-2*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
            else{
                p_k=(-2)*delta_y-delta_x;

                for(x=T[0].x-1;x>=T[1].x;x--){

                    if(p_k < 0){
                        p_k+=(-2)*delta_y-2*delta_x;
                        y++;
                    }
                    else{
                        p_k+= (-2)*delta_y;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }

        }
        }
        /*Se o coeficiente angular for maior que 1.*/

            else if((1-fabs(m))<-0.00001){
            y=T[0].y;
            x=T[0].x;

            glBegin( GL_POINTS );
        glVertex2i(x,y);
        glEnd( );

        if(m>0){
            if(T[0].x < T[1].x){
                    p_k=2*delta_x-delta_y;
                for(y=T[0].y+1;y<=T[1].y;y++){

                    if(p_k > 0){
                        x++;
                        p_k+=2*delta_x-2*delta_y;
                    }
                    else{
                        p_k+= 2*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
            else{
                p_k=(-2)*delta_x+delta_y;

                for(y=T[0].y-1;y>=T[1].y;y--){

                    if(p_k > 0){
                        x--;
                        p_k+=(-2)*delta_x+2*delta_y;
                    }
                    else{
                        p_k+= (-2)*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
        }
        else{
            if(T[0].x < T[1].x){
                    p_k=2*delta_x+delta_y;

                for(y=T[0].y-1;y>=T[1].y;y--){

                    if(p_k > 0){
                        x++;
                        p_k+=2*delta_x+2*delta_y;
                    }
                    else{
                        p_k+= 2*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
            else{
                p_k=(-2)*delta_x-delta_y;

                for(y=T[0].y+1;y<=T[1].y;y++){

                    if(p_k > 0){
                        x--;
                        p_k+=(-2)*delta_x-2*delta_y;
                    }
                    else{
                        p_k+= (-2)*delta_x;
                    }
                    glBegin( GL_POINTS );
                    glVertex2i(x,y);
                    glEnd( );
                }
            }
        }
    }
}

void Elipse_Circulo :: desenha_circulo(int* ponto_c, int raio){
    int x=0;
    int y=raio;
    int d = 1-raio;
    int delta_l = 3;
    int delta_se = -2*raio+5;

    glBegin( GL_POINTS );
    glVertex2i( x + ponto_c[0], y + ponto_c[1]);
    glVertex2i(-x + ponto_c[0], y + ponto_c[1]);
    glVertex2i( x + ponto_c[0],-y + ponto_c[1]);
    glVertex2i(-x + ponto_c[0],-y + ponto_c[1]);
    glVertex2i( y + ponto_c[0], x + ponto_c[1]);
    glVertex2i(-y + ponto_c[0], x + ponto_c[1]);
    glVertex2i( y + ponto_c[0],-x + ponto_c[1]);
    glVertex2i(-y + ponto_c[0],-x + ponto_c[1]);
    glEnd( );


    while(y > x){
        if(d < 0){
            d+=delta_l;
            delta_l+=2;
            delta_se+=2;
        }
        else{
            d+=delta_se;
            delta_l+=2;
            delta_se+=4;
            y--;
        }
        x++;

        glBegin( GL_POINTS );
        glVertex2i( x + ponto_c[0], y + ponto_c[1]);
        glVertex2i(-x + ponto_c[0], y + ponto_c[1]);
        glVertex2i( x + ponto_c[0],-y + ponto_c[1]);
        glVertex2i(-x + ponto_c[0],-y + ponto_c[1]);
        glVertex2i( y + ponto_c[0], x + ponto_c[1]);
        glVertex2i(-y + ponto_c[0], x + ponto_c[1]);
        glVertex2i( y + ponto_c[0],-x + ponto_c[1]);
        glVertex2i(-y + ponto_c[0],-x + ponto_c[1]);
        glEnd( );
    }

}

void Elipse_Circulo :: desenha_elipse(int raio_x,int raio_y,int* ponto_c){
    int P;
    int p_x,p_y;
    int x,y;
    int raio_xquad = raio_x*raio_x;
    int raio_yquad = raio_y*raio_y;


    x=0;
    y=raio_y;
    p_x=0;
    p_y = 2 * raio_xquad * y;

        printf("nadlajds1\n");
    glBegin(GL_POINTS);
    glVertex2i(ponto_c[0]+x,ponto_c[1]+y);
    glVertex2i(ponto_c[0]-x,ponto_c[1]+y);
    glVertex2i(ponto_c[0]+x,ponto_c[1]-y);
    glVertex2i(ponto_c[0]-x,ponto_c[1]-y);
    glEnd();
        printf("nadlajds2\n");

    P = round(raio_yquad - (raio_xquad*raio_y) + 0.25*raio_xquad);

    while(p_x < p_y){
        x++;
        p_x += 2* raio_yquad;

        if(P<0){
            P+= raio_yquad + p_x;
        }
        else{
            y--;
            p_y-=2*raio_xquad;
            P+= raio_yquad + p_x - p_y;
        }
        glBegin(GL_POINTS);
        glVertex2i(ponto_c[0]+x,ponto_c[1]+y);
        glVertex2i(ponto_c[0]-x,ponto_c[1]+y);
        glVertex2i(ponto_c[0]+x,ponto_c[1]-y);
        glVertex2i(ponto_c[0]-x,ponto_c[1]-y);
        glEnd();
    }

    P = round(raio_yquad * (x + 0.5)*(x + 0.5) + raio_xquad*(y-1)*(y-1) - raio_xquad*raio_yquad);

    while(y>0){
        y--;
        p_y-= 2*raio_xquad;

        if(P>0){
            P+= raio_xquad - p_y;
         }
         else{
            x++;
            p_x+=2*raio_yquad;//??
            P+= raio_xquad - p_y + p_x;

         }
         glBegin(GL_POINTS);
         glVertex2i(ponto_c[0]+x,ponto_c[1]+y);
         glVertex2i(ponto_c[0]-x,ponto_c[1]+y);
         glVertex2i(ponto_c[0]+x,ponto_c[1]-y);
         glVertex2i(ponto_c[0]-x,ponto_c[1]-y);
         glEnd();
    }
}



