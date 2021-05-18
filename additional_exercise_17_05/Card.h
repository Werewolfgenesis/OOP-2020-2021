#pragma once
#include <iostream>

enum class Face
{
    DUEC = 0,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Card
{
private:
    char suit; //C, D, H, S
    Face face;

public:
    Card(char _suit = '0', Face _face = Face::DUEC) : face(_face) {
        if (suit > 'a' && suit < 'z')
        {
            suit = _suit - ('a' - 'A');
        }
        else
        {
            suit = _suit;
        }
    }
    Card &operator=(const Card &other)
    {
        if (suit > 'a' && suit < 'z')
        {
            suit = other.suit - ('a' - 'A');
        }
        else
        {
            suit = other.suit;
        }

        face = other.face;

        return *this;
    }

    bool operator==(const Card &other) const
    {
        return this->suit == other.suit && this->face == other.face;
    }
    bool operator>(const Card &other) const
    {
        return this->face > other.getFace();
    }

    char getSuit() const
    {
        return suit;
    }
    Face getFace() const
    {
        return face;
    }
    friend std::ostream &operator<<(std::ostream &out, const Card &card)
    {
        switch (card.face)
        {
        case Face::DUEC:
            out << "2";
            break;
        case Face::THREE:
            out << "3";
            break;
        case Face::FOUR:
            out << "4";
            break;
        case Face::FIVE:
            out << "5";
            break;
        case Face::SIX:
            out << "6";
            break;
        case Face::SEVEN:
            out << "7";
            break;
        case Face::EIGHT:
            out << "8";
            break;
        case Face::NINE:
            out << "9";
            break;
        case Face::TEN:
            out << "10";
            break;
        case Face::JACK:
            out << "J";
            break;
        case Face::QUEEN:
            out << "Q";
            break;
        case Face::KING:
            out << "K";
            break;
        case Face::ACE:
            out << "A";
            break;
        }
        out << card.suit;
        return out;
    }
};
