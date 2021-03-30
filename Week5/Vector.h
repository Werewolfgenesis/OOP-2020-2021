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

