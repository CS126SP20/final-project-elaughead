// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>
#include <stdint.h>
#include <stdlib.h>

//#include "CinderImGui.h"
using namespace ci;
using namespace ci::app;
namespace myapp {

using cinder::app::KeyEvent;
using cinder::gl::clear;
using cinder::gl::color;

void MyApp() {}
void MyApp::setup() { ImGui::initialize(); }

void MyApp::update() {
  gameAreaGui();
}

void MyApp::draw() {
  cinder::gl::enableAlphaBlending();
  //gameAreaGui();
  drawGameArea();
}
//void MyApp::keyPressedEvent(cinder::app::KeyEvent event) {
  //switch (event.getCode()) {
   // case KeyEvent::KEY_SPACE: {
      //startGame();
    //}
    //case KeyEvent::KEY_UP: {
     // board.rotatePiece();
   // }
    //case KeyEvent::KEY_DOWN: {
     // board.moveDown();
    //}
    //case KeyEvent::KEY_LEFT: {
     // board.moveLeft();
    //}
    //case KeyEvent::KEY_RIGHT: {
     // board.moveRight();
    //}
  //}
//}

void MyApp::keyPressedEvent(KeyEvent event) {

  //enabled keyboard iputs through imgui
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
 io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

 //takes in certain keyboard inputs and makes actions based on them
  if (ImGui::IsKeyPressed('p')) {
    ImGui::Text("hello");
    startGame();
  }
  if (gameRunning) {
    try {
      if (ImGui::IsKeyPressed('d')) {
        board.movePieceRight();
      }
      if (ImGui::IsKeyPressed('a')) {
        board.movePieceLeft();
      }
      if (ImGui::IsKeyPressed('s')) {
        board.movePieceDown();
      }
      if (ImGui::IsKeyPressed('w')) {
        board.rotatePiece();
      }
    } catch (cinder::Exception e) {
      endGame();
    }
  }

}

void myapp::MyApp::timeSet() {
  // setting timer for game
  try {
    board.timeSet();
  } catch (cinder::Exception e) {
    endGame();
  }

  timer.start();
  // might not need the below lines of code
  // if (timer.getSeconds() == 850 - board.getLevel()*150) {
  // myapp::MyApp::endGame();
  //}
}

//starts the game
void myapp::MyApp::startGame() {
  board.clear();
  gameRunning = true;
  board.generateNextPiece();

  // might need to change this to an if statement like above
  //timer.start(800);
}

//ends the game
void myapp::MyApp::endGame() { timer.stop(); }

//draws the game ares
void myapp::MyApp::drawGameArea() {
  cinder::gl::clear(cinder::Color(252, 0, 236));
  const std::vector<cinder::Color> colors = {
      cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00),
      cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00),
      cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff),
      cinder::Color::hex(0xffaa00)};
  mylibrary::rowLogic p = board.getGroup();



  drawGroup(colors);
  drawPiece(colors);

}

//draws a single piece
void myapp::MyApp::drawPiece(std::vector<cinder::Color> color) {
  mylibrary::piece p = board.getPiece();
  auto shape = p.getShape();
  ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(), ImVec2(10,20), ImGui::ColorConvertFloat4ToU32(ImVec4(1, .15, .15, 1)));

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if (shape[i][j] > 0 && p.getY() + i >= 0 && p.getX() + j >= 0) {
        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(), ImVec2(10,30), 0x00FFFF);
      }
    }
  }
}

//draws the group of pieces
void myapp::MyApp::drawGroup(std::vector<cinder::Color> color) {
  const std::vector<cinder::Color> colors = {
      cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00),
      cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00),
      cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff),
      cinder::Color::hex(0xffaa00)};
  mylibrary::rowLogic r = board.getGroup();
  auto group = r.getRowPile();

  for (int i = 0; i < group.size(); i++) {
    for (int j = 0; j < group[i].size(); j++) {
      if (group[i][j] > 0) {

      }
    }
  }
}

//imgui code, setting up multiple windows
void myapp::MyApp::gameAreaGui() {

  //main window where game is played
  ImGui::Begin("Tetris");
  auto globalDrawlist = ImGui::GetOverlayDrawList();
  KeyEvent event;
  keyPressedEvent(event);
  ImGui::End();


  //window that keeps track of score, level, lines, and generates the next piece
  ImGui::Begin("Tetris2");
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding
      , ImVec2(0, 18));
  ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0.16f, 0.16f, 0.16f, 1.00f));
  ImVec2 toolbarSize(100, 100);
  ImGui::BeginChild("name", toolbarSize, false);
  ImGui::Text( "Score: %i", board.getScore());
  ImGui::Text( "Level: %i", board.getLevel());
  ImGui::Text( "Lines: %i", board.getLines());
  ImGui::EndChild();
  ImGui::PopStyleColor();
  ImGui::PopStyleVar();


  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding
      , ImVec2(0, 18));
  ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0.16f, 0.16f, 0.16f, 1.00f));
  ImGui::BeginChild("name2", toolbarSize, false);
  ImGui::Text("Next Piece:");

  mylibrary::piece p = board.getNextPiece();
  auto shape = p.getShape();
  const std::vector<cinder::Color> colors = {
      cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00),
      cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00),
      cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff),
      cinder::Color::hex(0xffaa00)};

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if (shape[i][j] > 0) {
        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(), ImVec2(20,20), 0x00FFFF);
      }
    }
  }
  ImGui::EndChild();
  ImGui::PopStyleColor();
  ImGui::PopStyleVar();

  ImGui::End();
}



}


// namespace myapp
