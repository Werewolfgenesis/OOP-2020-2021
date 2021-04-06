#include <iostream>

template <typename T>
struct TypedBuffer {
    T* data;
    size_t size;
};

//[подходящ тип] create (size_t n, [подходящ тип] k): инициализира и връща нов буфер, състоящ се от n>0 на брой елемента, всеки със стойност k
template <typename T>
TypedBuffer<T> create(size_t n, T k) {
    TypedBuffer<T> result;
    result.size = n;
    result.data = new T[n];

    for (size_t i = 0; i < n; ++i) {
        result.data[i] = k;
    }

    return result;
}

//[подходящ тип] concat ([подходящ тип] a, [подходящ тип] b): Създава и връща нов буфер, чиито елементи се получават от елементите на a, следвани от елементите на  b
template <typename T>
TypedBuffer<T> concat(const TypedBuffer<T>& a, const TypedBuffer<T>& b) {
    TypedBuffer<T> result;
    result.size = a.size + b.size;
    result.data = new T[result.size];

    size_t i = 0;
    for (i; i < a.size; ++i) {
        result.data[i] = a.data[i];
    }
    for (size_t j = 0; j < b.size; ++j) {
        result.data[i] = b.data[j];
        ++i;
    }
    return result;
}

//[подходящ тип] append ([подходящ тип] a, [подходящ тип] b): “Залепя” елементите на буфера b към елементите на буфера a. Резултатът се получава в буфера a
template <typename T>
void append(TypedBuffer<T>& a, const TypedBuffer<T>& b) {
    TypedBuffer<T> result;
    result.size = a.size + b.size;
    result.data = new T[result.size];

    size_t i = 0;
    for (i; i < a.size; ++i) {
        result.data[i] = a.data[i];
    }
    for (size_t j = 0; j < b.size; ++j) {
        result.data[i] = b.data[j];
        ++i;
    }
    delete[] a.data;
    a = create(result.size, result.data[0]);
    for (size_t k = 1; k < a.size; ++k) {
        a.data[k] = result.data[k];
    }
}

template <class T>
bool contains(const TypedBuffer<T>& tb, const T& el) {
    for(int i = 0; i < tb.size; ++i) {
        if(tb.data[i] == el) {
            return true;
        }
    }

    return false;
}

//[подходящ тип] union ([подходящ тип] a, [подходящ тип] b): Реализира обединение на множествата на елементите на буферите a и b. Резултатът е нов буфер, в който всеки елемент от обединението се среща точно веднъж.
template<typename T>
TypedBuffer<T> unionFunction(const TypedBuffer<T> &a, const TypedBuffer<T> &b)  
{
    TypedBuffer<T> newBuff;

    newBuff = create(a.size + b.size, a.data[0]);

    int k = 0;
    for(size_t i = 0; i < a.size - 1; i++)
    {
        for(size_t j = i; j < a.size; j++)
        {
            if(a.data[i] != a.data[j])
            {
                newBuff.data[k] = a.data[i];
                k++;
            }
        }
    }

    for(size_t i = 0; i < b.size - 1; i++)
    {
        for(size_t j = i; j < b.size; j++)
        {
            if(b.data[i] != b.data[j] && !contains(newBuff, b.data[i]))
            {
                newBuff.data[k] = b.data[i];
                k++;
            }
        }
    }

    return newBuff;
}

//Да се реализира клас SumAvgCalculator,  който служи за изчисляване на сума и средно аритметично на поредица от цели числа. При създаване на обект от класа,  съответната му поредица съдържа само едно число, което се подава като аргумент на конструктора. За класа да се реализират следните методи

class SumAvgCalculator {
private:
    int _sum;
    int countNumbers;

public:

    SumAvgCalculator() {
        _sum = 0;
        countNumbers = 0;
    }

    SumAvgCalculator(int number) {
        _sum += number;
        ++countNumbers;
    }

    //sum, който връща сумата на поредицата
    int sum()
    {
        return _sum;
    }

    //add, добавящ число към поредицата
    void add(int number)
    {
        _sum += number;
        ++countNumbers;
    }

    //sub, добавящ число с отрицателен знак към поредицата
    void sub(int number)
    {
        _sum += (-1) * number;
        ++countNumbers;
    }

    //num, връщащ броя на числата в поредицата
    int num()
    {
        return countNumbers;
    }

    //average, връщащ средното аритметично на числата в поредицата.
    double avr()
    {
        return (double)_sum / countNumbers;
    }

    //оператори за събиране на редици (+) и (+=), събиращи две редици. Резултатната редица се състои от членовете на двете изходни редици
    SumAvgCalculator operator+(const SumAvgCalculator& other)
    {
        SumAvgCalculator arr;
        arr._sum = other._sum + this->_sum;
        arr.countNumbers = other.countNumbers + this->countNumbers;
        return arr;
    }

    SumAvgCalculator& operator+=(const SumAvgCalculator& other)
    {
        this->_sum += other._sum;
        this->countNumbers += countNumbers;
        return *this;
    }
};

int main () {

    return 0;
}

// +, -, *, /, % -> Връщат нов обект
// +=, -=, *=, /=, %= -> Връщат текущия обект
