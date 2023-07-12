#include "../headers/Subject.hpp"

Subject::Subject(int id) : id(id), semester(0), numTeachers(0) {}

int Subject::getId() const { return this->id; }

const std::string Subject::getName() const { return this->name; }

short Subject::getSemester() const { return this->semester; }

void Subject::addTeacher(const Teacher &teacher)
{
  teachers.push_back(teacher);
  std::cout << "Teacher added successfully\n";
  this->numTeachers++;
}

void Subject::removeTeacher(long int reg)
{
  auto it = std::find_if(teachers.begin(), teachers.end(), [reg](const Teacher &teacher) {
    return teacher.getRegister() == reg;
  });

  if(it != teachers.end())
  {
    teachers.erase(it);
    std::cout << "Teacher removed successfully\n";
    this->numTeachers--;
  }
  else 
    std::cout << "Nonexistent teacher\n";
}

Teacher& Subject::searchTeacher(long int reg)
{
  auto it = std::find_if(teachers.begin(), teachers.end(), [reg](const Teacher &teacher) {
    return teacher.getRegister() == reg;
  });

  if(it != teachers.end())
    return *it;
  else 
    throw std::runtime_error("Teacher not found");
}
