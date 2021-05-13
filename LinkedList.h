
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   // return size of the list
   int size();
   
   // clear the list
   void clear();
   //add to the front of the list
   void addFront(Tile* tile);
   //add to the back of the list
   void addBack(Tile* tile);

   void removeFront();

   // returns copy of node at i   
   Node* get(int i);

   // returns copy of head
   Node* getHead();

   // checks if list is empty
   bool isEmpty();

private:
   Node* head;
   Node* tail;
};

#endif // ASSIGN2_LINKEDLIST_H
