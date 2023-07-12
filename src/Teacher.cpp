#include "../headers/Teacher.hpp"

Teacher::Teacher() : hours(0), time(Time::FULL), degree(Bachelor::BS) {}

Teacher& Teacher::operator=(const Teacher &other)
{
  if(this == &other)
    return *this;

  name = other.getName();
  lastName = other.getLastName();
  age = other.getAge();
  address = other.getAddress();
  reg = other.getRegister();
  hours = other.hours;
  time = other.time;
  degree = other.degree;

  return *this;
}

void Teacher::submitData()
{
  Person::submitData();

  std::cout << "Enter the hours worked: ";
  std::cin >> this->hours;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  std::cout << "Enter the type of work: \n\n";
  this->time = selectJob();

  std::cout << "\nEnter the degree:\n";
  this->degree = selectDegree();
}

void Teacher::showData()
{
  Person::showData();
  std::cout << "Job: " << jobToString(this->time) << std::endl;
  std::cout << "Hours: " << this->hours << std::endl;
  std::cout << "Degree: " << degreeToString(this->degree) << " degree" << std::endl;
}

Time Teacher::selectJob()
{
  const std::string text[] =
  {
    "Full time",
    "Part time"
  };

  int size = sizeof(text) / sizeof(text[0]);

  for(int i = 0; i < size; i++)
    std::cout << i + 1 << ": " << text[i] << std::endl;

  int opt = readOption(1, size); 
  
  return static_cast<Time>(opt - 1);
}

Degree Teacher::selectDegree()
{
  std::map<std::string, std::vector<std::string>> data = 
  {
    { "Associate", { " of Arts", " of Science" } },
    { "Bachelor", { " of Arts", " of Science", " of Fine Arts", " of Architecture" } },
    { "Master", { " of Arts", " of Science", " of Fine Arts", " of Business Administration" } },
    { "Doctor", { " of Philosophy", " of Medecine", " of Pharmacy", " of Medecine in Denistry", " of Juridical Science" } }
  };

  printOptions(data); 
  int opt1 = readOption(1, data.size());
  auto it = std::next(data.begin(), opt1 - 1);

  std::cout << "\nSelected degree: " << it->first << std::endl;
  std::cout << "Degree options:";

  const auto& options = it->second;
  
  int i = 1;

  for(const auto& value : options)
  {
    std::cout << std::endl << i << " " << it->first << value;
    i++;
  }

  std::cout << std::endl;

  int opt2 = readOption(1, options.size()); 

  switch (opt1) 
  {
    case 1:
      return static_cast<Associate>(opt2 - 1);

    case 2:
      return static_cast<Bachelor>(opt2 - 1);

    case 3:
      return static_cast<Graduate>(opt2 - 1);

    case 4:
      return static_cast<Doctoral>(opt2 - 1);
  }

  return Bachelor::BS;
}

const std::string Teacher::jobToString(Time ts) const
{ 
  return (ts == Time::PART) ? "Part time" : "Full time"; 
}

const std::string Teacher::degreeToString(Degree degree) const
{
  std::map<std::string, std::vector<std::string>> data = 
  {
    { "Associate", { " of Arts", " of Science" } },
    { "Bachelor", { "of Arts", " of Science", " of Fine Arts", " of Architecture" } },
    { "Master", { " of Arts", " of Science", " of Fine Arts", "of Business Administration" } },
    { "Doctor", { " of Philosophy", " of Medecine", " of Pharmacy", " of Medecine in Denistry", " of Juridical Science" } }
  };

  if(std::holds_alternative<Associate>(degree))
    return "Associate" + data["Associate"][static_cast<int>(std::get<Associate>(degree))];
  else if(std::holds_alternative<Bachelor>(degree))
    return "Bachelor" + data["Bachelor"][static_cast<int>(std::get<Bachelor>(degree))];
  else if(std::holds_alternative<Graduate>(degree))
    return "Graduate" + data["Graduate"][static_cast<int>(std::get<Graduate>(degree))];
  else if(std::holds_alternative<Doctoral>(degree))
    return "Doctoral" + data["Doctoral"][static_cast<int>(std::get<Doctoral>(degree))];

  return "Unknown";
}

void Teacher::printOptions(const std::map<std::string, std::vector<std::string>> &data) const
{
  int i = 1;

  for(const auto& category : data)
  {
    std::cout << i << ": " << category.first << std::endl;
    i++;
  }
}

int Teacher::readOption(int min, int max) const
{
  int option = 0;

  std::cout << "\nEnter the number of your option: ";
  std::cin >> option;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while(option < min || option > max)
  {
    std::cout << "\nInvalid option. Please enter a valid option: ";
    std::cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  return option;
}
