#pragma once
#include "ClosedQuestion.h"
#include "OpenQuestion.h"

class Test
{
private:
  std::vector<Question *> questions;

public:
  Test(std::vector<Question *> _questions)
  {
    for (auto q : _questions) {
      questions.push_back(q);
    }
  }
  void read(std::istream &is)
  {
    size_t size = questions.size();
    for (int i = 0; i < size; ++i)
    {
      questions[i]->read(is);
    }
  }

  void ask() const
  {
    size_t size = questions.size();
    std::cout<<size;
    unsigned points = 0;
    for (int i = 0; i < size; ++i)
    {
      points += questions[i]->ask();
    }

    std::cout << "Your score: " << points << std::endl;
  }

  void write(std::ostream &os) const
  {
    size_t size = questions.size();
    for (int i = 0; i < size; ++i)
    {
      questions[i]->print(os);
    }
  }
};