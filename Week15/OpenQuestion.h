#pragma once
#include "Question.h"

class OpenQuestion : public Question {
private: 

public:
  OpenQuestion(const std::string& question, const std::string& answer, unsigned points);
  void print(std::ostream &os) const;
  void read(std::istream &is);
};

OpenQuestion::OpenQuestion(const std::string& question, const std::string& answer, unsigned points) 
  : Question(question, answer, points){}

void OpenQuestion::print(std::ostream &os) const
{
  os << question << "\n";
  os << points << "\n";
  os << trueAnswer;
}

void OpenQuestion::read(std::istream &is)
{
  is >> question;
  is >> points;
  is >> trueAnswer;
}