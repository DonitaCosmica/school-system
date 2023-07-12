#include "../headers/Student.hpp"

Student::Student() : campus(State::JAL) {}

Student& Student::operator=(const Student &other)
{
  if(this == &other)
    return *this;

  name = other.getName();
  lastName = other.getLastName();
  age = other.getAge();
  address = other.getAddress();
  reg = other.getRegister();
  campus = other.campus;
  academicArea = other.academicArea;
  career = other.career;
  subjects = other.subjects;

  return *this; 
}

void Student::setData(std::string academicArea, std::string career)
{
  this->academicArea = academicArea;
  this->career = career;
}

void Student::submitData()
{
  Person::submitData();
  
  std::cout << "Enter the campus: \n\n";
  this->campus = selectCampus();
}

void Student::showData()
{
  Person::showData();
  std::cout << "Campus: " << toString(this->campus) << std::endl;
  std::cout << "Academic Area: " << this->academicArea << std::endl;
  std::cout << "Career: " << this->career << std::endl;
  std::cout << "Total Average: " << getAverage() << std::endl;
}

State Student::selectCampus()
{
  std::string name;
  State state;
  int opt = 0;

  for(int i = static_cast<int>(State::AGS); i <= static_cast<int>(State::YUC); i++)
  {
    state = static_cast<State>(i);
    name = toString(state);

    std::cout << i + 1 <<". " << name << std::endl;
  }

  std::cout << "Enter your option: ";
  std::cin >> opt;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return static_cast<State>(opt - 1);
}

void Student::showSubjects()
{
  if(subjects.empty())
    std::cout << "There are no registered subjects\n";
  else 
  {
    for(SubjStudent& subject : subjects){
      std::cout << subject.getId() << ": " << subject.getName() << std::endl;
      std::cout << "Semester: " << subject.getSemester() << std::endl << std::endl;
      std::cout << "Assigned teacher\n";
      subject.showTeachers();
    }
  }
}

const std::map<State, std::string> Student::stateName
{
  { State::AGS, "Aguascalientes" },
  { State::BC, "Baja California" },
  { State::CDMX, "Ciudad de Mexico" },
  { State::CHIS, "Chiapas" },
  { State::CHIH, "Chihuahua" },
  { State::COAH, "Coahuila" },
  { State::EDMX, "Esta de Mexico" },
  { State::JAL, "Jalisco" },
  { State::MOR, "Morelos" },
  { State::NL, "Nuevo Leon" },
  { State::PUE, "Puebla" },
  { State::QRO, "Queretaro" },
  { State::SLP, "San Luis POtosi" },
  { State::SON, "Sonora" },
  { State::TAB, "Tabasco" },
  { State::TAMPS, "Tamaulipas" },
  { State::VER, "Veracruz" },
  { State::YUC, "Yucatan"}
};

const std::string Student::toString(State state)
{
  auto it = stateName.find(state);

  if(it != stateName.end())
    return it->second;

  return "Ninguno";
}
