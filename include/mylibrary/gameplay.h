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

  float timer = 0;
  float delay = 0.3;
  int height = 20;
  int width = 20;
  int score = 0;
  int lines = 0;
  int level = 1;


  rowLogic blockGroup;
  pieceCreation pieceCreation1;
  piece currentPiece;
  piece nextPiece;

 public:

  //constructor
  gameplay()
      :width{width = 20}, height{height = 20},
  blockGroup{rowLogic(width, height)}, pieceCreation1{pieceCreation()} {

  };

  //deconstructor
  ~gameplay();

  //getters
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

  //generates the next piece randomly
  void generateNextPiece();

  //sets the timer
  bool timeSet();

  //logic for a piece that has landed
  bool isLanded();

  //checks to see if the piece has landed
  bool checksIsLanded() const;

  //moves piece right
  bool movePieceRight();

  //moves piece left
  bool movePieceLeft();

  //moves piece down
  bool movePieceDown();

  //roatates piece
  void rotatePiece();

  //checks if a piece is touching another piece
  bool checkTouchingPiece(const piece& p) const;

  //checks if the piece is touching the group
  bool checkTouchingGroup(const piece& p) const;

  //out of bounds
  bool ooB(const piece& p) const;

  //clears board
  void clear();

};
}

#endif  // FINALPROJECT_GAMEPLAY_H
