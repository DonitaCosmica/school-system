#include "../headers/Career.hpp"

Career::Career(short id, std::string name, std::string academy) : id(id), name(name), academy(academy), numStudents(0) {}

Career& Career::operator=(const Career &other)
{
  if(this == &other)
    return *this;

  id = other.id;
  name = other.name;
  academy = other.academy;
  numStudents = other.numStudents;
  subjects = other.subjects;

  return *this;
}

short Career::getId() const { return this->id; }

std::string Career::getName() const { return this->name; }

std::string Career::getAcademy() const { return this->academy; }

void Career::showInformation() const
{
  std::cout << "\nId: " << this->id << std::endl;
  std::cout << "Academy name: " << this->academy << std::endl;
  std::cout << "Career name: " << this->name << std::endl; 
}

void Career::addStudent(const Student &student)
{
  students.push_back(student);
  std::cout << "Student added successfully\n";
  this->numStudents++;
}

void Career::removeStudent(long int reg)
{
  auto it = std::find_if(students.begin(), students.end(), [reg](const Student &student) {
    return student.getRegister() == reg;
  });

  if(it != students.end())
  {
    students.erase(it);
    std::cout << "Student successfully removed\n";
    numStudents--;
  }
  else
    std::cout << "Non-existent student\n";
}

Student& Career::searchStudent(long int reg)
{
  auto it = std::find_if(students.begin(), students.end(), [reg](const Student &student) {
    return student.getRegister() == reg;
  });

  if(it != students.end())
    return *it;
  else 
    throw std::runtime_error("Student not found\n");
}

void Career::showStudents()
{
  if(students.empty())
    std::cout << "No students registered yet\n";
  else 
  {
    for(const Student& student : students)
      std::cout << student.getName() << " " << student.getLastName() << ",\n";
  }
}

void Career::showSubjects()
{
  if(subjects.empty())
    std::cout << "There are no registered subjects\n";
  else 
  {
    for(SubjCareer& subject : subjects){
      std::cout << subject.getId() << ": " << subject.getName() << std::endl;
      std::cout << "Semester: " << subject.getSemester() << std::endl << std::endl;
      std::cout << "Assigned teacher\n";
      subject.showTeachers();
    }
  }
}
