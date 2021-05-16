
#include "LinkedList.h"

LinkedList::LinkedList()
{
   head = nullptr;
   tail = nullptr;
   size = 0;

   // TODO
}

LinkedList::~LinkedList()
{
   this->clear();
}

int LinkedList::getSize()
{
   return size;
}

void LinkedList::clear()
{

   while (head != nullptr)
   {
      Node *curr = head->next;
      delete head;
      head = curr;
   }

   size = 0;
}

void LinkedList::addFront(Tile *tile)
{
   Node *front = new Node(tile, head);
   head = front;
   size++;
}

void LinkedList::addBack(Tile *tile)
{
   Node *back = new Node(tile, nullptr);
   if (head == nullptr)
   {
      head = back;
   }
   else if (tail != nullptr)
   {
      tail->next = back;
      tail = back;
   }
   else
   {
      tail = back;
      head->next = tail;
   }
   size++;
}

Node *LinkedList::get(int i)
{
   int counter = 0;
   Node *h = head;
   while (counter < i && h->next != nullptr)
   {
      h = h->next;
      counter++;
   }

   return h;
}

Node *LinkedList::getHead()
{
   return head;
}

bool LinkedList::isEmpty()
{
   return head == nullptr && tail == nullptr;
}

// removes head and replaces it with next, if not nullptr
void LinkedList::removeFront()
{
   if (head != nullptr)
   {
      if (head->next != nullptr)
      {
         Node *h = head->next;
         delete head;
         head = h;
      }
      delete head;
   }
}

void LinkedList::remove(int i)
{
   if (i > 0 && i < size)
   {
      Node *n0 = get(i - 1);
      Node *n1 = get(i + 1);
      n0->next = n1;
      size++;
   }
   else if (i == 0)
   {
      removeFront();
   }
   else if (i == size)
   {
      this->tail = nullptr;
   }

   size--;
}
