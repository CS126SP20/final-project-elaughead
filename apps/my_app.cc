// Copyright (c) 2020 Emily Laughead. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>
#include <stdint.h>
#include <stdlib.h>

#include "CinderImGui.h"
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
  bool* p_open;
  PieceGui(p_open);
}

void MyApp::draw() {

  cinder::gl::enableAlphaBlending();


}

void MyApp::keyDown(KeyEvent event) {

  //enabled keyboard inputs through imgui
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
  board.timeSet();
}

//ends the game
void myapp::MyApp::endGame() {
  gameRunning = false;
  timer.stop(); }

//draws the game area
void myapp::MyApp::drawGameArea() {
  cinder::gl::clear(cinder::Color(252, 0, 236));
  const std::vector<cinder::Color> colors = {
      cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00),
      cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00),
      cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff),
      cinder::Color::hex(0xffaa00)};
  mylibrary::rowLogic p = board.getGroup();
  for (int i = 0; i < board.getHeight(); i++) {
    for (int j = 0; j <board.getWidth(); j++) {

    }
  }

  drawGroup(colors);
  drawPiece(colors);

}

//draws a single piece
void myapp::MyApp::drawPiece(std::vector<cinder::Color> color) {
  mylibrary::piece p = board.getPiece();
  auto shape = p.getShape();
  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if (shape[i][j] > 0 && p.getY() + i >= 0 && p.getX() + j >= 0) {
        //ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(), ImVec2(p.getX() + i,p.getY() + j), 0x00FFFF);
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
        ImGui::GetWindowDrawList()->AddRectFilled(ImVec2(), ImVec2(i,j), 0x00FFFF);

      }
    }
  }
}

//imgui code, setting up multiple windows
void myapp::MyApp::gameAreaGui() {

  //main window where game is played
  /*ImGui::Begin("Tetris");

  KeyEvent event;
  keyPressedEvent(event);
  ImGui::End(); */
  drawGameArea();

  //window that keeps track of score, level, lines, and generates the next piece
  ImGui::Begin("Tetris2");
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding
      , ImVec2(0, 18));
  ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImVec4(0.16f, 0.16f, 0.16f, 1.00f));
  ImVec2 toolbarSize(150, 150);
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
  //board.generateNextPiece();
  mylibrary::piece p = board.getNextPiece();
  auto shape = p.getShape();
  const std::vector<cinder::Color> colors = {
      cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00),
      cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00),
      cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff),
      cinder::Color::hex(0xffaa00)};
  ImDrawList* draw_list = ImGui::GetWindowDrawList();

  static float sz = 25.0f;
  static float thickness = 4.0f;
  static ImVec4 col = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);

  {
    const ImVec2 p = ImGui::GetCursorScreenPos();
    const ImU32 col32 = ImColor(col);
    float x = p.x + 3.0f, y = p.y + 3.0f; //spacing = 8.0f;
    board.generateNextPiece();
    mylibrary::piece pi = board.getNextPiece();
    auto shape = pi.getShape();
    auto x2 = pi.getX();
    auto y2 = pi.getY();
    for (int i = 0; i < shape.size(); i++) {
      for (int j = 0; j < shape[i].size(); j++) {
        auto x2 = pi.getX() + j;
        auto y2 = pi.getY() + i;
        if (shape[i][j] > 0)/* && y2 >= 0 && x2 >= 0)*/ {
          draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col32);
          x += sz; //+ spacing;
          ImGui::Dummy(ImVec2((sz ) * 8, (sz) * 3));
        }
      }
    }

  }
  ImGui::EndChild();
  ImGui::PopStyleColor();
  ImGui::PopStyleVar();

  ImGui::End();
}

void  myapp::MyApp::PieceGui(bool* p_open)
{
  ImGui::SetNextWindowSize(ImVec2(350, 560), ImGuiCond_FirstUseEver);
  if (!ImGui::Begin("Tetris", p_open))
  {
    ImGui::End();
    return;
  }
  KeyEvent event;
  keyDown(event);

  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  static float sz = 36.0f;
  static float thickness = 4.0f;
  static ImVec4 col = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);

  {
    const ImVec2 p = ImGui::GetCursorScreenPos();
    const ImU32 col32 = ImColor(col);
    float x = p.x + 4.0f, y = p.y + 4.0f; //spacing = 8.0f;
    //board.generateNextPiece();
    mylibrary::piece pi = board.getNextPiece();
    auto shape = pi.getShape();
    /*if (shape == mylibrary::Shape::L) {

    }*/
    for (int i = 0; i < shape.size(); i++) {
      for (int j = 0; j < shape[i].size(); j++) {
        if (shape[i][j] > 0) {
          draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col32);
          x += sz; //+ spacing;
          //ImGui::Dummy(ImVec2((sz ) * 8, (sz) * 3));
        }
      }
    }

  }

  ImGui::End();
}

}


// namespace myapp
