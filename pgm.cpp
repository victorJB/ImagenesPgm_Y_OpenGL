#include "pgm.h"

PGM::PGM()
{

}

PGM::PGM(int filas, int columnas)
{

    int i = 0;

    this->filas = filas;
    this->columnas = columnas;

    matriz = new double*[this->filas];

    for(i = 0;i<this->filas;i++)
    {

        matriz[i] = new double[this->columnas];
    }
}

void PGM::CargarDatos(string nombre)
{
    int i = 0;
    int j = 0;
    int n = 0;

    ifstream file;

    file.open(nombre.c_str());
    if(file.is_open())
    {
       for(j=0;j<34;j++)
       {
           file>> this->cadena[n];
           n++;
       }

       file >> this->columnas;
             file >> this->filas;

             file>>this->cadena[n];
             n++;
             file>>this->cadena[n];
             n++;
             file>>this->cadena[n];


             this->matriz = new double* [this->filas];

             for(i=0;i<this->filas;i++)
             {
                 this->matriz[i]= new double [this->columnas];
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

void PGM::exportarDatos(string A)
{
    int i = 0;
    int j = 0;
    int n = 0;

    ofstream file;
    file.open(A.c_str());
    if(file.is_open())
    {

        file<<cadena[n];
        n++;
        file<<cadena[n]<<endl;
        n++;

        file<<cadena[n]<<" ";
        n++;

        for(j=0;j<7;j++)
        {
            file<<this->cadena[n];
            n++;
        }

         file<<this->cadena[n]<<" ";
         n++;

        for(j=0;j<3;j++)
        {
            file<<this->cadena[n];
            n++;
        }

        file<<this->cadena[n]<<" ";
        n++;

        for(j=0;j<2;j++)
        {
            file<<this->cadena[n];
            n++;
        }

         file<<this->cadena[n]<<" ";
         n++;


        for(j=0;j<5;j++)
        {
            file<<this->cadena[n];
            n++;
        }

        file<<this->cadena[n]<<" ";
        n++;

        for(j=0;j<6;j++)
        {
            file<<this->cadena[n];
            n++;
        }

        file<<this->cadena[n]<<" ";
        n++;

       for(j=0;j<2;j++)
       {
           file<< this->cadena[n];
           n++;
       }

       file<< this->cadena[n]<<endl;
       n++;


        file << this->columnas << " "<< this->filas<<endl;


        file<<this->cadena[n];
        n++;
        file<<this->cadena[n];
        n++;
        file<<this->cadena[n]<<endl;




              for(i = 0;i<this->filas;i++)
              {
                  for(j = 0;j<this->columnas;j++)
                  {
                      file << this->matriz[i][j]<<endl;

                  }
              }

      file.close();




    }

}

int PGM::devolverCoordenada(int i, int j)
{
    return this->matriz[i][j];
}




