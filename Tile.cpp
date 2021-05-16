
#include "Tile.h"

// Empty... for now?

Tile::Tile(Colour colour, Shape shape) {
    this->colour = colour;
    this->shape = shape;
}

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

ostream& operator<<(ostream& os, const Tile& t) {
    os << t.colour << t.shape;
}

ofstream& operator<<(ofstream& of, const Tile&t) {
    of << t.colour << t.shape;
}

ifstream& operator>>(ifstream& in, Tile& t) {
    char c;
    char s;
    in >> t.colour;
    in >> t.shape;
}

