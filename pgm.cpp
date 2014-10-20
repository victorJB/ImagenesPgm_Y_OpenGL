#include <pgm.h>

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
    ifstream file;
    char cadena[100];

    file.open(nombre.c_str());
    if(file.is_open())
    {
       for(j=0;j<8;j++)
       {
           file>> cadena;
       }

       file >> this->columnas;
             file >> this->filas;

             file>>cadena;

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

int PGM::devolverCoordenada(int i, int j)
{
    return this->matriz[i][j];
}


