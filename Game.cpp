#include "Game.h"
Game::Game()
{
    renderwindow=nullptr;
    initVariables();
    initWindow();
}

Game:: ~Game()
{
    renderwindow.release();
    renderwindow=nullptr;
}
    
    
    void Game::update()
    {
        pollevents();
    }
    void Game::render()
    {
        /*clear all framesndow
         * render objects
         * display frame in window*/
        
        
        renderwindow->clear(Color(255,0,0,255));
        renderwindow->display();
    }
    void Game::initVariables()
    {
        
    }
    void Game::pollevents()
    {
        while(renderwindow->pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                        renderwindow->close();
                        break;
                case Event::KeyPressed:
                        if(event.key.code==Keyboard::Escape)
                            renderwindow->close();
                            break;
            }
        }
    }
    void Game::initWindow()
    {
        
        videomode.height=600;
        videomode.width=800;
        renderwindow=make_unique<RenderWindow>(videomode,"gaurav_sharma_game",Style::Titlebar|Style::Close);

    }

    //Accessors
    const bool Game::running() const 
    {
        return renderwindow->isOpen();
    }
