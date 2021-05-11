#include <iostream>
#include "Bar.h"

int main()
{
  Drink *ad = new AlcoholDrink("Rum", 1000, 40);
  Drink *nad = new NonAlcoholDrink("Cola", 1000);
  Drink *alDrink = new AlcoholDrink("Vodka", 1000, 40);
  Drink *nalDrink = new NonAlcoholDrink("Orange juice", 1000);
  Bar club("33");
  std::vector<Drink *> drinks = {alDrink, nalDrink, ad, nad};
  club.addDrink(drinks);
  club.sell(drinks);
  club.print();
  return 0;
}