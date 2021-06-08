#pragma once
#include <string>

class WorkItem {
protected:
  std::string _name; 

public:
  WorkItem(const std::string& name) {
    this->_name = name;
  }
  virtual bool status(long now) const = 0;
  virtual std::string name() const {
    return _name;
  }
};