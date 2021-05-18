#pragma once
#include "Card.h"
#include <ctime>
#include <cassert>

class Deck {
private:
  Card cards[52];
  int currentCard;

  void generateDeck() {
    char suits[5] = "SHDC";
    size_t counter = 0;
    for(int i = 0; i < 13; ++i) {
      for(int j = 0; j < 4; ++j) {
        cards[counter] = Card(suits[j], (Face)i);
        counter++;
      }
    }
    currentCard = 0;
  }

public:
  Deck() {
    generateDeck();
    shuffle();
  } 

  void shuffle()
  {
    srand(time(0));
    size_t size = sizeof(cards) / sizeof(Card);
    for(int i = 0; i < size; ++i) {
      int j = i + rand() % (size - i);
      std::swap(cards[i], cards[j]);
    }
    currentCard = 0;
  }

  Card* draw(unsigned numberOfCards = 2) {
    assert(numberOfCards < 52);

    Card* hand = new Card[numberOfCards];
    for(int i = 0; i < numberOfCards; ++i) {
      hand[i] = cards[currentCard++];
    }

    return hand;
  }

  void print() const {
    for(int i = 0; i < 52; ++i) {
      std::cout<<cards[i]<<" ";
    }
  }
};