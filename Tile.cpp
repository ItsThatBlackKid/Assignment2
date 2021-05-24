
#include "Tile.h"

// Empty... for now?

Tile::Tile(Colour colour, Shape shape)
{
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile()
{
    // do nothing
}

Tile::Tile(Tile &other)
{
    this->colour = other.colour;
    this->shape = other.shape;
}

bool Tile::canPlace(Tile *onBoard)
{
    bool canPlace = false;
    bool sameShape = shape == onBoard->shape;
    bool sameColour = colour == onBoard->colour;
    if (sameShape)
    {
        canPlace = !sameColour;
    }
    else if (sameColour)
    {
        canPlace = !sameShape;
    }

    return canPlace;
}

bool Tile::canPlace(Tile *onBoard, bool isLine)
{
    bool canPlace = false;
    if (isLine)
    {
        bool sameShape = shape == onBoard->shape;
        bool sameColour = colour == onBoard->colour;

        if (sameShape)
        {
            canPlace = !sameColour;
        }
        else if (sameColour)
        {
            canPlace = !sameShape;
        }
    }

    return canPlace;
}

Shape Tile::getShape()
{
    return this->shape;
}

ostream &operator<<(ostream &os, const Tile &t)
{
    os << t.colour << t.shape;
    return os;
}

ofstream &operator<<(ofstream &of, const Tile &t)
{
    of << t.colour << t.shape;
    return of;
}

ifstream &operator>>(ifstream &in, Tile &t)
{
    in >> t.colour;
    in >> t.shape;

    return in;
}
