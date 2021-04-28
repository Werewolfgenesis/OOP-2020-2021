#include "AlcoholDrink.h"

inline AlcoholDrink::AlcoholDrink() : Drink(){
  percents = 20;
}

inline AlcoholDrink::AlcoholDrink(const char* name, double quantity, double percents) : Drink(name, quantity) {
  this->percents = percents;
}

inline void AlcoholDrink::drink(double quantity) {
  setQuantity(quantity);
}

inline void AlcoholDrink::show() const {
  std::cout<<"Rest: "<<getQuantity()<<'\n';
}
