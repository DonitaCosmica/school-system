#include <cstdlib>
#include <array>
#include <forward_list>
#include <deque>
#include <unordered_map>

#include "./headers/Carrera.hpp"

void clear()
{
  std::cout << "\033[H\033[2J";
}

void creatingTeachers(std::forward_list<Carrera>&, std::unordered_map<std::string, std::deque<Profesor>>&);
void assignSubProfToCareer(std::forward_list<Carrera>&, std::unordered_map<std::string, std::deque<Profesor>>&);
void assignSubToStudents(std::forward_list<Carrera>&, std::unordered_map<std::string, std::forward_list<Alumno>>&);

int main (int argc, char *argv[]) 
{
  std::forward_list<Carrera> careers;
  std::forward_list<Carrera>::iterator ptrCareers;

  std::unordered_map<std::string, std::deque<Profesor>> professors;
  std::unordered_map<std::string, std::forward_list<Alumno>> students;
  
  careers.push_front(Carrera("Data Science", "Engineering"));
  ptrCareers = careers.insert_after(careers.begin(), Carrera("Biochemistry", "Health Sciences"));
  ptrCareers = careers.insert_after(ptrCareers, Carrera("Education", "Social Sciences"));

  creatingTeachers(careers, professors);
  assignSubProfToCareer(careers, professors);
  assignSubToStudents(careers, students);
 
  for(auto& [academy, list] : students)
  {
    std::cout << "\t--" << academy << " students--\n\n";
    
    for(Alumno& student : list)
    {
      student.mostrarDatos();
      std::cout << "Assigned subjects\n\n";
      student.verMaterias();
    } 
  }
}

void creatingTeachers(std::forward_list<Carrera> &careers, std::unordered_map<std::string, std::deque<Profesor>> &teachers)
{
  for(Carrera& career : careers)
  {
    char opt = 0;
    short id = 1, ans = 0;

    std::cout << career.getAcademia() << " teachers" << std::endl << std::endl;

    do
    {
      Profesor teacher;
      teacher.ingresarInformacion();

      teachers[career.getAcademia()].push_back(teacher);

      std::cout << "\nDo you want to enter another teacher?\n1. Yes\n2. No\n\n";
      std::cout << "Enter your answer: ";
      std::cin >> opt;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      ans = atoi(std::string(1, opt).c_str());
      std::cout << std::endl;
      
    } while(ans != 2);

    clear();
  }
}

void assignSubProfToCareer(std::forward_list<Carrera> &careers, std::unordered_map<std::string, std::deque<Profesor>> &professors)
{
  for(Carrera& career : careers)
  {
    char opt;
    short id = 1, ans = 0;

    std::cout << career.getNombre() << " subjects" << std::endl << std::endl;

    do 
    {
      Materia subject(id);
      subject.ingresarDatos();

      do
      {
        long int reg = 0;

        std::cout << "Assign a teacher to the subject\n\n";

        for(const auto& [academy, deque] : professors)
        {
          std::cout << "Professors:" << std::endl;

          for(const auto& professor : deque)
            std::cout << "\t- " << professor.getMatricula() << ": " << professor.getNombre() << professor.getApellido() << std::endl;
            
          std::cout << std::endl;
        }

        std::cout << "\nEnter the enrollment of the teacher to assign: ";
        std::cin >> reg;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        for(const auto& [academy, deque] : professors)
        {
          for(const auto& professor : deque)
          {
            if(professor.getMatricula() == reg)
              subject.agregarProfesor(professor);
          }
        }

        std::cout << "\nDo you want to enter another teacher?\n1. Yes\n2. No\n\n";
        std::cout << "Enter your answer: ";
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ans = atoi(std::string(1, opt).c_str());
        std::cout << std::endl;
        
      } while(ans != 2);

      clear();

      career.agregarMateria(subject);
      id++;

      std::cout << "\nDo you want to enter another subject?\n1. Yes\n2. No\n\n";
      std::cout << "Enter your answer: ";
      std::cin >> opt;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      ans = atoi(std::string(1, opt).c_str());
      std::cout << std::endl;
      
    } while(ans != 2);

    clear();
  }
}

void assignSubToStudents(std::forward_list<Carrera> &careers, std::unordered_map<std::string, std::forward_list<Alumno>> &students)
{
  for(Carrera& career : careers)
  {
    char opt;
    short id = 0, ans = 0;

    std::cout << career.getNombre() << " students" << std::endl << std::endl;

    do 
    {
      Alumno student;
      student.ingresarInformacion(career.getAcademia(), career.getNombre());

      do
      {
        career.verMaterias();
        std::cout << std::endl;

        std::cout << "Enter the id of the subject you want to assign to the student: ";
        std::cin >> id;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        student.agregarMateria(career.buscarMateria(id));

        std::cout << "\nDo you want to enter another subject?\n1. Yes\n2. No\n\n";
        std::cout << "Enter your answer: ";
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ans = atoi(std::string(1, opt).c_str());
        std::cout << std::endl;
        
      } while(ans != 2);

      clear();

      students[career.getNombre()].push_front(student);

      career.agregarAlumno(student);

      std::cout << "\nDo you want to enter another student?\n1. Yes\n2. No\n\n";
      std::cout << "Enter your answer: ";
      std::cin >> opt;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      ans = atoi(std::string(1, opt).c_str());
      std::cout << std::endl;
      
    } while(ans != 2);

    clear();
  }
}
