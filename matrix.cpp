#include <iostream>
#include <matrix.h>
#include <fstream>

using namespace std;

Matrix::Matrix()
{
    matriz = NULL;
    columnas = 0;
    filas = 0;
}

Matrix::Matrix(int filas, int columnas)
{

    int i = 0;

    this->filas = filas;
    this->columnas = columnas;

    matriz = new double*[this->filas];

    for(i = 0;i<this->columnas;i++)
    {

        matriz[i] = new double[this->columnas];
    }

}

Matrix::~Matrix()
{

    delete &filas;
    delete &columnas;


}


void Matrix::setMatrix()
{
    int i = 0;
    int j = 0;

    for(i = 0;i<this->filas;i++)
    {
        for(j = 0;j<this->columnas;j++)
        {
            cin>>matriz[i][j];

        }
    }

    cout<<endl;
}


Matrix Matrix::getMatrix()
{

  Matrix z;
  int filas = 0;
  int columnas = 0;
  int i = 0;
  int j = 0;



  filas = this->filas;
  columnas = this->columnas;

  z.matriz = new double* [filas];

  for(i=0;i<columnas;i++)
  {
      z.matriz[i] = new double [columnas];
  }

  for(i=0;i<filas;i++)
  {
      for(j=0;j<columnas;j++)
      {
          z.matriz[i][j]= this->matriz[i][j];
      }
  }

  return z;


}

double **Matrix::suma(Matrix a, Matrix b)
{
    int i = 0;
    int j = 0;

    this->filas = a.filas;
    this->columnas = a.columnas;

    for(i=0;i<a.filas;i++)
    {
        for(j=0;j<a.columnas;j++)
        {
            this->matriz[i][j] = a.matriz[i][j]+b.matriz[i][j];
        }
    }

    return matriz;

}

void Matrix::resta(Matrix a, Matrix b)
{
    int i = 0;
    int j = 0;

    this->filas = a.filas;
    this->columnas = a.columnas;

    for(i=0;i<a.filas;i++)
    {
        for(j=0;j<a.columnas;j++)
        {
            this->matriz[i][j] = a.matriz[i][j]-b.matriz[i][j];
        }
    }

}

void Matrix::mulPorEscalar(double escalar)
{
    int i = 0;
    int j = 0;

    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->filas;j++)
        {
            this->matriz[i][j] = escalar*this->matriz[i][j];
        }
    }

}

void Matrix::transpuesta()
{

    int i = 0;
    int j = 0;
    double** z;
    {
        z = new double*[this->filas];

        for(i = 0;i<this->columnas;i++)
        {

            z[i] = new double[this->columnas];
        }
    }


        for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {

             z[i][j] = this->matriz[i][j];

        }
    }


    for(i=0;i<this->filas;i++)
    {
        for(j=0;j<this->columnas;j++)
        {

           this->matriz[j][i] = z[i][j];

        }
    }

    for(i=0;i<this->filas;i++)
    {
        delete z[i];
    }

    delete z;


}

void Matrix::multiplicacion(Matrix a, Matrix b)
{
    int i = 0;
    int j = 0;
    int r = 0;

    for(i =0;i<this->filas; i++)
       {
           for(j=0;j<this->columnas;j++)
           {
               for(r=0;r<this->columnas;r++)
               {
                  this->matriz[i][j]= this->matriz[i][j] + a.matriz[i][r]*b.matriz[r][j];
               }
           }
       }
}

Matrix Matrix::operator+(const Matrix x)
{
    Matrix z;

    int i = 0;
    int j = 0;

    z.filas = x.filas;
    z.columnas = x.columnas;

    z.matriz = new double* [z.filas];

    for(i=0;i<filas;i++)
    {
        z.matriz[i] = new double [z.columnas];
    }

    for(i=0;i<z.filas;i++)
    {
        for(j=0;j<z.columnas;j++)
        {
            z.matriz[i][j] = this->matriz[i][j]+x.matriz[i][j];
        }
    }

    return z;


}

void Matrix::showMatrix()
{
    int filas = 0;
    int columnas = 0;
    int i = 0;
    int j = 0;

    filas = this->filas;
    columnas = this->columnas;

    for(i=0;i<filas;i++)
    {
        for(j=0;j<columnas;j++)
        {
            cout<<this->matriz[i][j]<<" ";
        }

        cout<<endl;
    }

}

Matrix Matrix::operator-(const Matrix x)
{
    Matrix z;

    int i = 0;
    int j = 0;

    z.filas = x.filas;
    z.columnas = x.columnas;

    z.matriz = new double* [z.filas];

    for(i=0;i<filas;i++)
    {
        z.matriz[i] = new double [z.columnas];
    }

    for(i=0;i<z.filas;i++)
    {
        for(j=0;j<z.columnas;j++)
        {
            z.matriz[i][j] = this->matriz[i][j]-x.matriz[i][j];
        }
    }

    return z;

}

Matrix Matrix::operator*(const Matrix x)
{
    Matrix z;

    int i = 0;
    int j = 0;
    int r = 0;

    z.filas = x.filas;
    z.columnas = x.columnas;

    z.matriz = new double* [z.filas];

    for(i=0;i<filas;i++)
    {
        z.matriz[i] = new double [z.columnas];
    }



    for(i =0;i<this->filas; i++)
       {
           for(j=0;j<this->columnas;j++)
           {
               for(r=0;r<this->columnas;r++)
               {
                  z.matriz[i][j]= z.matriz[i][j] + this->matriz[i][r]*x.matriz[r][j];
               }
           }
       }
    return z;
}

ostream& operator << (ostream &os, const Matrix &m)
{
    int i = 0;
    int j = 0;

    for(i = 0;i<m.filas;i++)
    {
        for(j=0;j<m.columnas;j++)
        {
            os << m.matriz[i][j] << " ";
        }

        os << endl;
    }

    return os;
}

void Matrix::cargarDatos(string A)
{
    int i = 0;
    int j = 0;
    ifstream file;
    file.open(A.c_str());
    if(file.is_open())
    {
        file >> this->filas;
              file >> this->columnas;

              this->matriz = new double* [filas];

              for(i=0;i<this->filas;i++)
              {
                  this->matriz[i]= new double [columnas];
              }

              for(i = 0;i<this->filas;i++)
              {
                  for(j = 0;j<this->columnas;j++)
                  {
                      file >> this->matriz[i][j];

                  }
              }

     file.close();

    }

}


void Matrix::exportarDatos(string A)
{
    int i = 0;
    int j = 0;
    ofstream file;
    file.open(A.c_str());
    if(file.is_open())
    {
        file << this->filas << " "<< this->columnas<<endl;


              for(i = 0;i<this->filas;i++)
              {
                  for(j = 0;j<this->columnas;j++)
                  {
                      file << this->matriz[i][j] << " ";

                  }

                  file << endl;
              }

      file.close();




    }

}
