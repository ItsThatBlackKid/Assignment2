
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H
#include <iostream>
#include <fstream>

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

using std::ostream;
using std::ifstream;
using std:: ofstream;
class Tile {
public:
   Colour colour;
   Shape  shape;
   Tile();
   Tile(Colour colour, Shape shape);
   Tile(Tile& other);

   Shape getShape();

   // overloaded terminal output operator
   friend ostream& operator << (ostream& os, const Tile& t);
   // overloaded file output operator
   friend ofstream& operator<<(ofstream& of, const Tile& t); 
   // overloaded file input operator
   friend ifstream& operator>>(ifstream& in, Tile& t); 


   
};

#endif // ASSIGN2_TILE_H
