#ifndef PERSONA_HPP
#define PERSONA_HPP

#include <iostream>
#include <string>
#include <limits>

class Person 
{
public:
  Person();
  Person(Person &&) = default;
  Person(const Person &) = default;
  Person &operator=(Person &&) = default;
  Person &operator=(const Person &) = default;
  virtual ~Person() = default;
 
  virtual void submitData();
  virtual void showData();

  std::string getName() const;
  std::string getLastName() const;
  short getAge() const;
  std::string getAddress() const;
  long int getRegister() const;

protected:
  std::string name;
  std::string lastName;
  short age;
  std::string address;
  long int reg;
};

#endif // !PERSONA_HPP

