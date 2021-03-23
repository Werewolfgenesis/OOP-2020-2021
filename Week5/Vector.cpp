#include "Vector.h"

template <class T>
Vector<T>::Vector() {
    this->data = nullptr;
    this->size = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) {
    this->size = other.size;
    this->data = new T[other.size];
    for(int i = 0; i < this->size; ++i) {
        this->data[i] = data[i];
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
    if(this != &other) {
        delete[] this->data;

        this->size = other.size;
        this->data = new T[other.size];
        for(int i = 0; i < this->size; ++i) {
            this->data[i] = data[i];
        }
    }

    return *this;
}

template <class T>
Vector<T>::~Vector() {
    delete[] this->data;
}

template <class T>
Vector<T>::Vector(unsigned size) { //TODO
    this->data = new T[size];
    this->size = size;
}

    template <class T>
    void Vector<T>::popBack()
    {
        if (this->data == nullptr)
        {
            std::cout << "Vector is empty!" << std::endl;
            return;
        }
    
	    --this->size;
	    T *array = new T[size];

        for (size_t i = 0; i < size; i++)
        {
            array[i] = this->data[i];
        }
    
        delete[] this->data;
	    this->data = array;
    }

    template <class T>
    void Vector<T>::pushBack(const T& element)
    {
       if(this->data == nullptr)
        {
	       ++this->size;
	       this->data = new T[size];
           this->data[0] = element;
           return;
        }
    
        T* array = new T[size + 1];
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = this->data[i];
        }
        array[size] = element;
        ++size;
        delete [] this->data;
        this->data = array;
    

    } 
template<typename T>
void Vector<T>::print()
{
    if (this->data == nullptr)
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    for (size_t i = 0; i < this->size; i++)
    {
        std::cout << this->data[i] << " ";
    }
	std::cout << std::endl;
}