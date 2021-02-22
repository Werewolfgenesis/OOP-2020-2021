#include <iostream>

template<typename T>
T sum(const T& first_argument,const T& second_argument)
{
    return first_argument + second_argument;
    //if sum chars you sum their ascii code and you end up with a non readable symbol a.k.a monkey
}
void testTask()
{
    char c = 'c';
    char b = 'b';

    int first = 3;
    int second = 4;

    std::cout << sum(first,second) << std::endl; // 7
    std::cout << sum(c,b) << std::endl; // non-readable symbol
}
int main()
{
    testTask();
    return 0;
}