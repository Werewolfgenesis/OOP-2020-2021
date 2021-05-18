#pragma once
#include "Player.h"
#include <vector>

class Game {
private:
  std::vector<Player> players;
  std::vector<Card> tableCards;
  Deck deck;  
  const int HAND_SIZE = HAND_SIZE;
  
  Card* generateAllCards(const Player& player) const{
    Card* holder = new Card[HAND_SIZE];
    for(int i = 0; i < 5; ++i) {
      holder[i] = tableCards[i];
    }
    holder[5] = player.get_hand()[0];
    holder[6] = player.get_hand()[1];

    return holder;
  }

  Card* sort_cards(const Card* holder) const {
    Card* temp = new Card[HAND_SIZE];
    for(int i = 0; i < HAND_SIZE; ++i) {
      temp[i] = holder[i];
    }
    for (unsigned i = 0; i < HAND_SIZE; i++)
    {
      for(unsigned j = i + 1; j < HAND_SIZE; ++j){
        if (temp[i] > temp[j])
        {
          std::swap(temp[i], temp[j]);
        }
      }
    }

    return temp;
  }

  int calculatePoints(const Player& player) const {
    if(has_pair(player)) {
      return 1;
    } 
    else if (has_two_pair(player)) {
      return 2;
    } 
    else if(has_three_of_a_kind(player)) {
      return 3;
    } 
    else if (has_straight(player)) {
      return 4;
    } 
    else if (has_flush(player)) {
      return 5;
    } 
    else if (has_four_of_a_kind(player)) {
      return 6;
    } 
    else if (has_full_house(player)) {
      return 7;
    }
    else if(has_straight_flush(player)){
      return 8;
    }
    else if(has_royal_flush(player)){
      return 9;
    } 
    else{
      return 0;
    }       
  }

public:
  Game(size_t numberOfPlayer = 1) {
    players = std::vector<Player>(numberOfPlayer);
    tableCards = std::vector<Card>(5);
    Card* holder = deck.draw(5);
    for(int i = 0; i < 5; ++i) {
      tableCards[i] = holder[i];
    }
  }

  void draw() {
    size_t size = players.size();
    for(int i = 0; i < size; ++i) {
      players[i].set_hand(deck.draw());
    }
  }

  bool has_high_card() const {

  }

  bool has_pair(const Player& player) const{
    Card* holder = generateAllCards(player);
    for(unsigned i = 0; i < HAND_SIZE; ++i){
        for(unsigned j = i + 1; j < HAND_SIZE; ++i){
            if(holder[i] == holder[j]){
              return true;
            }
        }
    }
    return false;
  }

  bool has_two_pair(const Player& player) const{ //  2 2 2 3 5 6 8
    Card* holder = generateAllCards(player);
    unsigned counter = 0;
    for(unsigned i = 0; i < HAND_SIZE; ++i){
        for(unsigned j = i + 1; j < HAND_SIZE; ++j){
            if(holder[i] == holder[j]){
              counter++;
              // ++i;
              ++j;
            }
            if(counter == 2) {
              return true;
            }
        }
    }
    return false;
  }

  bool has_three_of_a_kind(const Player& player) const{
    Card* holder = generateAllCards(player);
    unsigned counter = 0;
    for (size_t i = 0; i < HAND_SIZE - 1; i++)
    {
      if(holder[i] == holder[i + 1]) {
        for(int j = i + 2; j < HAND_SIZE; ++j) {
          if(holder[i] == holder[j]) {
            return true;
          }
        }
      }
    }

    return false;
  }

  bool has_straight(const Player& player) const{ //five in a row
    Card* holder = generateAllCards(player);
    holder = sort_cards(holder);
    size_t start = 0;
    for (start; start < 13; ++start) {
      if((Face)start == holder[0].getFace()){
        break;
      }
    }

    int counter = 0;
    for (size_t i = 0; i < HAND_SIZE; ++i) {
      if ((Face)start++ == (Face)i){
        ++counter;
      } else {
        counter = 0;
      }
    }

    return counter == 5;
  }

  bool has_flush(const Player& player) const{ //five from one suit
    Card* holder = generateAllCards(player);
    int counter[4]; // 0-C, 1-D, 2-H, 3-S
    for(int i = 0; i < HAND_SIZE; ++i) {
      if(holder[i].getSuit() == 'C') {
        counter[0]++;
      } else if(holder[i].getSuit() == 'D') {
        counter[1]++;
      } else if(holder[i].getSuit() == 'H') {
        counter[2]++;
      } else if(holder[i].getSuit() == 'S') {
        counter[3]++;
      } else {
        throw std::invalid_argument("The card's suit is \'0\'");
      }
    }

    for(int i = 0; i < 4; ++i) {
      if(counter[i] == 5) {
        return true;
      }
    }
    
    return false;
  }

  bool has_full_house(const Player& player) const{
    return has_pair(player) && has_three_of_a_kind(player);
  }

  bool has_four_of_a_kind(const Player& player) const{
    Card* holder = generateAllCards(player);
    unsigned counter = 0;
    for (size_t i = 0; i < player.get_size() - 1; i++) {
      if(holder[i] == holder[i + 1]) {
        for(int j = i + 2; j < player.get_size(); ++j) {
          if(holder[i] == holder[j]) {
            for(int k = j + 1; k < player.get_size(); ++k) {
              if(holder[j] == holder[k]) {
                return true;
              }
            }
          }
        }
      }
    }
  }

  bool has_straight_flush(const Player& player) const{
    return this->has_flush(player) && this->has_straight(player);
  }

  bool has_royal_flush(const Player& player) const{
    Card* holder = generateAllCards(player);
    bool contains[3] = {false, false, false};
    for(int i = 0; i < HAND_SIZE; ++i) {
      if(holder[i] == 'A') {
        contains[0] = true;
      }
      if(holder[i] == 'K') {
        contains[1] = true;
      }
      if(holder[i] == 'Q') {
        contains[2] = true;
      }
    }

    return this->has_straight_flush(player) && contains[0] && contains[1] && contains[2];
  }

  bool hasCombination(const Player& player) const{
    return has_pair(player) || 
            has_two_pair(player) || 
            has_three_of_a_kind(player) || 
            has_straight(player) || 
            has_flush(player) || 
            has_four_of_a_kind(player) || 
            has_full_house(player) ||
            has_straight_flush(player) || 
            has_royal_flush(player);
  }
  

  Player winner() {
    int* points = new int[players.size()];
    int size = players.size();
    for(int i = 0; i < size; ++i) {
      points[i] = calculatePoints(players[i]);
      players[i].assignPoints(points[i]);
    }
    
    Player temp = players[0];
    for(int i = 1; i < size; ++i) {
      if(temp.getPoints() < players[i].getPoints()) {
        temp = players[i];
      }
    }

    return temp;
  }
};