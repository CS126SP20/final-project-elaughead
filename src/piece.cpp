//
// Created by Emily Laughead on 4/30/20.
//

#include "mylibrary/piece.h"


namespace mylibrary {

int piece::pieceIds = 0;

//Rotates the piece
void piece::rotate() {
  std::vector<std::vector<int>> newShape{ shape };

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      newShape[j][shape.size() - i - 1] = shape[i][j];
    }
    setShape(newShape);
  }
}

//Moves the piece to the right
void piece::moveRight() {
  x++;
}

//Moves the piece to the left
void piece::moveLeft() {
  x--;
}

//Moves the piece down
void piece::moveDown() {
  y++;
}

//Returns true if the shape is not empty
bool piece::dimension() const {
  return !shape.empty();
}
}
