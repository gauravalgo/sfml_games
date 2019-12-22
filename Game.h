#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <eigen3/Eigen/Core>
#include <memory>
#include <iostream>
#include <type_traits>
#include <vector>
#include <ctime>
using namespace std;
using namespace sf;
class Game
{
private :
    void initVariables();
    void initWindow();
    //variables Window
    unique_ptr<RenderWindow> renderwindow;
    VideoMode videomode;
    Event event;
    RectangleShape enemy;
    void initEnemies();
    Vector2i mouseposwindow;
    Vector2f mousepositionview;
    vector<RectangleShape> enemies;
    
    float enemiesspawntimer;
    float enemiesspawntimerMax;
    int maxEnemies;
    int Points;
public:
    Game();
    virtual ~Game();
    void updatemousepos();
    const bool running() const ;
    void pollevents();
    void update();
    void render();
    void updateenemies();
    void renderenemies();
    void spawnenemies();
};
