#pragma once
#include "Fugire.h"

class Circle : public Figure
{
private:
  double r;
  
public: 
  Circle() : Figure("circle") {
    r = 3;
  }

  double findArea() const override
  {
    std::cout << "fasjdkl";
  }

  double findPerimeter() const override
  {
    std::cout << "dfsajk";
  }

  void print() const override
  {
    std::cout << getLabel() << " " << r;
  }
};