#include <iostream>
#include "List.h"

// 2 3 4 5 6 1 
// 4 5 6 1 2 3
// 1 2 3 4 5 6
// 4 5 6->null first -> 1 2 3 -> 4
//4-5-6-1-2-3
// 1 2 3 4 5 6

template<typename T>
void swap (List<T>& list) {
  List<T> holder;
	Box<T> *curr = list.getFirst();
	while(curr != nullptr) {
		if(curr->next != nullptr && curr->data > curr->next->data) { // 6 > 1
      holder.pushBack(curr->data); // 4 5 6
      list.pop(); // 1 2 3
      curr = list.getFirst();
      Box<T>* temp = holder.getFirst();
      while(temp != nullptr) {
        list.pushBack(temp->data);
        holder.pop();
        temp = holder.getFirst();
      }
			return;
		} else {
      holder.pushBack(curr->data); // 4 5
      list.pop(); // 6 1 2 3
      curr = list.getFirst();
    }
	}
  list = holder;
}

int main() {
  List<int> list;
  list.pushBack(2);
  list.pushBack(3);
  list.pushBack(4);
  list.pushBack(5);
  list.pushBack(6);
  list.pushBack(1);
  list.print();
  swap(list);
  list.print();
  return 0;
}

///...sdjcnsdlkcmss mskfvh sdkcds