#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T* arr;
	size_t size;
	size_t capacity;

	void copy(const Vector<T>&);
	void erase();
	void resize();

public:
	///��������� �����������
	Vector();
	Vector(const Vector&);
	Vector& operator=(const Vector<T>&);
	~Vector();

	///������������� �� ���������
	const T& operator[](size_t ) const;
	T& operator[](size_t );
	Vector operator+ (const Vector<T>&);
	Vector& operator+= (const Vector<T>&);

	///������
	size_t getSize() const;
	size_t getCapacity() const;

	///push & pop
	void push_back(T);
	void pop_back();
	void popByIndex(size_t);
	void pushByIndex(size_t,T);
	void push_front(T);
	void pop_front();
	void popByData(T);

	///�������� ���� �������� � ������
	bool isEmpty () const;

	///��������� �� ������������ ��� �������
	void print() const;

	///��������� �� ���� � ����� - Will explain in the future!
	// friend std::istream& operator>>(std::istream& is, Vector<T> other) {
	// 	for(int i=0; i<this->size; ++i){
	// 		is>>arr[i];
	// 	}

	// 	return is;
	// }

	// friend std::ostream& operator<<(std::ostream& out, const Vector<T> other) {
	// 	out<<"[";
	// 	for(int i=0; i<this->size; ++i){
	// 		out<<this->arr[i]<<", ";
	// 	}
	// 	out<<"]"<<std::endl;

	// 	return out;
	// }
};

template<class T>
void Vector<T>::copy(const Vector<T>& other) {
	this->size = other.size;
	this->capacity = other.capacity;
	
	for (size_t i = 0; i < this->size; ++i) {
		this->arr[i] = other.arr[i];
	}
}

template<class T>
void Vector<T>::erase() {
	delete[] this->arr;
}

template<class T>
void Vector<T>::resize() {
	T* temp = new T[this->capacity * 2];
	this->capacity *= 2;

	for (size_t i = 0; i < this->size; ++i) {
		temp[i] = this->arr[i];
	}
	this->erase();
	this->arr = temp;
}

template<class T>
inline Vector<T>::Vector() {
	this->capacity = 8;
	this->size = 0;
	this->arr = new T[capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other) {
	this->copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		this->erase();
		this->copy(other);
	}

	return *this;
}

template<class T>
Vector<T>::~Vector() {
	this->erase();
}

template<class T>
const T& Vector<T>::operator[](size_t index) const {
	return this->arr[index];
}

template<class T>
T& Vector<T>::operator[](size_t index) {
	return this->arr[index];
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) {
	Vector<T> temp;
	temp.capacity = this->capacity + other.capacity;
	temp.size = this->size + other.size;

	for (size_t i = 0; i < this->size; ++i) {
		temp.arr[i] = this->arr[i];
	}

	for (size_t i = this->size; i < temp.size; ++i) {
		temp.arr[i] = other.arr[i - this->size];
	}

	return temp;
}

template<class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
	*this = *this + other;

	return *this;
}

template<class T>
size_t Vector<T>::getSize() const {
	return this->size;
}

template<class T>
size_t Vector<T>::getCapacity() const {
	return this->capacity;
}

template<class T>
void Vector<T>::push_back(T element) {
	this->size++;
	if (this->size >= this->capacity) {
		this->resize();
	}

	this->arr[this->size - 1] = element;
}

template<class T>
void Vector<T>::pop_back() {
	if(this->size == 0) {
		std::cerr<<"The vector is empty"<<std::endl;
		return;
	}

	T* newBuffer = new T[size - 1];
    for (size_t i = 0; i < size - 1; i++) {
        newBuffer[i] = data[i];
    }
    erase();
    --size;
    data = newBuffer;
}

template<class T>
void Vector<T>::popByIndex(size_t index) {
    if (isEmpty()) return;
	for (size_t i = index; i < this->size; ++i) {
		this->arr[i] = this->arr[i + 1];
	}
	this->size--;
}

template<class T>
void Vector<T>::pushByIndex(size_t index, T element) {
	++this->size;
	if (this->size > this->capacity) {
		this->resize();
	}

	for (size_t i = this->size - 1; i > index; --i) {
		this->arr[i] = this->arr[i - 1];
	}
	this->arr[index] = element;
}

template<class T>
void Vector<T>::push_front(T element) {
	++this->size;
	if (this->size > this->capacity) {
		resize();
	}

	for (size_t i = this->size - 1; i > 0; --i) {
		this->arr[i] = this->arr[i - 1];
	}
	this->arr[0] = element;
}

template<class T>
void Vector<T>::pop_front() {
    if (isEmpty()) return;
	for (size_t i = 0; i < this->size; ++i) {
		this->arr[i] = this->arr[i + 1];
	}
	--this->size;
}

template<class T>
void Vector<T>::popByData(T element){
    for (size_t i = 0; i < this->size; ++i) {
        if(this->arr[i] == element) {
            this->popByIndex(i);
            return;
        }
    }
}

template <class T>
bool Vector<T>::isEmpty() const {
    return !this->size;
}

template<class T>
void Vector<T>::print() const {
	std::cout<<"[";
	for(int i = 0; i < this->size; ++i) {
		std::cout<<this->arr[i]<<", ";
	}
	std::cout<<"]"<<std::endl;
}
