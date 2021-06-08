#pragma once
#include <iostream>

template <class T>
struct Box
{
  T data;
  Box *next;

  Box(T _data, Box *_next)
  {
    data = _data;
    next = _next;
  }
};

template <class T>
class List
{
private:
  Box<T> *first;

  void copy(const List<T> &);
  void erase();

  void printRec(const Box<T>*curr) const
  {
    if(curr == nullptr) {
      std::cout<<"nullptr\n";
      return;
    }
    std::cout<<curr->data<<"->";
    printRec(curr->next);
  }

public:
  List();
  List(const List<T> &);
  List<T> &operator=(const List<T> &);
  ~List();

  void pushBack(const T&);
  void pop();
  
  void print() const;
  size_t length() const; 
  int sum() const;
  void reverse();

  

  //1->2->3->4

  Box<T>* getFirst() {
    return first;
  }
  // void print() const {
  //   Box<T>* current = first;
  //   while(current != nullptr) {
  //     std::cout<<current->data<<" -> ";
  //     current = current->next;
  //   }
  //   std::cout<<"nullptr\n";
  // }

};

template <typename T>
List<T>::List()
{
  this->first = nullptr;
}

template <class T>
List<T>::List(const List<T> &other)
{
  this->copy(other);
}

template <class T>
List<T> &List<T>::operator=(const List<T> &other)
{
  if (this != &other)
  {
    this->erase();
    this->copy(other);
  }
  return *this;
}

template <class T>
List<T>::~List()
{
  this->erase();
}

template <class T>
void List<T>::copy(const List<T> &other)
{
  if(other.first == nullptr) {
    this->first = nullptr;
    return;
  }

  this->first = new Box<T>(other.first->data, nullptr);
  Box<T>* current = this->first;
  Box<T>* holder = other.first->next;
  while(holder != nullptr) {
    current->next = new Box<T>(holder->data, nullptr);
    current = current->next;
    holder = holder->next;
  }
}

template <class T>
void List<T>::erase()
{
  while(this->first){
    Box<T> *current = this->first->next;
    delete this->first;
    first = current;
  }
}

template<typename T>
void List<T>::pushBack(const T& elem){
  if(this->first == nullptr){
    this->first = new Box<T>(elem, nullptr);
    return;
  }

  Box<T>* curr = this->first;
  while(curr->next != nullptr){//will stop at last elem
    curr = curr->next;
  }

  curr->next = new Box<T>(elem, nullptr);
}

template <class T>
void List<T>::pop() {
  if(this->first == nullptr) {
    std::cout << "Empty list! " << std::endl;
    return;
  }

  Box<T>* toDelete = this->first;
  this->first = this->first->next;
  delete toDelete;
}


template <class T>
void List<T>::print() const {
  printRec(first);
  // if(this->first == nullptr)
  // {
  //   std::cout << "Can't print anything" << std::endl;
	//   return;
  // }
  
	// Box<T> *current = this->first;
  // while(current != nullptr)
  // {
  //   std::cout << current->data << " -> ";
  //   current = current->next;
  // }
  // std::cout<<"nullptr\n";
}
//print
//length
template <class T>
size_t List<T>::length() const
{
  if(this->first == nullptr)
  {
    return 0;
  }
  
  Box<T>* crr = this->first;
  size_t counter = 0;

  while(crr != nullptr)
  {
    ++counter;
    crr = crr -> next;
  }
  return counter;
}


//sum
//chatbox:
//reverse - Veso!
//pishi si reversa alo 
//<//3
//ne moa : )-> misli :(
//chertai 
//prai struvaj - da0 ima reverse napisan :)
template <class T>
void List<T>::reverse(){
    if(this->first == nullptr) {
		std::cout << "Empty list!";
		return;
	}
	Box<T> *current = this->first;
	Box<T> *lastElement = this->first;
	while(lastElement){
		lastElement = lastElement->next;
	}
	size_t i = 0;
	size_t size = this->length();
    while (i < size/2) {
    current->data = lastElement->data;
	current->next = lastElement->next; //Veso beshe tuk
	}
				   
}