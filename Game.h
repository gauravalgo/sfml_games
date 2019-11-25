#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <eigen3/Eigen/Core>
#include <memory>
#include <type_traits>
#include <CGAL/Simple_cartesian.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;

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
public:
    Game();
    virtual ~Game();
    
    const bool running() const ;
    void pollevents();
    void update();
    void render();
};
