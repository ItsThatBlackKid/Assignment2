
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:
   Colour colour;
   Shape  shape;
   Tile(Colour, Shape);
   Tile();
   Tile(Tile& other);

   Shape getShape();
};

#endif // ASSIGN2_TILE_H
