// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"
#include "CinderImGui.h"


#include <cinder/app/App.h>


namespace myapp {

using cinder::app::KeyEvent;



MyApp::MyApp() {

}

void MyApp::setup() {
  ImGui::initialize();
  ImGui::Text("Hello, world %d", 123);

}

void MyApp::update() { }

void MyApp::draw() { }

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
