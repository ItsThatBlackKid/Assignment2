
#include "Node.h"

Node::Node(Tile* tile, Node* next)
{
   // TODO
   this->tile = tile;
   this->next = next;
}

// destructor, only deletes what's in the tile

Node::~Node() {
   delete tile;
}

