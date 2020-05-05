//
// Created by Emily Laughead on 5/4/20.
//

#ifndef FINALPROJECT_UPDATER_H
#define FINALPROJECT_UPDATER_H

#include <vector>
#include <algorithm>

namespace mylibrary {
class updater {
 public:
  virtual void update() = 0;
};

class updater2 {
 private:
  std::vector<updater*> updtr;

 public:
  void attach(updater* u) {
    updtr.push_back(u);
  }
  void detach(updater* u) {
    updtr.erase(std::remove(updtr.begin(), updtr.end(), u), updtr.end());
  }
  void notify() {
    for (std::vector<updater*>::const_iterator iterator = updtr.begin(); iterator != updtr.end(); iterator++) {
      if ((*iterator) != 0) {
        (*iterator)->update();
      }
    }
  }
};
}
#endif  // FINALPROJECT_UPDATER_H
