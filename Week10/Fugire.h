#pragma once
#include <iostream>
#include <string>

class Figure
{
private:
  std::string label;

public:
  Figure()
  {
    label = "label";
  }
  Figure(const std::string& l) {
    label = l;
  }
  std::string getLabel() const {
    return label;
  }
  void setLabel(std::string l) {
    label = l;
  }
  virtual double findArea() const = 0;
  virtual double findPerimeter() const = 0;
  virtual void print() const
  {
    std::cout << label;
  }
};