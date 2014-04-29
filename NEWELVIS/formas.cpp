#include "formas.h"
#include "cmath"
#include "stdlib.h"
#include <GL/gl.h>

Formas::Formas()
{
}


void Rect :: desenharect(int *ponto1, int *ponto2, int *ponto3, int *ponto4){
    Bresenham(ponto1,ponto2);
    Bresenham(ponto2,ponto3);
    Bresenham(ponto3,ponto4);
    Bresenham(ponto4,ponto1);
}


void Rect :: Bresenham(int *ponto1,int *ponto2) {

    typedef struct{
        int x;
        int y;
    }vetor;

    vetor T[2];
    //T[0] = {0,0};
    //T[1] = {0,0};
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


