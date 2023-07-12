#include "../headers/Academy.hpp"

Academy::Academy(short id, std::string name) : id(id), name(name), numCareers(numCareers) {}

short Academy::getId() const { return this->id; }

const std::string Academy::getName() const { return this->name; }

void Academy::showInformation() const
{
  std::cout << "Id: " << this->id << std::endl;
  std::cout << "Academy: " << this->name << std::endl;
}

void Academy::addCareer(const Career &career)
{
  careers.push_back(career);
  std::cout << "Career added successfully\n";
  this->numCareers++;
}

void Academy::removeCareer(short id)
{
  auto it = std::find_if(careers.begin(), careers.end(), [id](const Career &career) {
    return career.getId() == id;
  });
  
  if(it != careers.end())
  {
    careers.erase(it);
    std::cout << "Career successfully removed\n";
    numCareers--;
  }
  else 
    std::cout << "Non-existent career\n";
}

Career& Academy::searchCareer(short id)
{
  auto it = std::find_if(careers.begin(), careers.end(), [id](const Career &career) {
    return career.getId() == id;
  });
  
  if(it != careers.end())
    return *it;
  else 
    throw std::runtime_error("Career not found\n");
}

void Academy::showCareers()
{
  if(careers.empty())
    std::cout << "No careers registered yet\n";
  else 
  {
    for(const Career& career : careers)
      career.showInformation();
  }
}
