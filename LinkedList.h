
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

#include <fstream>

using std::ofstream;
using std::ifstream;
class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   // return size of the list
   int getSize();
   
   // clear the list
   void clear();
   //add to the front of the list
   void addFront(Tile* tile);
   //add to the back of the list
   void addBack(Tile* tile);

   void removeFront();

   // removes Node at position i. DOES NOT DELETE THE NODE
   void remove(int i);

   // returns copy of node at i   
   Node* get(int i);

   // returns copy of head
   Node* getHead();

   // checks if list is empty
   bool isEmpty();

   friend ofstream& operator << (ofstream& of, LinkedList& list);

private:
   Node* head;
   Node* tail;
   int size;
};

#endif // ASSIGN2_LINKEDLIST_H
