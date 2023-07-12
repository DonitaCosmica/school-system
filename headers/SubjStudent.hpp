#ifndef SUBJSTUDENT_HPP
#define SUBJSTUDENT_HPP

#include "./Subject.hpp"
#include "./SubjCareer.hpp"
#include "../enums/Attendance.hpp"

class SubjStudent : public Subject {
public:
  explicit SubjStudent();
  SubjStudent(SubjStudent &&) = default;
  SubjStudent(const SubjStudent &) = default;
  SubjStudent &operator=(SubjStudent &&) = default;
  SubjStudent &operator=(const SubjStudent &) = default;
  ~SubjStudent() = default;
  
  float getScore() const;
  void setData(SubjCareer&);
  void enterData() override;
  void showData() override;
  void showTeachers() override;

private:
  float score;
  Attendance grade;

  Attendance selectClass();
  const std::string toString(Attendance);
};

#endif // !SUBJSTUDENT_HPP
