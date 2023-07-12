#include <cstdlib>
#include <array>
#include <forward_list>
#include <deque>
#include <unordered_map>

#include "./headers/Academy.hpp"

void clear()
{
  std::cout << "\033[H\033[2J";
}

int main (int argc, char *argv[]) 
{
  Academy *ing = new Academy(1, "Ingenierias");

  Career career1(1, "Ciencia de Datos", ing->getName());
  Career career2(2, "Mecatronica", ing->getName());

  ing->addCareer(career1);
  ing->addCareer(career2);

  Teacher teacher;

  teacher.submitData();
  teacher.showData();
}
