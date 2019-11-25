#include <iostream>

#include "Game.h"
using namespace std;
using namespace sf;

int main() {

  // Code adapted from the SFML 2 "Window" example.

  //cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

  Game game;

  while (game.running()) {
    
    game.update();
    game.render();
}
}
