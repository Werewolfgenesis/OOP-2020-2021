#include "Patient.h"

int main() {
    Patient p;
    Patient p1;
    std::cout<<(p == p1)<<std::endl;
    p.print();
    return 0;
}