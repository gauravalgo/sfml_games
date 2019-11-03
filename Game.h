#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
using namespace sf;
class Game
{
private :
    void initVariables();
    void initWindow();
    //variables Window
    RenderWindow 
public:
    Game();
    virtual ~Game();
    
    
    void update();
    void render();
};
