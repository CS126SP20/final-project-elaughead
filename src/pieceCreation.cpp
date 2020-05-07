//
// Created by Emily Laughead on 4/30/20.
//

#include "mylibrary/pieceCreation.h"

namespace mylibrary {

//Constructor
pieceCreation::pieceCreation() {}

//Deconstructor
pieceCreation::~pieceCreation() {}

//Creates the pieces based on their names
piece pieceCreation::getPiece(const mylibrary::Shape& s, const int c, int x,
                              int y) const {
  piece l = piece(x,y);

  if (s == Shape::L) {
    l.setShape({
                   {0, c, 0},
                   {0, c, 0},
                   {0, c, c}

    });
  }
  else if (s == Shape::T) {
    l.setShape({
                   {0, 0, 0},
                   {0, c, 0},
                   {c, c, c}
    });
  }
  else if (s == Shape::Z) {
    l.setShape({
                   {0, 0, 0},
                   {c, c, 0},
                   {0, c, c}
    });
  }
  else if (s == Shape::S) {
    l.setShape({
                   {0, 0, 0},
                   {0, c, c},
                   {c, c, 0}
               });
  }
  else if (s == Shape::I) {
    l.setShape({
                   {0, 0, c, 0},
                   {0, 0, c, 0},
                   {0, 0, c, 0},
                   {0, 0, c, 0}
               });
  }
  else if (s == Shape::J) {
    l.setShape({
                   {0, c, 0},
                   {0, c, 0},
                   {c, c, 0}
               });
  }
  else if (s == Shape::O) {
    l.setShape({
                   {0, 0, 0, 0},
                   {0, c, c, 0},
                   {0, c, c, 0},
                   {0, 0, 0, 0}
               });
  }
  return l;
  }

  //Generates a random piece using Mersenne Twister 19937 generator
  piece pieceCreation::randomPiece(const int x, const int y) const {

  std::random_device random2;
  std::mt19937 mt(random2());
  std::uniform_real_distribution<double> dist(1.0, 1000.0);

  Shape  s = Shape((int)dist(mt) % 7);

  int color = (int)dist(mt) % 5 + 1;

  return getPiece(s, color, x, y);
}

}