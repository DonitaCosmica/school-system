#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <map>
#include <vector>

#include "./Materia.hpp"

enum class Estado 
{
  AGS, BC, CDMX, CHIS,
  CHIH, COAH, EDMX, JAL,
  MOR, NL, PUE, QRO,
  SLP, SON, TAB, TAMPS,
  VER, YUC
};

class Alumno : public Persona
{
public:
  Alumno();
  Alumno(Alumno &&) = default;
  Alumno(const Alumno &) = default;
  Alumno &operator=(Alumno &&) = default;
  Alumno &operator=(const Alumno&);
  ~Alumno() = default;
  
  void ingresarInformacion(std::string, std::string);
  void mostrarDatos();
  void agregarMateria(const Materia&); 
  void eliminarMateria(int);
  Materia &buscarMateria(int);
  void verMaterias();

private:
  // Atributos
  Estado campus;
  std::string areaAcademica;
  std::string carrera;
  int numMaterias;
  std::vector<Materia> materias;
  
  // Metodos
  Estado seleccionarCampus();
  const std::string toString(Estado);
  static const std::map<Estado, std::string> estadoToString;
  int materiaExistente(int id);
};

#endif // !ALUMNO_HPP
