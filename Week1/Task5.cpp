#include <iostream>
//Напишете шаблонна структура Array, която представя едномерен масив. Нека структурата съдържа метод за достъпване на дължината на масива както и метод,
//който принтира всички елементи на структурата
template<typename T>
struct Array{
    T* data;
    const unsigned size = 128;

    Array(unsigned size)
    {
        if (size > this->size || size < 0)
        {
            std::cout << "Wrong size " << std::endl;
            exit(1);
        }
        data = new T[size];
        this->size = size;
    }
    int get_size()
    {
        return this->size;
    }
    void print()
    {
        for (size_t i = 0; i < this->size; i++)
        {
            std::cout << data[i] << "  ";
        }
        std::cout << std::endl;
    }
};
