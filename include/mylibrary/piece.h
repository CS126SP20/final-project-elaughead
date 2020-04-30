//
// Created by Emily Laughead on 4/30/20.
//

#ifndef FINALPROJECT_PIECE_H
#define FINALPROJECT_PIECE_H

#include <vector>
namespace mylibrary {
class piece {
 private:
  int pieceId;
  static int pieceIds;
  int x;
  int y;
  std::vector<std::vector<int>> shape;

 public:
  piece(){};

  piece(const int x, const int y)
      : id{generateId()},
        x{x},
        y{y} {

        };

  piece(const piece& p) {
    pieceId = p.pieceId;
    x = p.x;
    y = p.y;
    shape = p.shape;
  }
  // Getters
  int getId() const { return pieceId; }
  int getX() const { return x; }
  int getY() const { return y; }
  std::vector<std::vector<int>> getShape() const { return shape; }

  // Setters
  void setShape(const std::vector<std::vector<int>>& newShape) {
    shape = newShape;
  }
  void setX(const int x) { this->x = x; }
  void setY(const int y) { this->y = y; }

  const static int generateId() {
    pieceIds++;
    return pieceIds;
  }

  // shape movement
  void rotate();
  void moveRight();
  void moveLeft();
  void moveDown();
  bool dimension() const;
};
}

#endif  // FINALPROJECT_PIECE_H
