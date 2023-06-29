#include "../headers/Carrera.hpp"

Carrera::Carrera(std::string nombre, std::string academia) : nombre(nombre), academia(academia), numAlumnos(0) {}

std::string Carrera::getNombre() const { return this->nombre; }

std::string Carrera::getAcademia() const { return this->academia; }

void Carrera::agregarAlumno(const Alumno &alumno)
{
  alumnos.push_back(alumno);
  std::cout << "Alumno agregado exitosamente\n";
}

void Carrera::eliminarAlumno(long int matricula)
{
  auto it = std::find_if(alumnos.begin(), alumnos.end(), [matricula](const Alumno &alumno) {
    return alumno.getMatricula() == matricula;
  });

  if(it != alumnos.end())
  {
    alumnos.erase(it);
    std::cout << "Alumno eliminado exitosamente\n";
  }
  else
    std::cout << "Alumno inexistente\n";
}

Alumno& Carrera::buscarAlumno(long int matricula)
{
  auto it = std::find_if(alumnos.begin(), alumnos.end(), [matricula](const Alumno &alumno) {
    return alumno.getMatricula() == matricula;
  });

  if(it != alumnos.end())
    return *it;
  else 
    throw std::runtime_error("Alumno no encontrado");
}

void Carrera::mostrarAlumnos()
{
  if(alumnos.empty())
    std::cout << "No hay alumnos registrados aun\n";
  else 
  {
    for(const Alumno& alumno : alumnos)
      std::cout << alumno.getNombre() << " " << alumno.getApellido() << ",\n";
  }
}

void Carrera::agregarMateria(const Materia &materia)
{
  materias.push_back(materia);
  std::cout << "Materia agregada exitosamente\n";
}

int Carrera::materiaExistente(int id)
{
  for(int i = 0; i < materias.size(); i++)
  {
    if(id == materias[i].getId())
      return i;
  }

  return -1;
}

void Carrera::eliminarMateria(int id)
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

Materia& Carrera::buscarMateria(int id)
{
  for(Materia& materia : materias)
  {
    if(materia.getId() == id)
      return materia;
  }

  throw std::runtime_error("Materia no encontrada");
}

void Carrera::verMaterias()
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

void Carrera::mostrarDatos()
{
  std::cout << "Nombre de la academia: " << this->academia << std::endl;
  std::cout << "Nombre de la carrera: " << this->nombre << std::endl << std::endl; 
}
