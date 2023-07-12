#include "../headers/SubjCareer.hpp"

SubjCareer::SubjCareer(int id) : Subject(id), hours(0), numClasses(0) {}

void SubjCareer::enterData()
{
  char delimiter = '\n';

  std::cout << "Enter the name of the subject: ";
  std::getline(std::cin, this->name, delimiter);

  std::cout << "Enter the semester of the subject: ";
  std::cin >> this->semester;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimiter);

  std::cout << "Enter the credits of the subject: ";
  std::cin >> this->credits;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter the hours of the subject: ";
  std::cin >> this->hours;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimiter);

  std::cout << "Enter the number of classes of the subject per week: ";
  std::cin >> this->numClasses;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), delimiter);
}

void SubjCareer::showData()
{
  std::cout << "\t--INFORMATION--\n";
  std::cout << "Name of the class: " << this->name << std::endl;
  std::cout << "Semester: " << this->semester << std::endl;
  std::cout << "Hours per week: " << this->hours << std::endl;
  std::cout << "Clases totales: " << this->numClasses << std::endl;
  std::cout << "Numero de creditos: " << this->credits << std::endl;
}

void SubjCareer::showTeachers()
{
  if(teachers.empty())
    std::cout << "There are no registered teachers yet\n";
  else 
  {
    for(Teacher& teacher : teachers)
      teacher.showData(); 
  } 
}
