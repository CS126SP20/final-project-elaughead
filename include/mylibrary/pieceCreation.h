//
// Created by Emily Laughead on 4/30/20.
//

#ifndef FINALPROJECT_PIECECREATION_H
#define FINALPROJECT_PIECECREATION_H

#include "piece.h"
#include <random>

namespace mylibrary {
enum class Shape{L,T,Z,S,I,J,O,Empty};
class pieceCreation {
  pieceCreation();
  ~pieceCreation();

  piece getPiece(const Shape& s, const int c, int x, int y) const;

  piece randomPiece(const int x, const int y) const;
};
}
#endif  // FINALPROJECT_PIECECREATION_H
