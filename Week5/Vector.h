#pragma once
// #include <iostream>

template <class T>
class Vector {
private:
    T* data;
    size_t size;

    void copy(const Vector<T>&);
    void erase();

public:
    Vector();
    Vector(const Vector<T>&);
    Vector<T>& operator=(const Vector<T>&);
    ~Vector();
    Vector(unsigned size);

    void pushBack(const T& element);
    void popBack();

    void print();
    // 1 2 3 4 5 6
};