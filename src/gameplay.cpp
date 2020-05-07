//
// Created by Emily Laughead on 5/4/20.
//

#include "mylibrary/gameplay.h"


namespace mylibrary{


gameplay::~gameplay() {

}

//generates the next piece
void gameplay::generateNextPiece() {
  if (!nextPiece.dimension()) {
    nextPiece = pieceCreation1.randomPiece(width / 2 - 1, 0);
    nextPiece.setY(nextPiece.getShape().size()*(-1));
  }

  currentPiece = nextPiece;
  nextPiece = pieceCreation1.randomPiece(width / 2 - 1, 0);
  nextPiece.setY(nextPiece.getShape().size()*(-1));

  isLanded();

  notify();

}

//moves the piece down as the timer goes
bool gameplay::timeSet() {
  movePieceDown();
  return true;
}

//generates the next piece if the piece has landed
bool gameplay::isLanded() {
  if (checksIsLanded()) {
    blockGroup.addPiece(currentPiece);
    int totalLines = blockGroup.checkRows();
    lines += totalLines;
    score += totalLines * level * 100;
    if (totalLines >= 4) {
      score += totalLines * level * 100;
    }
    level = lines / 9;
    generateNextPiece();
    notify();
    return true;

  }
  return false;
}

//checks to see if a piece has landed or not
bool gameplay::checksIsLanded() const {

  int x = currentPiece.getX();
  int y = currentPiece.getY();

  auto shape = currentPiece.getShape();
  //change the name of getRowPile() to getGroup();
  auto group = blockGroup.getRowPile();

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[0].size(); j++) {
      if ((((y + i + 1) >= height && shape[i][j] > 0) ||
      (y + i + 1 >=0 && x + j >= 0 && shape[i][j] > 0 && group[y + i + 1][x + j] > 0))) {
        return true;
      }
    }
  }
  return false;
}

//moves the piece right
bool gameplay::movePieceRight() {
  piece piece2 = piece{ currentPiece };
  piece2.moveRight();

  if (!checkTouchingPiece(piece2)) {
    currentPiece.moveRight();
    isLanded();
    return true;
  }
  return false;
}

//moves the piece left
bool gameplay::movePieceLeft() {
  piece piece2 = piece{ currentPiece };
  piece2.moveLeft();

  if (!checkTouchingPiece(piece2)) {
    currentPiece.moveLeft();
    isLanded();
    return true;
  }
  return false;
}

//moves the piece down
bool gameplay::movePieceDown() {
  piece piece2 = piece{ currentPiece };
  piece2.moveDown();

  if (!checkTouchingPiece(piece2)) {
    currentPiece.moveDown();
    isLanded();
    return true;
  }
  return false;
}

//rotates the piece
void gameplay::rotatePiece() {

  piece piece2 = piece{ currentPiece };
  piece2.rotate();

  if (!checkTouchingPiece(piece2)) {
    currentPiece.rotate();
    isLanded();
  }
}

//checks if the piece is touching the group or out of bounds
bool gameplay::checkTouchingPiece(const piece &p) const {
  return checkTouchingGroup(p) || ooB(p);
}

//adds piece to the group if it is touching
bool gameplay::checkTouchingGroup(const piece &p) const {

  if (ooB(p)) {
    return true;
  }

  int x = p.getX();
  int y = p.getY();

  auto shape = p.getShape();

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if ((x + j >= 0 && x + j < width && y + i >= 0 && y + i < height)
      && blockGroup.getRowPile()[y + i][x + j] > 0 && shape[i][j] > 0) {
        return true;
      }
    }
  }
  return false;
}

//determines if out of bounds or not
bool gameplay::ooB(const piece &p) const {

  int x = p.getX();
  int y = p.getY();

  auto shape = p.getShape();

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[0].size(); j++) {
      if (shape[i][j] > 0 && (x + j >= width || y + i >= height || x + j < 0)) {
        return true;
      }
    }
  }
  return false;
}

//clears the group, resets everything
void gameplay::clear() {

  blockGroup.clear();
  nextPiece = pieceCreation1.getPiece(Shape::Empty, 0, 0, 1);
  score = 0;
  lines = 0;
  level = 1;
}
}