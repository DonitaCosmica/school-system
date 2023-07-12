#include "../headers/Person.hpp"

Person::Person() : age(0), reg(0) {}

void Person::submitData()
{
  std::cout << "Enter the name: ";
  std::getline(std::cin, this->name, '\n');

  std::cout << "Enter the last name: ";
  std::getline(std::cin, this->lastName, '\n');

  std::cout << "Enter the age: ";
  std::cin >> this->age;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter the address: ";
  std::getline(std::cin, this->address, '\n');

  std::cout << "Enter the register: ";
  std::cin >> reg;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Person::getName() const { return this->name; }

std::string Person::getLastName() const { return this->lastName; }

short Person::getAge() const { return this->age; }

std::string Person::getAddress() const { return this->address; }

long int Person::getRegister() const { return this->reg; }

void Person::showData()
{
  std::cout << "\t--INFORMATION--\n\n";
  std::cout << "Register: " << this->reg << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Last name: " << this->lastName << std::endl;
  std::cout << "Age: " << this->age << std::endl;
  std::cout << "Address: " << this->address << std::endl;
}
