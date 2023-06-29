#include "../headers/Alumno.hpp"

Alumno::Alumno() : numMaterias(0) {}

Alumno& Alumno::operator=(const Alumno &other)
{
  if(this == &other)
    return *this;

  nombre = other.getNombre();
  apellido = other.getApellido();
  edad = other.getEdad();
  domicilio = other.getDomicilio();
  matricula = other.getMatricula();
  campus = other.campus;
  areaAcademica = other.areaAcademica;
  carrera = other.carrera;

  return *this; 
}

void Alumno::ingresarInformacion(std::string areaAcademica, std::string carrera)
{
  char delimitador = '\n';

  ingresarDatos();
  
  std::cout << "Ingrese el campus: \n\n";
  this->campus = seleccionarCampus();

  this->areaAcademica = areaAcademica;
  this->carrera = carrera;
}

Estado Alumno::seleccionarCampus()
{
  std::string nombre;
  Estado estado;
  int opcion = 0;

  for(int i = static_cast<int>(Estado::AGS); i <= static_cast<int>(Estado::YUC); i++)
  {
    estado = static_cast<Estado>(i);
    nombre = toString(estado);

    std::cout << i + 1 <<". " << nombre << std::endl;
  }

  std::cout << "Ingrese su opcion: ";
  std::cin >> opcion;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return static_cast<Estado>(opcion - 1);
}

void Alumno::agregarMateria(const Materia &materia)
{
  materias.push_back(materia);
  std::cout << "Materia agregada exitosamente\n";
}

int Alumno::materiaExistente(int id)
{
  for(int i = 0; i < materias.size(); i++)
  {
    if(id == materias[i].getId())
      return i;
  }

  return -1;
}

void Alumno::eliminarMateria(int id)
{
  int indiceMateria = materiaExistente(id);

  if(indiceMateria != -1)
  {
    materias.erase(materias.begin() + indiceMateria);
    std::cout << "Materia eliminada exitosamente\n";
  }
  else
    std::cout << "Materia inexistente\n";
}

void Alumno::mostrarDatos()
{
  mostrarInformacion();
  std::cout << "Campus: " << toString(this->campus) << std::endl;
  std::cout << "Area Academica: " << this->areaAcademica << std::endl;
  std::cout << "Carrera: " << this->carrera << std::endl;
}

const std::map<Estado, std::string> Alumno::estadoToString
{
  { Estado::AGS, "Aguascalientes" },
  { Estado::BC, "Baja California" },
  { Estado::CDMX, "Ciudad de Mexico" },
  { Estado::CHIS, "Chiapas" },
  { Estado::CHIH, "Chihuahua" },
  { Estado::COAH, "Coahuila" },
  { Estado::EDMX, "Esta de Mexico" },
  { Estado::JAL, "Jalisco" },
  { Estado::MOR, "Morelos" },
  { Estado::NL, "Nuevo Leon" },
  { Estado::PUE, "Puebla" },
  { Estado::QRO, "Queretaro" },
  { Estado::SLP, "San Luis POtosi" },
  { Estado::SON, "Sonora" },
  { Estado::TAB, "Tabasco" },
  { Estado::TAMPS, "Tamaulipas" },
  { Estado::VER, "Veracruz" },
  { Estado::YUC, "Yucatan"}
};

const std::string Alumno::toString(Estado cp)
{
  auto it = estadoToString.find(cp);

  if(it != estadoToString.end())
    return it->second;

  return "Ninguno";
}

Materia& Alumno::buscarMateria(int id)
{
  for(Materia& materia : materias)
  {
    if(materia.getId() == id)
      return materia;
  }

  throw std::runtime_error("Materia no encontrada");
}

void Alumno::verMaterias()
{
  if(materias.empty())
    std::cout << "No hay materias registradas\n";
  else 
  {
    for(Materia& materia : materias){
      std::cout << materia.getId() << ": " << materia.getNombre() << ",\n\n";
      std::cout << "Profesores asigandos\n";
      materia.mostrarProfesores();
    }
  }
}
