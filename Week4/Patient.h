#pragma once
#include <cstring>
#include <iostream>

//Какво прави класът?
class Patient {
private:
    char* name;
    char* date;
    int numberOfVisits;

    void copy(const Patient&);
    void erase();

public:
    Patient();
    Patient(const Patient&);
    Patient& operator=(const Patient&);
    ~Patient();

    void print();

    bool operator<(const Patient&);
    bool operator>(const Patient&);
    bool operator==(const Patient&);
    bool operator<=(const Patient&);
    bool operator>=(const Patient&);
    bool operator!=(const Patient&);

};

#include "Patient.cpp"