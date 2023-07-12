#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <vector>

template<typename T>
class Entity {
public:
  Entity() : numSubjects(0) {}
  Entity(Entity &&) = default;
  Entity(const Entity &) = default;
  Entity &operator=(Entity &&) = default;
  Entity &operator=(const Entity &) = default;
  virtual ~Entity() = default;

protected:
  void addSubject(const T&);
  void removeSubject(int);
  T &searchSubject(int);
  virtual void showSubjects() = 0;

  std::vector<T> subjects;

private:
  int numSubjects; 
};

#endif // !ENTITY_HPP
