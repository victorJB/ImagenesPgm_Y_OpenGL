#ifdef __APPLE__
#  include "opImagen.h"
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#include "opImagen.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

void opImage::igualar(opImage a)
{
    int i = 0;
    int j = 0;

    this->filas = a.filas;
    this->columnas = a.columnas;

    this->matriz = new double* [this->filas];

    for(i=0;i<this->filas;i++)
    {
        this->matriz[i]= new double [this->columnas];
    }

    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {
            this->matriz[i][j]=a.matriz[i][j];
        }
    }


}

void opImage::pintar()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_POINTS);

    int filas = this->filas;
    int columnas = this->columnas;
    double n = 0;
    double r = 480;
    int i = 0;
    int j = 0;
    double data = 0;
    int escalar = 180;

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            data = this->devolverCoordenada(i,j);
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

void opImage::threshold(opImage a)
{
    int i = 0;
    int j = 0;

    this->igualar(a);

    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {
            if(this->matriz[i][j]>=150)
                this->matriz[i][j] = 255;
            else
                this->matriz[i][j] = 0;
        }
    }

    this->pintar();


}

void opImage::negativo(opImage a)
{
    this->igualar(a);
    int i = 0;
    int j = 0;

    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {
            this->matriz[i][j] = 255-this->matriz[i][j];
        }
    }

    this->pintar();
}
