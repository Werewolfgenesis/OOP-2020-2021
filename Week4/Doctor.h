#pragma once
#include "Patient.h"

class Doctor {
private:
    Patient* patients;
    size_t size;

public:
    //4

    Patient& operator[](int index) {
        return this->patients[index];
    }

    const Patient& operator[](int index) const {
        return this->patients[index];
    }

};

//Doctor d;
//d[1].print();