#include "NonAlcoholDrink.h"

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
