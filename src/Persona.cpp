#include "../headers/Persona.hpp"

Persona::Persona() {}

void Persona::ingresarDatos()
{
  char delimitador = '\n';

  std::cout << "Ingrese el nombre: ";
  std::getline(std::cin, this->nombre, delimitador);

  std::cout << "Ingrese el apellido: ";
  std::getline(std::cin, this->apellido, delimitador);

  std::cout << "Ingrese la edad: ";
  std::cin >> this->edad;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimitador);

  std::cout << "Ingrese el domicilio: ";
  std::getline(std::cin, this->domicilio, delimitador);

  std::cout << "Ingrese la matricula: ";
  std::cin >> matricula;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimitador);
}

std::string Persona::getNombre() const { return this->nombre; }

std::string Persona::getApellido() const { return this->apellido; }

short Persona::getEdad() const { return this->edad; }

std::string Persona::getDomicilio() const { return this->domicilio; }

long int Persona::getMatricula() const { return this->matricula; }

void Persona::mostrarInformacion() const
{
  std::cout << "\t--INFORMACION--\n\n";
  std::cout << "Matricula: " << this->matricula << std::endl;
  std::cout << "Nombre: " << this->nombre << std::endl;
  std::cout << "Apellido: " << this->apellido << std::endl;
  std::cout << "Edad: " << this->edad << std::endl;
  std::cout << "Domicilio: " << this->domicilio << std::endl;
}
