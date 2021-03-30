#include "Player.h"

Player::Player()
{
	std::strcpy(this->name, "John Doe");
    this->age = 20;
    this->price = 10.5;
    this->kitNumber = 1234;
    this->isCaptain = false;
}

Player::Player(char name[], size_t _age, double _price, int _number, bool _isCap)
                : age(_age), price(_price), kitNumber(_number), isCaptain(_isCap)
{
    std::strcpy(this->name, name);
}

Player& Player::operator=(const Player& other) {
    std::strcpy(this->name, other.name);
    this->age = other.age;
    this->price = other.price;
    this->kitNumber = other.kitNumber;
    this->isCaptain = other.isCaptain;

    return *this;
}

void Player::print() const
{
	std::cout << "Player name: " << this->name;
    std::cout << "Age: " << this->age;
}
