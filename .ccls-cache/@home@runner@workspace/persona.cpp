#include "persona.h"

Persona::Persona(string nombre, int rut){
  this->nombre = nombre;
  this->rut = rut;                       
}

Persona::~Persona(){
  cout << "destruyendo" << endl;                   
}

string Persona::getNombre(){
   return this->nombre;      
}

void Persona::setNombre(string nombre){
   this->nombre = nombre;      
}


int Persona::getRut(){
   return this->rut;      
}

void Persona::setRut(int rut){
   this->rut = rut;      
}