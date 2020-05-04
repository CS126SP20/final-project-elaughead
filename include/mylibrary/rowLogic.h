//
// Created by Emily Laughead on 5/4/20.
//

#ifndef FINALPROJECT_ROWLOGIC_H
#define FINALPROJECT_ROWLOGIC_H

#include "piece.h"

namespace mylibrary {
class rowLogic {
 private:

  int width;
  int height;
  std::vector<std::vector<int>> rowPile;

 public:

  rowLogic(int width, int height) :width{ width }, height{ height } {

    rowPile.resize(height);
    for (int i = 0; i < rowPile.size(); i++) {
      rowPile[i].resize(width, 0);
    }
  }

  int getWidth() const {
    return width;
  }
  int getHeight() const {
    return height;
  }
  std::vector<std::vector<int>> getRowPile() const {
    return rowPile;
  }

  int checkRows();

  void removeRow(int row);

  void addPiece(piece& p);

  void clear();
};
}
#endif  // FINALPROJECT_ROWLOGIC_H
