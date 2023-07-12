#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <map>

#include "./Entity.hpp"
#include "./SubjStudent.hpp"
#include "../enums/State.hpp"

class Student : public Person, Entity<SubjStudent> {
public:
  explicit Student();
  Student(Student &&) = default;
  Student(const Student &) = default;
  Student &operator=(Student &&) = default;
  Student &operator=(const Student&);
  ~Student() = default;
  
  void setData(std::string, std::string);
  virtual void submitData();
  virtual void showData();
  void showSubjects() override;

private:
  // Atributos
  State campus;
  std::string academicArea;
  std::string career;
  
  // Metodos
  State selectCampus();
  const std::string toString(State);
  static const std::map<State, std::string> stateName;
  const std::function<float()> getAverage = [this]() -> float 
  {
    if(subjects.empty())
      return 0.00;

    float total = 0.0;
    for(const SubjStudent& subject : subjects)
      total += subject.getScore();

    return total / subjects.size();
  }; 
};

#endif // !ALUMNO_HPP
