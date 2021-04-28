#pragma once
#include "Drink.h"

class AlcoholDrink : public Drink
{
private:
  double percents;

public:
  AlcoholDrink();
  AlcoholDrink(const char *, double, double);
  AlcoholDrink(const AlcoholDrink &other);

  void drink(double) override;
  void show() const override;

  friend std::ostream &operator<<(std::ostream &out, const AlcoholDrink &other)
  {
    Drink *newDrink = new AlcoholDrink(other);
    out << *newDrink;
    out << "Percents: " << other.percents << '\n';

    return out;
  }
};

inline AlcoholDrink::AlcoholDrink() : Drink()
{
  percents = 20;
}

inline AlcoholDrink::AlcoholDrink(const char *name, double quantity, double percents) : Drink(name, quantity)
{
  this->percents = percents;
}

inline void AlcoholDrink::drink(double quantity)
{
  setQuantity(quantity);
}

inline void AlcoholDrink::show() const
{
  std::cout << "Rest: " << getQuantity() << '\n';
}

AlcoholDrink::AlcoholDrink(const AlcoholDrink &other) : Drink(other)
{
  this->percents = other.percents;
}