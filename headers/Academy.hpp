#ifndef ACADEMY_HPP
#define ACADEMY_HPP

#include "./Career.hpp"

class Academy final {
public:
  Academy() = default;
  Academy(Academy &&) = default;
  Academy(const Academy &) = default;
  Academy &operator=(Academy &&) = default;
  Academy &operator=(const Academy &) = default;
  ~Academy() = default;

  explicit Academy(short, std::string);
  short getId() const;
  const std::string getName() const;
  void showInformation() const;

  void addCareer(const Career&);
  void removeCareer(short);
  Career& searchCareer(short);
  void showCareers();

private:
  short id;
  std::string name;
  short numCareers;
  std::vector<Career> careers; 
};

#endif // !ACADEMY_HPP
