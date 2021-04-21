#include <iostream>
#include <fstream>
#include <string>
#include "String.h"

int main () {

    std::ofstream fout;
    fout.open("test.txt");
    std::string text;
    std::cout << "Enter text: ";
    std::cin >> text;
    fout << text;

    fout.close(); //Трябва да затворим потокът за вход преди да отворим този за изход, тъй като ще четат един и същ файл.

    std::ifstream fin;
    fin.open("test.txt");
    std::string str;
    fin >> str;
    std::cout<<str;

    fin.close();

    return 0;
}