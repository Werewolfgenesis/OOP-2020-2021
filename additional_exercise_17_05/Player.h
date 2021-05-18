#pragma once 
#include "Deck.h"

class Player {
private:
  Card* hand;
  size_t size;
  int points;

public:
  Player(Card* _hand) {
    hand = _hand;
    size = 2;
    points = 0;
  }
  
  Player(const Player& other) {
    size = other.size;
    hand = new Card[size];
    points = other.points;
    for(int i = 0; i < size; ++i) {
      this->hand[i] = other.hand[i];
    }
  }
  
  Player& operator= (const Player& other){
    if (this != &other)
    {
        delete[] this->hand;
        size = other.size;
        points = other.points;
        this->hand = new Card[other.size];
        for(unsigned i = 0; i < other.size ;++i){
            this->hand[i] = other.hand[i];
        }
    }
    return *this;
  }

  void set_hand(Card* hand){
    if(hand != nullptr){
        delete[] this->hand;
        this->hand = new Card[size];
        for(unsigned i = 0; i < size; ++i){
            this->hand[i] = hand[i];
        }
    }
  }

  ~Player(){
    delete[] this->hand;
  }

  size_t get_size() const { 
    return this->size;
  }

  Card* get_hand() const {
    return this->hand;
  }

  void assignPoints(int p) {
    points = p;
  }

  int getPoints() const {
    return points;
  }
};