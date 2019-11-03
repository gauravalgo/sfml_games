#include <iostream>

#include "Game.h"
using namespace std;
using namespace sf;

int main() {

  // Code adapted from the SFML 2 "Window" example.

  //cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << endl;

  RenderWindow App(VideoMode(800, 600), "myproject",Style::Titlebar|Style::Close);
  Event Event; 
  while (App.isOpen()) {
    
    while (App.pollEvent(Event)) {
      switch(Event.type) 
      {
          case Event::Closed:
              App.close();
              break;
          case Event::KeyPressed: 
              if(Event.key.code == Keyboard::Escape)
                  App.close();
              break;
              
      
    }
    App.clear(Color(255,255,255,255));
    App.display();
  }
}
}
