#include "../headers/Materia.hpp"

Materia::Materia(int id) : id(id), numProfesores(0) {}

Materia& Materia::operator=(const Materia &other)
{
  if(this == &other)
    return *this;

  id = other.id;
  nombre = other.nombre;
  semestre = other.semestre;
  horas = other.horas;
  numClases = other.numClases;
  creditos = other.creditos;
  clase = other.clase;

  return *this;
}

void Materia::ingresarDatos()
{
  char delimitador = '\n';

  std::cout << "Ingrese el nombre de la materia: ";
  std::getline(std::cin, this->nombre, delimitador);

  std::cout << "Ingrese el semestre de la materia: ";
  std::cin >> this->semestre;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Ingrese las horas de la materia: ";
  std::cin >> this->horas;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Ingrese el numero de clases de la materia a la semana: ";
  std::cin >> this->numClases;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Ingrese el tipo de asistencia: \n\n";
  this->clase = seleccionarClase();
}

Asistencia Materia::seleccionarClase()
{
  int opcion = 0;

  const std::string texto[] =
  {
    "Presencial",
    "Online",
    "Ausente"
  };

  for(int i = static_cast<int>(Asistencia::PRESENCIAL); i <= static_cast<int>(Asistencia::AUSENTE); i++)
    std::cout << i + 1 << ". " << texto[i] << std::endl;

  std::cout << "Ingrese su opcion: ";
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return static_cast<Asistencia>(opcion - 1);
}

int Materia::getId() const { return this->id; }

const std::string Materia::getNombre() const { return this->nombre; }

void Materia::agregarProfesor(const Profesor &profesor)
{
  profesores.push_back(profesor);
  std::cout << "Alumno agregado exitosamente\n";
}

void Materia::eliminarProfesor(long int matricula)
{
  auto it = std::find_if(profesores.begin(), profesores.end(), [matricula](const Profesor &profesor) {
    return profesor.getMatricula() == matricula;
  });

  if(it != profesores.end())
  {
    profesores.erase(it);
    std::cout << "Profesor eliminado exitosamente\n";
  }
  else 
    std::cout << "Profesor inexistente\n";
}

void Materia::mostrarProfesores()
{
  if(profesores.empty())
    std::cout << "No hay profesores registrados aun\n";
  else 
  {
    for(Profesor& profesor : profesores)
    {
      std::cout << "-\t " << profesor.getNombre() << " " << profesor.getApellido() << ":\n";
      profesor.mostrarDatos();
    }
  }
}

Profesor& Materia::buscarProfesor(long int matricula)
{
  auto it = std::find_if(profesores.begin(), profesores.end(), [matricula](const Profesor &profesor) {
    return profesor.getMatricula() == matricula;
  });

  if(it != profesores.end())
    return *it;
  else 
    throw std::runtime_error("Profesor no encontrado");
}

void Materia::mostrarDatos()
{
  std::cout << "\t--INFORMACION--\n";
  std::cout << "Nombre de la clase: " << this->nombre << std::endl;
  std::cout << "Semestre: " << this->semestre << std::endl;
  std::cout << "Horas por semana: " << this->horas << std::endl;
  std::cout << "Clases totales: " << this->numClases << std::endl;
  std::cout << "Numero de creditos: " << this->creditos << std::endl;
  std::cout << "Asistencia: " << toString(this->clase) << std::endl;
}

const std::string Materia::toString(Asistencia asistencia)
{
  const std::string texto[] = 
  {
    "Presencial",
    "Online",
    "Ausente"
  };

  int index = static_cast<int>(asistencia);

  if(index >= 0 && index < (sizeof(texto) / sizeof(texto[0])))
    return texto[index];

  return "Desconocido";
}
