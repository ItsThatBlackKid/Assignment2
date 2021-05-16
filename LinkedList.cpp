
#include "LinkedList.h"

LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;

   // TODO
}

LinkedList::~LinkedList()
{
   this->clear();
}

int LinkedList::size()
{
   int size = 0;
   Node *n = new Node(*head);

   while (n != nullptr)
   {
      size++;
      n = n->next;
   }

   return size;
}

void LinkedList::clear()
{

   while (head != nullptr)
   {
      Node *n = head->next;
      delete head;
      head = n;
   }
}

void LinkedList::addFront(Tile *tile)
{
   Node *front = new Node(tile, head);
   head = front;
}

void LinkedList::addBack(Tile *tile)
{
   Node *back = new Node(tile, nullptr);
   if (tail == nullptr)
   {
      tail = back;
   }
   else
   {
      tail->next = back;
      back = tail;
   }

}

Node* LinkedList::get(int i) {
   int counter = 0;
   Node *h = head;
   while(counter > i && h->next !=nullptr) {
      h = h->next;
      counter++;
   }

   return h;
}

Node* LinkedList::getHead() {
   return new Node(*head);
}

bool LinkedList::isEmpty() {
   return head == nullptr && tail == nullptr;
}

// removes head and replaces it with next, if not nullptr
void LinkedList::removeFront() {
   if(head != nullptr) {
      if(head->next != nullptr) {
         Node* h = head->next;
         delete head;
         head = h;
      } else {
         delete head;
      }
   } 
}
