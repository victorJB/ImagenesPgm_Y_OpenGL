#ifdef __APPLE__
#  include <iostream>
#  include <matrix.h>
#  include <fstream>
#  include <pgm.h>
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#include <iostream>
#include <matrix.h>
#include <fstream>
#include <pgm.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

void display(void);

using namespace std;

Matrix a;
PGM b;

int main(int argc, char** argv)
{


   b.CargarDatos("C://venecia1.pgm");
   glutInit(&argc, argv);
   glutInitWindowSize(640,480);
   glutInitWindowPosition(200,100);
   glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
   gluOrtho2D(0,640,0,480);
   glutCreateWindow("Venecia");
   gluOrtho2D(0,640,0,480);
   glutDisplayFunc(display);
   glutMainLoop();


       return EXIT_SUCCESS;
}



void display()
{
    int filas =b.getFilas();
    int columnas =b.getColumnas();
    double n = 0;
    double r = 480;
    int i = 0;
    int j = 0;
    double data = 0;
    int escalar = 150;

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POINTS);

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            data = b.devolverCoordenada(i,j);
            data = data/escalar;
            glColor3f(data,data,data);

            glVertex2f(n,r);
            n = n+1;

        }
        j = 0;
        n = 0;
        r = r-1;
    }


    glEnd();

    glFlush();
}


