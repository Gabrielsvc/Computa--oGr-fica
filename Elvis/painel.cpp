#include "painel.h"
#include "formas.h"
painel::painel(QWidget *parent) :
    QWidget(parent)
{
}

painel::criarect(){
    rect r = new rect();
}


void painel::resize( int w, int h )
{
    float vfAspect = 0.f;
    float viewDepth = gfWrldSizeZ/2.f;

    // Usar toda a janela.
    glViewport(0, 0, w, h);

    h = (h==0) ? 1 : h;
    w = (w==0) ? 1 : w;
    vfAspect = ( h < w ) ? (float)w/(float)h : (float)h/(float)w ;

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    glOrtho( 0, gfWrldSizeX, // * vfAspect,
             0, gfWrldSizeY, // * vfAspect,
            -viewDepth, viewDepth );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity( );
}
void painel::init( void )
{
    // Clear the rendering window
    glClearColor( 0.f, 0.f, 0.f, 0.f );
    glClear( GL_COLOR_BUFFER_BIT );
    glPushMatrix( );
    glPopMatrix( );
                    // Flush the pipeline, swap the buffers
    glFlush();
}


void painel::redesenha( void )
{
    // Clear the rendering window
    glClearColor( 0.f, 0.f, 0.f, 0.f );
    glClear( GL_COLOR_BUFFER_BIT );

    glPushMatrix( );
    glPopMatrix( );
                    // Flush the pipeline, swap the buffers
    glFlush();
}


