/*!
 ===========================================================================
 SOURCE FILE : gasket.c
 ===========================================================================
 DESCRIPTION.: Um programa simples que desenha uma linha por Bresenham.

 AUTHOR......: Selan R. dos Santos
 ADAPTATION..: Do livro "Computer Graphics Using OpenGL", F. S. Hill, Jr.
 LOCATION....: DIMAp/UFRN.
 SATARTED ON.: August/2006
 CHANGES.....: No changes.

 TO COMPILE..: make gasket
 OBS.........: Part of the DIM0102 Project.

 LAST UPDATE.:
 ---------------------------------------------------------------------------
*/

/* ========================================================================= */
/* INCLUDES E DEFINES                                                        */
/* ------------------------------------------------------------------------- */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h> // OpenGL Graphics Utility Library


/* ========================================================================= */
/* VARIAVEIS GLOBAIS E TIPOS                                                 */
int x2;
int y2;
int x3;
int y3;

/* ------------------------------------------------------------------------- */

//! Representa um ponto com tipos básicos do OpenGL.
typedef struct _GLintPoint {
        GLint x;
        GLint y;
} GLintPoint ;

//! Tamanho do mundo
const GLfloat gfWrldSizeX = 400.f;
const GLfloat gfWrldSizeY = 400.f;
const GLfloat gfWrldSizeZ = 400.f;


/* ========================================================================= */
/* PROTOTIPO DE FUNCOES                                                      */
/* ------------------------------------------------------------------------- */

void myKeyboardFunc( unsigned char, int, int );
void mySpecialKeyFunc( int, int, int );
void drawScene(void);
void initRendering( void );
void resizeWindow( int, int );
void Bresenham();
void myApplicationInit ( void );

//! Rotina principal, configura a janela para o OpenGL desenhar.
int main( int argc, char** argv )
{
	
    int xa,xb,ya,yb;
    printf("Coordenadas na Janela ([0,400]x[0,400])\n");

    printf("x0: ");
    scanf("%i",&xa);
    printf("y0: ");
    scanf("%i",&ya);
    printf("x1: ");
    scanf("%i",&xb);	
    printf("y1: ");
    scanf("%i",&yb);	
	
    x2=xa;
    y2=ya;
    x3=xb;
    y3=yb;	

    // Initializing the glut (demanded by the freeglut implementation).
    glutInit(&argc,argv);

    // We're not going to animate it, so a single buffer will do the job.
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );

    // Window position (from top corner), and size (width% and hieght)
    glutInitWindowPosition( 10, 60 );
    glutInitWindowSize( 500, 500 );
    glutCreateWindow( "** Linha Bresenham **" );

    // Initialize OpenGL parameters.
    initRendering();

    // Call this whenever window needs redrawing
    glutDisplayFunc( drawScene );

    // Set up callback functions for key presses
    glutKeyboardFunc( myKeyboardFunc );	// Handles "normal" ascii symbols
    // glutSpecialFunc( mySpecialKeyFunc );  // Handles "special" keyboard keys

    // Set up the callback function for resizing windows
    glutReshapeFunc( resizeWindow );

    // Call this for background processing
    // glutIdleFunc( myIdleFunction );

    myApplicationInit( );

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop(  );

    // This line is never reached.
    return( EXIT_SUCCESS );
}

//! Set the initial values for the application, in this case the seed for random().
void
myApplicationInit( void ) {
    // Iniciar o random de forma a gerar pontos diferentes cada vez.
    srand( (int) time( NULL ) );
}

//! glutKeyboardFunc is called below to set this function to handle all "normal" key presses.
void myKeyboardFunc( unsigned char key, int x, int y )
{
    int w, h;
    switch ( key ) {
        case 27:	// Escape key
            exit( EXIT_SUCCESS );
    }
}

/*! Called below to set this function to handle
 * all "special" key presses.  See glut.h for the names of
 * special keys.
 * @param key Key's ascii code.
 */
void
mySpecialKeyFunc( int key,
                  int x,
                  int y )
{ /* Empty */ }


//! Callback responsável pelas rotinas de desenho
/*!
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 */
void drawScene(void)
{
    // Clear the rendering window
    glClearColor( 0.9f, 0.9f, 0.9f, 0.f );
    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f( 1.f, 0.f, 0.f );

    glPushMatrix( );

    Bresenham ();

    glPopMatrix( );
    // Flush the pipeline, swap the buffers
    glFlush();
}

void
Bresenham() {
	GLintPoint T[] = {{0,0},{0,0}};
	int delta_x,delta_y,p_k,x,y;
	int i,j;
    	float  m;

	T[0].x=x2;
	T[0].y=y2;
	T[1].x=x3;
	T[1].y=y3;	

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


// Initialize OpenGL's rendering modes
void initRendering()
{ /* Empty */ }

//! 
/*! Callbal called when the drawing window is resized.
 *  @param w Window's width
 *  @param h Window's height
 */
void resizeWindow( int w, int h )
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

