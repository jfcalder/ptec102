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
class Estudiante : public Persona{
private:
string carrera;
float ppa;
public:
Estudiante(string nombre, string carrera, int rut, float ppa);
Estudiante(string nombre, int rut);
void aprender(string contenido);
string getNombre();
string getCarrera();
void setCarrera(string carrera);
};
class Profesor{
private:
string nombre;
string asignatura;
int rut;
public:
Profesor(string nombre, string asignatura, int rut);
Profesor(string nombre, int rut);
~Profesor();
string getNombre();
string getAsignatura();
void setAsignatura(string asignatura);
void ensenar(string contenido);
void ayudar(Estudiante* e);
void cambiarCarrera(Estudiante* e, string carrera);
};
Profesor::Profesor(string nombre, string asignatura, int rut){
this->nombre = nombre;
if(asignatura != "ingles"){
this->asignatura = asignatura;
}
else{
this->asignatura = "No tiene asignatura";
}
this->rut = rut;
}
Profesor::Profesor(string nombre, int rut){
this->nombre = nombre;
this->rut = rut;
this->asignatura = "No tiene asignatura";
}
Profesor::~Profesor(){
cout << "Destruyendo objeto de tipo Profesor" << endl;
}
string Profesor::getNombre(){
return this->nombre;
}
string Profesor::getAsignatura(){
return this->asignatura;
}
void Profesor::setAsignatura(string asignatura){
if(asignatura != "ingles"){
this->asignatura = asignatura;
}
}
void Profesor::ensenar(string contenido){
cout << "El profesor " << nombre << " esta ense ando " << contenido << endl;�
}
void Profesor::ayudar(Estudiante* e){
cout << this->nombre << " esta ayudando al estudiante " << e->getNombre() <<
endl;
}