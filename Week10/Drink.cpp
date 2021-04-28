#include "Drink.h"

void Drink::copy(const Drink& other) {
  name = new char[std::strlen(other.name) + 1];
  std::strcpy(name, other.name);
  quantity = other.quantity;
}

void Drink::erase() {
  delete[] name;
}

Drink::Drink() {
  name = new char[1];
  name[0] = 0;
  quantity = 0;
}

Drink::Drink(const Drink& other) {
  copy(other);
}

Drink& Drink::operator=(const Drink& other) {
  if(this != &other) {
    erase();
    copy(other);
  }

  return *this;
}

Drink::~Drink() {
  erase();
}

Drink::Drink(const char* name, double quantity) {
  this->name = new char[std::strlen(name) + 1];
  std::strcpy(this->name, name);
  this->quantity = quantity;
}

void Drink::setQuantity(double q) {
  if(q > 0 && q <= quantity) {
    quantity -= q;
  }
}

double Drink::getQuantity() const {
  return quantity;
}