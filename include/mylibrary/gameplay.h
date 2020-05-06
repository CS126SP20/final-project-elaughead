//
// Created by Emily Laughead on 5/4/20.
//

#ifndef FINALPROJECT_GAMEPLAY_H
#define FINALPROJECT_GAMEPLAY_H

#include "rowLogic.h"
#include "pieceCreation.h"
#include "updater.h"


namespace mylibrary {
class gameplay : public updater2 {
 private:

  int height;
  int width;
  int score = 0;
  int lines = 0;
  int level = 1;

  rowLogic blockGroup;
  pieceCreation pieceCreation1;
  piece currentPiece;
  piece nextPiece;

 public:
  gameplay()
      :width{width}, height{height},
  blockGroup{rowLogic(width, height)}, pieceCreation1{pieceCreation()} {

  };
  ~gameplay();

  int getWidth() const {
    return width;
  }
  int getHeight() const {
    return height;
  }
  int getScore() const {
    return score;
  }
  int getLines() const {
    return lines;
  }
  int getLevel() const {
    return level;
  }
  piece getPiece() const {
    return currentPiece;
  }
  piece getNextPiece() const {
    return nextPiece;
  }
  rowLogic getGroup() const {
    return blockGroup;
  }

  void generateNextPiece();

  bool timeSet();

  bool isLanded();

  bool checksIsLanded() const;

  bool moveRight();

  bool moveLeft();

  bool moveDown();

  void rotatePiece();

  bool checkTouchingPiece(const piece& p) const;

  bool checkTouchingGroup(const piece& p) const;

  bool ooB(const piece& p) const;

  void clear();

};
}

#endif  // FINALPROJECT_GAMEPLAY_H
