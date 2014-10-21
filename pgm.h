#ifndef PGM_H
#define PGM_H

#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

class PGM : public Matrix
{

private:



public:
    PGM();
    PGM(int filas, int columnas);
    void CargarDatos(string nombre);
    int devolverCoordenada(int i, int j);


};

#endif // PGM_H
