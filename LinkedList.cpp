
#include "LinkedList.h"

#include <iostream>

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
   while (counter != i && h != nullptr)
   {
      h = h->next;
      counter++;

   }

   return h;
}

Tile *LinkedList::getTile(string tile)
{
   bool found = false;
   Tile *toReturn = nullptr;
   Node *h = head;
   // while not the tail node
   while (h != nullptr && !found) {
      if(h->tile->colour == tile[0] && h->tile->shape == tile[1] - '0' ) {
         toReturn = h->tile;
         found = true;
      }
      h = h->next;
   }

   return toReturn;
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
         head = h;
      }
   }
   size--;
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

ostream &operator<<(ostream &os, LinkedList &list)
{
   Node* h = list.getHead();
   while (h != nullptr)
   {
      Tile *t = h->tile;

      os << t->colour << t->shape << ",";
      h = h->next;
   }
   return os;
}

ofstream &operator<<(ofstream &of, LinkedList &list)
{
   int count = 0;
   while (count < list.getSize())
   {
      of << list.get(count)->tile << ",";
      count++;
   }
   of << std::endl;
   return of;
}

ifstream &operator>>(ifstream &in, LinkedList *list)
{
   string line;
   std::getline(in, line);
   stringstream ss(line);

   vector<string> tiles;

   while (ss.good())
   {
      string sub;
      getline(ss, sub, ',');
      if(sub[0] == ' ') {
         sub = sub[1];
         sub += sub[2];
      }
      tiles.push_back(sub);
   }

   Tile *t = nullptr;
   for (string s : tiles)
   {
      t = new Tile(s[0], s[1] - '0');
      list->addBack(t);
   }

   std::cout << "hand: " << *list << std::endl;

   return in;
}