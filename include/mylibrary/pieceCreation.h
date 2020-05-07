//
// Created by Emily Laughead on 4/30/20.
//

#ifndef FINALPROJECT_PIECECREATION_H
#define FINALPROJECT_PIECECREATION_H

#include "piece.h"
#include <random>

namespace mylibrary {

//Enum class of all the tetriminos
enum class Shape{L,T,Z,S,I,J,O,Empty};

class pieceCreation {

 public:

  //Deconstructor & constructor
  ~pieceCreation();
  pieceCreation();

  //Getter
  piece getPiece(const Shape& s, int c, int x, int y) const;

  //Picks a random piece
  piece randomPiece(const int x, const int y) const;
};
}
#endif  // FINALPROJECT_PIECECREATION_H
