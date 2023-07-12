#ifndef CARRERA_HPP
#define CARRERA_HPP

#include "./Student.hpp"
#include "./SubjCareer.hpp"

class Career : public Entity<SubjCareer> {
public:
  Career() = default;
  Career(Career &&) = default;
  Career(const Career &) = default;
  Career &operator=(Career &&) = default;
  Career &operator=(const Career &);
  ~Career() = default;

  explicit Career(short, std::string, std::string);
  short getId() const;
  std::string getName() const;
  std::string getAcademy() const;
  void showInformation() const;

  void addStudent(const Student&);
  void removeStudent(long int);
  Student &searchStudent(long int);
  void showStudents();
  void showSubjects() override;

private:
  short id;
  std::string name;
  std::string academy;
  int numStudents;
  std::list<Student> students;
};

#endif // !CARRERA_HPP
