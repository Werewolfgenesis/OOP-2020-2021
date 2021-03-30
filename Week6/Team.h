#pragma once
#include "Player.h"

class Team {
private:
   char team_name[64];
   Player players[20];
   char games[6];

public:
   Team();
   Team(char team_name[], Player player[], char games[]);
   
   void print() const;
   void winner_forecast(const Team& other);
   double calcPercents() const;
};