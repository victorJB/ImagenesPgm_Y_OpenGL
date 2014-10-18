#include <iostream>
#include <matrix.h>
#include <fstream>


using namespace std;


int main()
{

   Matrix a;
   Matrix b;
   Matrix c;

   a.cargarDatos("MatrizA.txt");
   b.cargarDatos("MatrizB.txt");

  cout<<a<<endl;
  cout<<b<<endl;

  a.exportarDatos("NuevaMatrizA.txt");
  b.exportarDatos("NuevaMatrizB.txt");

  c = a+b;
  cout<<"Sobrecarga del operador + y exportar datos"<<endl;
  cout<<c<<endl;
  c.exportarDatos("NuevaMatrizC.txt");


    return 0;
}

