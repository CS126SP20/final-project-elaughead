//
// Created by Emily Laughead on 4/30/20.
//

#include "mylibrary/piece.h"


namespace mylibrary {

int piece::pieceIds = 0;

void piece::rotate() {
  std::vector<std::vector<int>> newShape{ shape };

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      newShape[j][shape.size() - i - 1] = shape[i][j];
    }
    setShape(newShape);
  }
}

void piece::moveRight() {
  x++;
}

void piece::moveLeft() {
  x--;
}

void piece::moveDown() {
  y++;
}

bool piece::dimension() const {
  return !shape.empty();
}
}
