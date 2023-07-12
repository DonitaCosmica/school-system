#include "../headers/SubjStudent.hpp"

SubjStudent::SubjStudent() : Subject(0), score(0), grade(Attendance::FACE_TO_FACE) {}

float SubjStudent::getScore() const { return this->score; }

void SubjStudent::setData(SubjCareer &subject)
{
  this->id = subject.getId();
  this->name = subject.getName();
  this->semester = subject.getSemester();
}

void SubjStudent::enterData()
{  
  std::cout << "Enter the score of the subject: ";
  std::cin >> this->score;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter the type of assistance: \n\n";
  this->grade = selectClass(); 
}

void SubjStudent::showData()
{
  std::cout << "\t--INFORMATION--\n";
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Name: " << this->name << std::endl;
  std::cout << "Semester: " << this->semester << std::endl;
  std::cout << "Score: " << this->score << std::endl;
  std::cout << "Grade: " << toString(this->grade) << std::endl;
}

void SubjStudent::showTeachers()
{
  if(teachers.empty())
    std::cout << "There are no registered teachers yet\n";
  else 
  {
    for(Teacher& teacher : teachers)
    {
      std::cout << "-\t " << teacher.getName() << " " << teacher.getLastName() << ":\n"; 
    }
  }
}

Attendance SubjStudent::selectClass()
{
  int opt = 0;

  const std::string text[] =
  {
    "Face to face",
    "Online",
    "Absent"
  };

  for(int i = static_cast<int>(Attendance::FACE_TO_FACE); i <= static_cast<int>(Attendance::ABSENT); i++)
    std::cout << i + 1 << ". " << text[i] << std::endl;

  std::cout << "Enter your option: ";
  std::cin >> opt;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  return static_cast<Attendance>(opt - 1);
}

const std::string SubjStudent::toString(Attendance attendance)
{
  const std::string text[] = 
  {
    "Face to face",
    "Online",
    "Absent"
  };

  int index = static_cast<int>(attendance);

  if(index >= 0 && index < (sizeof(text) / sizeof(text[0])))
    return text[index];

  return "Unknown";
}
