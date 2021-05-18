#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using std::ostream;
using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;

using std::vector;

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
   Tile* get(string tile);

   // returns copy of head
   Node* getHead();

   // checks if list is empty
   bool isEmpty();

   friend ostream& operator << (ostream& os, LinkedList& list);
   friend ofstream& operator << (ofstream& of, LinkedList& list);
   friend ifstream& operator >> (ifstream& in, LinkedList* list);

private:
   Node* head;
   Node* tail;
   int size;
};

#endif // ASSIGN2_LINKEDLIST_H
