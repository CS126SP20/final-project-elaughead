// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <cinder/gl/wrapper.h>

#include "CinderImGui.h"

namespace myapp {


using cinder::app::KeyEvent;
using cinder::gl::clear;
using cinder::gl::color;

void MyApp() {}
void MyApp::setup() {
  ImGui::initialize();

}

void MyApp::update() { }

void MyApp::draw() {
  cinder::gl::enableAlphaBlending();
  cinder::gl::clear(cinder::Color(252, 0, 236));

  //drawGameArea();


  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
  ImGui::Begin("Red Window");
  ImGui::PopStyleColor();
  ImGui::Text("Hello world!");
  ImGui::End();



}

void MyApp::keyDown(KeyEvent event) { }



void myapp::MyApp::keyPressEvent() {
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  if (ImGui::IsKeyPressed('s')) {
    startGame();
  }
  if (gameRunning) {
    try {
      if (ImGui::IsKeyPressed('d')) {
        board.moveRight();
      }
      if (ImGui::IsKeyPressed('a')) {
        board.moveLeft();
      }
      if (ImGui::IsKeyPressed('s')) {
        board.moveDown();
      }
      if (ImGui::IsKeyPressed('w')) {
        board.rotatePiece();
      }
    }
    catch(cinder::Exception e) {
      endGame();
    }

  }
  drawGameArea();
}

void myapp::MyApp::initComp() {
  //initialization of the game board
}

void myapp::MyApp::initSlots() {
  //idk what this does. do i even need it.
}

void myapp::MyApp::timeSet() {
  //setting timer for game
  try {
    board.timeSet();
  }
  catch (cinder::Exception e) {
    endGame();
  }

  timer.start();
  //might not need the below lines of code
  //if (timer.getSeconds() == 850 - board.getLevel()*150) {
   // myapp::MyApp::endGame();
  //}
}

void myapp::MyApp::startGame() {
  board.clear();
  gameRunning = true;
  board.generateNextPiece();
  //might need to change this to an if statement like above
  timer.start(700);
}

void myapp::MyApp::endGame() {
  timer.stop();
}

void myapp::MyApp::drawGameArea(){
  const std::vector<cinder::Color> colors = {cinder::Color::hex(0x00FFFF), cinder::Color::hex(0xFFFF00), cinder::Color::hex(0xBB00FF), cinder::Color::hex(0x0dff00), cinder::Color::hex(0xff1100), cinder::Color::hex(0x0004ff), cinder::Color::hex(0xffaa00) };
  mylibrary::rowLogic p = board.getGroup();

  //set background color
  for (int i = 0; i < board.getHeight(); i++) {
    for (int j = 0; j < board.getWidth(); j++) {
      ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
      ImGui::Begin("Red Window");
      ImGui::PopStyleColor();
      ImGui::End();
      clear(cinder::Color(23, 200, 0));
    }
  }

  drawGroup(colors);
  drawPiece(colors);
}

void myapp::MyApp::drawPiece(std::vector<cinder::Color> color) {
  mylibrary::piece p = board.getPiece();
  auto shape = p.getShape();

  for (int i = 0; i < shape.size(); i++) {
    for (int j = 0; j < shape[i].size(); j++) {
      if (shape[i][j] > 0 && p.getY() + i >= 0 && p.getX() + j >= 0) {
        //do some shit here idk
      }
    }
  }
}

void myapp::MyApp::drawGroup(std::vector<cinder::Color> color) {

  mylibrary::rowLogic r = board.getGroup();
  auto group = r.getRowPile();

  for (int i = 0; i < group.size(); i++) {
    for (int j = 0; j < group[i].size(); j++) {
      if (group[i][j] > 0) {
        //more shit here
      }
    }
  }
}

}

// namespace myapp
