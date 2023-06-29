#ifndef CARRERA_HPP
#define CARRERA_HPP

#include "./Alumno.hpp"

class Carrera {
public:
  Carrera() = default;
  Carrera(Carrera &&) = default;
  Carrera(const Carrera &) = default;
  Carrera &operator=(Carrera &&) = default;
  Carrera &operator=(const Carrera &) = default;
  ~Carrera() = default;

  Carrera(std::string, std::string);
  std::string getNombre() const;
  std::string getAcademia() const;
  void mostrarDatos();

  void agregarAlumno(const Alumno&);
  void eliminarAlumno(long int);
  Alumno &buscarAlumno(long int);
  void mostrarAlumnos();

  void agregarMateria(const Materia&); 
  void eliminarMateria(int);
  Materia &buscarMateria(int);
  void verMaterias();

private:
  const std::string nombre;
  const std::string academia;
  int numAlumnos;
  std::list<Alumno> alumnos;
  std::vector<Materia> materias;

  int materiaExistente(int id);
};

#endif // !CARRERA_HPP
