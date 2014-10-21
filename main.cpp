#ifdef __APPLE__
#  include <iostream>
#  include "matrix.h"
#  include <fstream>
#  include "pgm.h"
#  include "opImagen.h"
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#include <iostream>
#include "matrix.h"
#include <fstream>
#include "pgm.h"
#include "opImagen.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

void display(void);
void keyboard(unsigned char z, int x, int y);

using namespace std;

Matrix a;
opImage b;
opImage c;
char selector;
int k = 0;
char g;
int numero = 155;


int main(int argc, char** argv)
{


   b.CargarDatos("C://venecia.pgm");
   c.igualar(b);

   glutInit(&argc, argv);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(200,100);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   gluOrtho2D(0,640,0,480);
   glutCreateWindow("Venecia");
   gluOrtho2D(0,640,0,480);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();


       return EXIT_SUCCESS;
}



void display()
{
  b.pintar();

}

void keyboard(unsigned char z,int x,int y)
{
    switch(z)
    {
      case 'd':

        b.pintar();
        break;
      case 'a':
        c.threshold(b,numero);
            break;
       case 's':
        c.negativo(b);

    }

}

