#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

using namespace std;



class Matrix
{
protected:

    int filas;
    int columnas;
    double **matriz;
    char cadena[200];


public:


    Matrix();
    Matrix(int filas, int columnas);
    //~Matrix();
    void setMatrix();
    int getFilas();
    int getColumnas();
    Matrix getMatrix();
    double** suma(Matrix a, Matrix b);
    void resta(Matrix a, Matrix b);
    void mulPorEscalar(double escalar);
    void transpuesta();
    void multiplicacion(Matrix a, Matrix b);
    Matrix operator+(const Matrix X);
    void showMatrix();
    Matrix operator-(const Matrix x);
    Matrix operator*(const Matrix x);
    friend ostream& operator << (ostream& os, const Matrix &m);
    void cargarDatos(string A);
    void exportarDatos(string A);
    static Matrix sum(Matrix a, Matrix b);
    static Matrix rest(Matrix a, Matrix b);
    static Matrix mult(Matrix a, Matrix b);

};


#endif // MATRIX_H
