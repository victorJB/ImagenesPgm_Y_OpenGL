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

void opImage::threshold(opImage a, int numero)
{

    *this = a>numero;

    this->pintar();


}

void opImage::negativo(opImage a)
{

    *this = !a;

    this->pintar();
}

opImage opImage::operator>(int t)
{

    int i = 0;
    int j = 0;

    opImage z;

    z.filas = this->filas;
    z.columnas = this->columnas;

    z.matriz = new double* [z.filas];

    for(i=0;i<filas;i++)
    {
        z.matriz[i] = new double [z.columnas];
    }

    for(i=0;i<z.filas;i++)
    {
        for(j=0;j<z.columnas;j++)
        {
            if(this->matriz[i][j]>=t)
                z.matriz[i][j] = 255;
            else
                z.matriz[i][j] = 0;
        }
    }

    return z;
}

opImage opImage::operator!()
{

    int i = 0;
    int j = 0;

    opImage z;

    z.filas = this->filas;
    z.columnas = this->columnas;

    z.matriz = new double* [z.filas];

    for(i=0;i<z.filas;i++)
    {
        z.matriz[i] = new double [z.columnas];
    }

    for(i=0;i<z.filas;i++)
    {
        for(j=0;j<z.columnas;j++)
        {
          z.matriz[i][j] = 255-this->matriz[i][j];

        }
    }

    return z;
}






