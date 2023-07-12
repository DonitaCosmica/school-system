#ifndef SUBJCAREER_HPP
#define SUBJCAREER_HPP

#include "./Subject.hpp"

class SubjCareer : public Subject {
public:
  SubjCareer() = default;
  SubjCareer(SubjCareer &&) = default;
  SubjCareer(const SubjCareer &) = default;
  SubjCareer &operator=(SubjCareer &&) = default;
  SubjCareer &operator=(const SubjCareer &) = default;
  ~SubjCareer() = default;

  explicit SubjCareer(int);
  void enterData() override;
  void showData() override;
  void showTeachers() override;

private:
  int credits;
  short hours;
  short numClasses;
};

#endif // !SUBJCAREER_HPP
