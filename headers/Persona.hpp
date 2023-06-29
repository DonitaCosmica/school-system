#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <string>
#include <limits>

class Persona 
{
public:
  Persona();
  Persona(Persona &&) = default;
  Persona(const Persona &) = default;
  Persona &operator=(Persona &&) = default;
  Persona &operator=(const Persona &) = default;
  ~Persona() = default;
 
  void ingresarDatos();
  std::string getNombre() const;
  std::string getApellido() const;
  short getEdad() const;
  std::string getDomicilio() const;
  long int getMatricula() const;
  void mostrarInformacion() const;

protected:
  std::string nombre;
  std::string apellido;
  short edad;
  std::string domicilio;
  long int matricula;
};

#endif // !PERSONA_HPP

