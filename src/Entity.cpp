#include "../headers/Entity.hpp"

template<typename T>
void Entity<T>::addSubject(const T& subject)
{
  subjects.push_back(subject);
  std::cout << "Subject successfully added\n";
  numSubjects++;
}

template<typename T>
void Entity<T>::removeSubject(int id)
{
  if(id >= 0 && id < numSubjects)
  {
    subjects.erase(subjects.begin() + id);
    numSubjects--;
  }
}

template<typename T>
T& Entity<T>::searchSubject(int id)
{
  if(id >= 0 && id < numSubjects)
    return subjects[id];

  throw std::runtime_error("Subject no found\n");
}
