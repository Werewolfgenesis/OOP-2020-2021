#pragma once
#include "Question.h"
#include <vector>

class ClosedQuestion : public Question
{
private:
  std::vector<std::string> answers;

public:
  ClosedQuestion(int numberOfAnswers, const std::string &question, unsigned points, const std::string *answers, const std::string &trueAnswer);
  void print(std::ostream &os) const;
  void read(std::istream &is);
};

ClosedQuestion::ClosedQuestion(int numberOfAnswers, const std::string &question, unsigned points, const std::string *_answers, const std::string &trueAnswer)
    : Question(question, trueAnswer, points)
{
  if (_answers == nullptr)
  {
    throw new std::invalid_argument("No answers.");
  }
  answers.push_back(trueAnswer);
  for (int i = 0; i < numberOfAnswers; ++i)
  {
    answers.push_back(_answers[i]);
  }
}

void ClosedQuestion::print(std::ostream &os) const
{
  os << question << "\n" << points;
  for (std::string answer : answers)
  {
    os << answer << "\n";
  }
}

void ClosedQuestion::read(std::istream &is)
{
  is >> question;
  is >> points;
  for(std::string& answer : answers) {
    is >> answer;
  }
}