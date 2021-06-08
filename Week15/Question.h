#pragma once
#include <string>
#include <iostream>

class Question
{
protected:
  std::string question;
  std::string trueAnswer;
  unsigned points;

public:
  Question(const std::string& question, const std::string& answer, unsigned points);
  virtual void print(std::ostream& os) const = 0;
  virtual void read(std::istream& is) = 0;
  virtual unsigned ask() const;

};

unsigned Question::ask() const {
  std::cout<<question<<std::endl<<"Enter your answer: \n";

  std::string userAnswer;
  std::cin>>userAnswer;

  return trueAnswer == userAnswer ? points : 0;
}

Question::Question(const std::string& _question, const std::string& _answer, unsigned _points)
  :question(_question), trueAnswer(_answer), points(_points){}