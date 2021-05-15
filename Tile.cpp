
#include "Tile.h"

// Empty... for now?

Tile::Tile() {
    // do nothing
}

Tile::Tile(Tile& other) {
    this->colour = other.colour;
    this->shape = other.shape;
}

Shape Tile::getShape() {
    return this->shape;
}