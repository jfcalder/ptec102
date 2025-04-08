#include <iostream>
#include <vector>
using namespace std;

class Persona{
  private:
          string nombre;
          int rut;
  public:
          Persona(string nombre, int rut);
          ~Persona();
          string getNombre();
          void setNombre(string nombre);
          int getRut();
          void setRut(int rut);
};