// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include "CinderImGui.h"
#include <mylibrary/gameplay.h>



namespace myapp {

class MyApp : public cinder::app::App {
 public:

  MyApp() {
    initComp();
    initSlots();
  };
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;


 private:

  cinder::Timer timer;
  bool gameRunning = false;
  mylibrary::gameplay board;

  void keyPressEvent();
  void timeSet();

  void initComp();
  void initSlots();

  void startGame();
  void endGame();

  void drawGameArea();
  void drawPiece();
  void drawGroup();

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
