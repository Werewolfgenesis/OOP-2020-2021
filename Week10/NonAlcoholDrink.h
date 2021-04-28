#pragma once
#include "Drink.h"

class NonAlcoholDrink : public Drink {
public:
  NonAlcoholDrink();
  NonAlcoholDrink(const char*, double);

  void drink(double) override;
  void show() const override;

  
};

inline NonAlcoholDrink::NonAlcoholDrink() : Drink(){
}

inline NonAlcoholDrink::NonAlcoholDrink(const char* name, double quantity) : Drink(name, quantity) {
}

inline void NonAlcoholDrink::drink(double quantity) {
  setQuantity(quantity);
}

inline void NonAlcoholDrink::show() const {
  std::cout<<"Rest: "<<getQuantity()<<'\n';
}


