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

class Estudiante : public Persona{
private:
  string carrera;
  float ppa;
public:
  Estudiante(string nombre, string carrera, int rut, float ppa); 
  Estudiante(string nombre, int rut);
  void aprender(string contenido);
  string getCarrera();
  void setCarrera(string carrera);
};

class Profesor : public Persona{
private:
  string asignatura;
public:
  Profesor(string nombre, string asignatura, int rut);
  Profesor(string nombre, int rut);
  ~Profesor();
  string getAsignatura();
  void setAsignatura(string asignatura);
  void ensenar(string contenido);
  virtual void ayudar(Estudiante* e);
  void cambiarCarrera(Estudiante* e, string carrera);
};

class DirectorCarrera : public Profesor{
private:
  string facultad;
public:
  DirectorCarrera(string nombre, string facultad, int rut);
  ~DirectorCarrera();
  void entrevistarProfesor(Profesor* p);
  void ayudar(Estudiante* e);

};

class Curso{
private:
  int nrc;
  string nombre;
  Profesor* docente;
  vector<Estudiante*> estudiantes;
public:
  Curso(int nrc, string nombre, Profesor* docente);
  ~Curso();
  void inscribirEstudiante(Estudiante* estudiante);
  void comenzarImparticion();
  void mostrarListaEstudiantes();
};

class Facultad{

private:
  vector<Curso*> cursos;
  string nombre;
public:
  Facultad(string nombre);
  ~Facultad();
  void agregarCurso(Curso* curso);
  void iniciarFuncionamiento();
};
