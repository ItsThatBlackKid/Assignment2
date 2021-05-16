
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;
   tail = nullptr;

   // TODO
}

LinkedList::~LinkedList() {
   this->clear();
}

int LinkedList::size() {
   int size = 0;
   Node* n = new Node(*head);

   while( n != nullptr) {
      size++;
      n = n->next;
   }

   return size;
}

void LinkedList::clear() {

   while(head !=  nullptr) {
      Node* n = head->next;
      delete head;
      head = n;
   }
}

void LinkedList::addFront(Tile* tile) {
   Node* front = new Node(tile, head);
   head = front;
}

void LinkedList::addBack(Tile* tile) {
   Node* back = new Node(tile,nullptr);
   if(tail == nullptr) {
      tail = back;
   } else {
      tail->next = back;
      back = tail;
   }
}

ofstream& operator << (ofstream& of, const LinkedList& list) {
   int count = 0; 
   while(count < list.size) {

   }
}