// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#define SCALE 25

#include <cinder/app/App.h>
#include "CinderImGui.h"
#include <mylibrary/gameplay.h>
#include "cinder/Area.h"

namespace myapp {

class MyApp : public cinder::app::App {
 public:

  MyApp() {};
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;


 private:

  cinder::Timer timer;
  bool gameRunning = false;
  mylibrary::gameplay board;


  void keyPressedEvent(cinder::app::KeyEvent);
  void timeSet();


  void startGame();
  void endGame();

  void drawGameArea();
  void gameAreaGui();
  void drawPiece(std::vector<cinder::Color> color);
  void drawGroup(std::vector<cinder::Color> color);

};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
