#ifndef OPIMAGEN_H
#define OPIMAGEN_H

#include "pgm.h"
#include "matrix.h"

class opImage : public PGM
{

 private:


 public:


    void pintar();
    opImage();
    ~opImage();
    void threshold(const opImage &a, int numero);
    void igualar(const opImage &a);
    void negativo(const opImage &a);
    void operator>(int t);
    void igualarDatos(const opImage &a);
    void operator!();



};

#endif // OPIMAGEN_H
