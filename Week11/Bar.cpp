#include "Bar.h"

Bar::Bar(const std::string &name)
{
  this->name = name;
}

void Bar::addDrink(const std::vector<Drink *> &drinks)
{
  for (size_t i = 0; i < drinks.size(); ++i)
  {
    this->drinks.push_back(drinks[i]);
  }
}

void Bar::print() const
{
  for (size_t i = 0; i < this->drinks.size(); ++i)
  {
    std::cout << *this->drinks[i];
  }
}

void Bar::sell(const std::vector<Drink *> &drinks)
{
  for (size_t i = 0; i < drinks.size(); ++i)
  {
    for (size_t j = 0; j < this->drinks.size(); ++j)
    {
      if (drinks[i] == this->drinks[j])
      {
        this->soldDrinks.push_back(this->drinks[j]);
        this->drinks.erase(this->drinks.begin() + j);
      }
    }
  }
}
