#include <iostream>
#include "AlcoholDrink.h"
#include "NonAlcoholDrink.h"
#include <vector>

int main()
{
  AlcoholDrink ad("Rum", 1000, 40);
  NonAlcoholDrink nad("Cola", 1000);
  Drink *alDrink = new AlcoholDrink("Vodka", 1000, 40);
  Drink *nalDrink = new NonAlcoholDrink("Orange juice", 1000);

  // std::cout<<*alDrink;
  // std::cout<<ad; // -> override
  // std::cout<<nad;
  std::vector<Drink*> drinks;
  drinks.push_back(alDrink);
  drinks.push_back(nalDrink);

  for (auto el : drinks)
  {
    std::cout << *el;
  }

  return 0;
}