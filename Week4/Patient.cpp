#include "Patient.h"
//Как го прави класът?

void Patient::copy(const Patient& other) {
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);

    this->date = new char[std::strlen(other.date) + 1];
    std::strcpy(this->date, other.date);

    this->numberOfVisits = other.numberOfVisits;
}

void Patient::erase() {
    delete[] this->name;
    delete[] this->date;
}

Patient::Patient(){
    this->name = new char[8];
    std::strcpy(this->name, "Unknown");
    this->date = new char[8];
    std::strcpy(this->name, "Unknown");
    this->numberOfVisits = 0;
}

Patient::Patient(const Patient& other){
    copy(other);
}

Patient& Patient::operator=(const Patient& other){
    if(this != &other) {
        erase();
        copy(other);
    }

    return *this;
}

Patient::~Patient(){
    erase();
}

void Patient::print() {
    std::cout<<this->name<<" "<<this->date<<" "<<this->numberOfVisits<<std::endl;
}
//p1 < p2
bool Patient::operator<(const Patient& other) {
    return this->numberOfVisits < other.numberOfVisits;
}

bool Patient::operator<=(const Patient& other) {
    return (this < &other) || (this == &other);
}

bool Patient::operator>(const Patient& other) {
    return this->numberOfVisits > other.numberOfVisits;
}

bool Patient::operator>=(const Patient& other) {
    return (this > &other) || (this == &other);
}

bool Patient::operator==(const Patient& other) {
    return this->numberOfVisits == other.numberOfVisits;
}

bool Patient::operator!=(const Patient& other) {
    return !(this->numberOfVisits == other.numberOfVisits);
}
// * -> + - += -= / /= *= % %= [] << >>... -> can be overloaded
// . :: : .* sizeof typeid -> cannot be overloaded


