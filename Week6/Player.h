#pragma once
#include <iostream>
#include <cstring>

//Всеки играч има име, възраст, цена, номер в отбора и дали е капитан.
class Player
{
private:
    char name[32];
    size_t age;
    double price;
    int kitNumber;
    bool isCaptain;
    
public:
    Player();
    Player(char name[], size_t age, double price, int number, bool isCap);
	void print() const;
	Player& operator=(const Player& other);
};
