#ifndef OPIMAGEN_H
#define OPIMAGEN_H

#include "pgm.h"
#include "matrix.h"

class opImage : public PGM
{

 private:


 public:

    void pintar();
    void threshold(opImage a);
    void igualar(opImage a);
    void negativo(opImage a);



};

#endif // OPIMAGEN_H
