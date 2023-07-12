#ifndef PROFESOR_H
#define PROFESOR_H

#include <vector>
#include <variant>
#include <map>
#include "./Person.hpp"
#include "../enums/Time.hpp"
#include "../enums/Degree.hpp"

using Degree = std::variant<Associate, Bachelor, Graduate, Doctoral>;

class Teacher : public Person
{
public:
  explicit Teacher();
  Teacher(Teacher &&) = default;
  Teacher(const Teacher &) = default;
  Teacher &operator=(Teacher &&) = default;
  Teacher &operator=(const Teacher &);
  ~Teacher() = default;
 
  virtual void submitData();
  virtual void showData(); 

private:
  int hours;
  Time time;
  Degree degree;

  Time selectJob();
  Degree selectDegree();
  const std::string jobToString(Time) const;
  const std::string degreeToString(Degree) const;

  void printOptions(const std::map<std::string, std::vector<std::string>>&) const;
  int readOption(int, int) const;
};

#endif 
