#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <list>
#include <algorithm>

#include "./Teacher.hpp"

class Subject 
{
public:
  Subject() = default;
  Subject(Subject &&) = default;
  Subject(const Subject &) = default;
  Subject &operator=(Subject &&) = default;
  Subject &operator=(const Subject &) = default;
  virtual ~Subject() = default;
   
  Subject(int); 
  int getId() const;
  const std::string getName() const;
  short getSemester() const;

  void addTeacher(const Teacher&);
  void removeTeacher(long int); 
  Teacher &searchTeacher(long int);

  virtual void enterData() = 0;
  virtual void showData() = 0; 
  virtual void showTeachers() = 0;

protected:
  // Atributos
  int id;
  std::string name;
  short semester;
  short numTeachers;
  std::list<Teacher> teachers;
};

#endif // !MATERIA_HPP
