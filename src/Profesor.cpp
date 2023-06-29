#include "../headers/Profesor.hpp"

Profesor::Profesor() : horas(0), tiempo(Tiempo::COMPLETO), titulo("") {}

Profesor& Profesor::operator=(const Profesor &other)
{
  if(this == &other)
    return *this;

  nombre = other.getNombre();
  apellido = other.getApellido();
  edad = other.getEdad();
  domicilio = other.getDomicilio();
  matricula = other.getMatricula();
  horas = other.horas;
  tiempo = other.tiempo;
  titulo = other.titulo;

  return *this;
}

void Profesor::ingresarInformacion()
{
  ingresarDatos();

  std::cout << "Ingrese horas laboradas: ";
  std::cin >> this->horas;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  std::cout << "Ingrese el tipo de trabajo: \n\n";
  this->tiempo = seleccionarTrabajo();

  std::cout << "Ingrese el titulo profesional: ";
  std::getline(std::cin, this->titulo, '\n');
}

Tiempo Profesor::seleccionarTrabajo()
{
  int opcion = 0;

  const std::string texto[] =
  {
    "Tiempo completo",
    "Medio tiempo"
  };

  for(int i = static_cast<int>(Tiempo::COMPLETO); i <= static_cast<int>(Tiempo::MEDIO); i++)
    std::cout << i + 1 << ". " << texto[i] << std::endl;

  std::cout << "Ingrese su opcion: ";
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return static_cast<Tiempo>(opcion - 1);
}

void Profesor::mostrarDatos()
{
  std::cout << "\tMatricula: " << this->matricula << std::endl;
  std::cout << "\tEdad: " << this->edad << std::endl;
  std::cout << "\tDomicilio: " << this->domicilio << std::endl;
  std::cout << "\tTrabajo: " << toString(tiempo) << std::endl;
  std::cout << "\tHoras: " << this->horas << std::endl;
  std::cout << "\tTitulo: " << this->titulo << std::endl;
}

const std::string Profesor::toString(Tiempo ts)
{ return (ts == Tiempo::MEDIO) ? "Medio tiempo" : "Tiempo completo"; }
