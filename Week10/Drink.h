#pragma once
#include <cstring>
#include <iostream>

class Drink
{
private:
  char *name;
  double quantity;

  void copy(const Drink &);
  void erase();

public:
  Drink();
  Drink(const Drink &);
  Drink &operator=(const Drink &);
  ~Drink();

  Drink(const char *, double);

  void setQuantity(double);
  double getQuantity() const;

  virtual void drink(double) = 0;
  virtual void show() const = 0;

  friend std::ostream &operator<<(std::ostream &out, const Drink &other)
  {
    out << "Name of the drink: ";
    for (size_t i = 0; i < std::strlen(other.name); i++)
    {
      out << other.name[i];
    }
    out << '\n';
    out << "Quantity: " << other.quantity << '\n';

    return out;
  }
};

void Drink::copy(const Drink &other)
{
  name = new char[std::strlen(other.name) + 1];
  std::strcpy(name, other.name);
  quantity = other.quantity;
}

void Drink::erase()
{
  delete[] name;
}

Drink::Drink()
{
  name = new char[1];
  name[0] = 0;
  quantity = 0;
}

Drink::Drink(const Drink &other)
{
  copy(other);
}

Drink &Drink::operator=(const Drink &other)
{
  if (this != &other)
  {
    erase();
    copy(other);
  }

  return *this;
}

Drink::~Drink()
{
  erase();
}

Drink::Drink(const char *name, double quantity)
{
  this->name = new char[std::strlen(name) + 1];
  std::strcpy(this->name, name);
  this->quantity = quantity;
}

void Drink::setQuantity(double q)
{
  if (q > 0 && q <= quantity)
  {
    quantity -= q;
  }
}

double Drink::getQuantity() const
{
  return quantity;
}