//
// Created by Emily Laughead on 5/4/20.
//

#include "mylibrary/rowLogic.h"

#include <cinder/Exception.h>

namespace mylibrary {

int rowLogic::checkRows() {

  int remove = 0;

  for (int i = 0; i < height; i++) {
    bool fullRow = true;
    for (int j = 0; j < width; j++) {
      if (rowPile[i][j] == 0) {
        fullRow = false;
      }
    }
    if (fullRow == true) {
      removeRow(i);
      remove++;
    }
  }
  return remove;
}

void rowLogic::removeRow(int row) {
  for (int i = row; i >= 1; i--) {
    for (int j = 0; j < width; j++) {
      rowPile[i][j] = rowPile[i-1][j];
    }
  }
  for (int k = 0; k < width; k++) {
    rowPile[0][k] = 0;
  }
}

void rowLogic::addPiece(const piece &p) {

  int x = p.getX();
  int y = p.getY();

  std::vector<std::vector<int>> shape = p.getShape();

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if (shape[i][j] > 0) {
        if (y + i < 0 || x + j < 0) {
          throw cinder::Exception{"out of bounds"};
        }
        rowPile[y + i][x + j] = shape[i][j];
      }
    }
  }
}

void rowLogic::clear() {
  for (auto & row : rowPile) {
    for (auto & block : row) {
      block = 0;
    }
  }
}
}