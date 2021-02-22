#include <iostream>

//Напишете шаблонна функция, която приема два параметъра и връща по-големия от тях.
template<typename T>
const T& max(const T& first_argument, const T& second_argment)
{
    return first_argument > second_argment ? first_argument : second_argment;
}
void testTask()
{
    int first_int = 2;
    int second_int = 3;

    double first_double = 4.33;
    double second_double = 4.76;

    char first_char = 'c';
    char second_char = 'A';
    std::cout << "Max is " << max(first_int, second_int) << std::endl;
    std::cout << "Max is " << max(first_double, second_double) << std::endl;
    std::cout << "Max is " << max(first_char, second_char) << std::endl;
}
int main()
{
    testTask();
    return 0;
}