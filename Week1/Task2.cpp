#include <iostream>
#include <cstring>
//Напишете шаблонна функция, приемаща два аргумента и разменяща стойностите им
//Аргументите могат да бъдат от произволен тип (int, double, arrays, objects)
//
struct Account
{
    char* username;
    unsigned age;
    double balance;
    bool has_credit_history;

    Account()
    {
        username = nullptr;
        age = 0;
        balance = 0;
        has_credit_history = 0;
    }
    Account(const char* username, const unsigned& age, const double& balance, const bool& has_credit_history)
    {
        unsigned size_name = strlen(username);
        this->username = new char[size_name];
        for (unsigned i = 0; i < size_name; i++)
        {
            this->username[i] = username[i];
        }
        this->age = age;
        this->balance = balance;
        this->has_credit_history = has_credit_history;
    }
    void print()
    {
        std::cout << "Name: " ;
        unsigned size = strlen(this->username);
        for (size_t i = 0; i < size; i++)
        {
            std:: cout << this->username[i]; 
        }
        std::cout << std::endl;
        std::cout << "Age: " << this->age << std::endl; 
        std::cout << "Balance: " << this->balance << std::endl; 
        std::cout << "Has credit History: " << std::boolalpha << this->has_credit_history << std::endl; 
    }
};

template<typename T>
void swap(T& first_argument, T& second_argument)
{
    T temporary = first_argument;
    first_argument = second_argument;
    second_argument = temporary;
}
Account* get_richest_accs(Account* accs, const unsigned& size)
{
    for (size_t j = 0; j < size; j++)
    {
        for (unsigned i = 0; i < size; i++)
        {
            if (i+1 > size)
            {
                break;
            }
            if(accs[i].balance >= accs[i+1].balance)
            {
                swap(accs[i], accs[i+1]);

            }
        }
    }
    
    
    Account* richest = new Account[3];
    richest[0] = accs[size-1];
    richest[1] = accs[size-2];
    richest[2] = accs[size-3];

    return richest;
    
}
void testTask()
{
    int a = 4;
    int b = 34;

    swap(a,b);
    std::cout << a << std::endl;

    Account Toni("Toni Storaro", 44, 0.37, 0);
    Account Koceto("Koceto", 44, 998.56, 1);
    Account Sofka("Sofka", 45, 564.34, 0);
    Account Dessita("Dessita", 19, 231.78, 1);
    Account Vanko1("Vanko1", 45, 3123.45, 1);
    Account arr[5];
    arr[0] = Toni;
    arr[1] = Koceto;
    arr[2] = Sofka;
    arr[3] = Dessita;
    arr[4] = Vanko1;

    swap(Toni, Koceto);
    Toni.print();
    std::cout << "-------------------------------" << std::endl;

        Account* richest = get_richest_accs(arr, 5);
        std::cout << "Generating list of richest accounts... " << std::endl;
        std::cout << "-------------------------------" << std::endl;
        for (size_t i = 0; i < 3; i++)
        {
            richest[i].print();
            std::cout << std::endl;
        }
        
}
int main()
{
    testTask();
    return 0;
}