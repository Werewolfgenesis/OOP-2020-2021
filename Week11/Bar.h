#pragma once
#include <vector>
#include <cstring>
#include "AlcoholDrink.h"
#include "NonAlcoholDrink.h"
class Bar
{
public:
  //Bar();
  Bar(const std::string &name = "Default");
  //Drink* - указател към обект от тип Drink
  //const Drink* - константен указател
  //Drink&- референция
  //const Drink& - константна референция към обект от тип Drink
  //const Drink*& - константна референция към указател към обект от тип Drink
  void addDrink(const std::vector<Drink *> &);
  void print() const;

  void sell(const std::vector<Drink *> &);

private:
  std::string name;
  std::vector<Drink *> drinks;
  std::vector<Drink *> soldDrinks;
};

#include "Bar.cpp"