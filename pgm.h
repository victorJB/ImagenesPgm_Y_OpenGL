#ifndef PGM_H
#define PGM_H

#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

class PGM : public Matrix
{

protected:

 char cadena[200];



public:

    PGM();
    ~PGM();
    PGM(int filas, int columnas);
    void CargarDatos(string nombre);
    int devolverCoordenada(int i, int j);
    void exportarDatos(string A);


};

#endif // PGM_H
