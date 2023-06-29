#ifndef PROFESOR_H
#define PROFESOR_H

#include "./Persona.hpp"

enum class Tiempo 
{
  COMPLETO,
  MEDIO
};

class Profesor : public Persona
{
public:
  Profesor();
  Profesor(Profesor &&) = default;
  Profesor(const Profesor &) = default;
  Profesor &operator=(Profesor &&) = default;
  Profesor &operator=(const Profesor &);
  ~Profesor() = default;
 
  void ingresarInformacion();
  void mostrarDatos();
  const std::string toString(Tiempo);

private:
  int horas;
  Tiempo tiempo;
  std::string titulo;

  Tiempo seleccionarTrabajo(); 
};

#endif 
