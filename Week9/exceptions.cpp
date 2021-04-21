#include <iostream>
#include <cassert>
#include <string>

int temp(int a){
    if (a != 2) {
        // std::cerr<<"ERROR: a = "<<a<<std::endl;
        throw std::invalid_argument("a = 1 asd");
    }
    if (a != 3) {
        // std::cerr<<"ERROR: a = "<<a<<std::endl;   
        throw std::length_error("a = 1 asd");
    }

    int b = a + 1;
    std::cout << b;
}

void print(int a) {
    try {
        temp(a);
    } catch (const std::length_error& le) {
        le.what();
    } catch (const std::invalid_argument& le) {
        le.what();
    }
}

int main () {
   
    int a = 5;
    // assert(a == 2);
    std::string name = "hjfksdhfks1hjfksdhfks1hjfksdhfks1hjfksdhfks1";
    // assert(name.length() == 10);
    // temp(a);
   
    print(a);
    std::cout<<"asfhjkas";
    

    return 0;
}