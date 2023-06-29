#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <list>
#include <algorithm>

#include "./Profesor.hpp"

enum class Asistencia 
{
  PRESENCIAL,
  ONLINE,
  AUSENTE
};

class Materia 
{
public:
  Materia() = default;
  Materia(Materia &&) = default;
  Materia(const Materia &) = default;
  Materia &operator=(Materia &&) = default;
  Materia &operator=(const Materia &);
  ~Materia() = default;
   
  Materia(int);
  void ingresarDatos();
  int getId() const;
  const std::string getNombre() const;
  void agregarProfesor(const Profesor&);
  void eliminarProfesor(long int);
  void mostrarProfesores();
  Profesor &buscarProfesor(long int);
  void mostrarDatos(); 

private:
  // Atributos
  int id;
  std::string nombre;
  short semestre;
  short horas;
  short numClases;
  int creditos;
  Asistencia clase;
  short numProfesores;
  std::list<Profesor> profesores;
  
  // Metodos
  Asistencia seleccionarClase();
  const std::string toString(Asistencia);
};

#endif // !MATERIA_HPP
