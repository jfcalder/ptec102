#include <iostream>
#include <vector>
#include "universidad_clases.h"

using namespace std;

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
Profesor::Profesor(string nombre, string asignatura, int rut) : Persona(nombre,rut){
  if(asignatura != "ingles"){
    this->asignatura = asignatura;
  }
  else{
    this->asignatura = "No tiene asignatura";
  }
}

Profesor::Profesor(string nombre, int rut) : Persona(nombre, rut){

  this->asignatura = "No tiene asignatura";
}

Profesor::~Profesor(){
  cout << "Destruyendo objeto de tipo Profesor" << endl;
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
  cout << "El profesor " << this->getNombre() << " esta enseñando " << contenido << endl;
}

void Profesor::ayudar(Estudiante* e){
  cout << this->getNombre() << " esta ayudando respecto a temas pedagógicos al estudiante " << e->getNombre() << endl;
}

void Profesor::cambiarCarrera(Estudiante* e, string carrera){
  if(carrera != "antropologia"){
      e->setCarrera(carrera);
  }
}

Estudiante::Estudiante(string nombre, string carrera, int rut, float ppa) : Persona(nombre,rut){
  this->carrera = carrera;
  this->ppa = ppa;
}

Estudiante::Estudiante(string nombre, int rut) : Persona(nombre,rut){
  this->carrera = "No tiene carrera";
  this->ppa = 1.0;
}

string Estudiante::getCarrera(){
  return this->carrera;
}

void Estudiante::setCarrera(string carrera){
  this->carrera = carrera;
}


void Estudiante::aprender(string contenido){
  cout << "El estudiante " << this->getNombre() << " esta aprendiendo " << contenido << endl;
}
DirectorCarrera::DirectorCarrera(string nombre, string facultad, int rut) : Profesor(nombre, "informatica", rut){
  this->facultad = facultad;
}

DirectorCarrera::~DirectorCarrera(){
  cout << "Destruyendo objeto de tipo DirectorCarrera" << endl;  
}

void DirectorCarrera::entrevistarProfesor(Profesor* p){
  cout << "El director " << this->getNombre() << " esta entrevistando al profesor " << p->getNombre() << endl;
}

void DirectorCarrera::ayudar(Estudiante* e){
  cout << "El director (como director)" << this->getNombre() << " esta ayudando al estudiante " << e->getNombre() << endl;
}
Curso::Curso(int nrc, string nombre, Profesor* docente){
  this->nrc = nrc;
  this->nombre = nombre;
  this->docente = docente;
}

Curso::~Curso(){
  cout << "Destruyendo objeto de tipo Curso" << endl;
}

void Curso::comenzarImparticion(){
  cout << "Empezando curso de " << this->nombre << endl;
}

void Curso::inscribirEstudiante(Estudiante* estudiante){
  this->estudiantes.push_back(estudiante);
}

void Curso::mostrarListaEstudiantes(){
  cout << "Estudiantes inscritos curso " << this->nombre << " - Profesor " << this->docente->getNombre() << endl;
  for(int i = 0; i < this->estudiantes.size(); i++){
    cout << this->estudiantes[i]->getNombre() << endl;
  }
}

Facultad::Facultad(string nombre){
  this->nombre = nombre;
}

Facultad::~Facultad(){
  cout << "Destruyendo objeto de tipo Facultad" << endl;
}

void Facultad::agregarCurso(Curso *curso){
  this->cursos.push_back(curso);
}

void Facultad::iniciarFuncionamiento(){
  cout << "Iniciando funcionamiento de la facultad " << this->nombre << endl;

  Profesor* p1 = new Profesor("Juan Pedro", "Matematicas", 123456);
  Profesor* p2 = new Profesor("Pedro", 654321);
  //Profesor* p3 = new Profesor("Lorena", "matemática", 654876);
  Estudiante* e1 = new Estudiante("Lorena",5636);
  Estudiante* e2 = new Estudiante("Juan Luis",65365365);

  Curso* curso1 = new Curso(101, "Matematicas", p1);
  curso1->inscribirEstudiante(e1);
  curso1->inscribirEstudiante(e2);
  curso1->comenzarImparticion();
  curso1->mostrarListaEstudiantes();

  Curso* curso2 = new Curso(102, "Lenguaje", p2);
  curso2->inscribirEstudiante(e1);
  curso2->mostrarListaEstudiantes();

  p1->ayudar(e2);
  p2->ayudar(e1);
  p1->cambiarCarrera(e1, "Ingenieria");
  p1->cambiarCarrera(e2, "antropologia");
  cout << e1->getCarrera() << endl;
  cout << e2->getCarrera() << endl;

  cout << "hola" << endl;
  DirectorCarrera* d1 = new DirectorCarrera("Carla", "Facultad de Ingenieria", 123456);
  d1->entrevistarProfesor(p1);
  cout << "chao" << endl;
  d1->ayudar(e1);
  cout << "Mostrando polimorfismo" << endl;
  vector<Profesor*> profesores;
  profesores.push_back(new Profesor("Juan Luis", "Matematicas", 6545564));
  profesores.push_back(new Profesor("Amanda", "Biologia", 544544));
  profesores.push_back(new Profesor("Emilia", "Fisica", 985671));
  profesores.push_back(new DirectorCarrera("Giannina", "Facultad de Ingenieria", 123456));

  for(int i = 0; i < profesores.size(); i++){
    profesores[i]->ayudar(e1);
  }
}

