#include "Game.h"
Game::Game()
{
    renderwindow=nullptr;
    initVariables();
    initWindow();
    initEnemies();
}

Game:: ~Game()
{
    renderwindow.release();
    renderwindow=nullptr;
}
    
    
    void Game::update()
    {
        pollevents();
        //Relativetive to the screen
        updatemousepos();
        
        updateenemies();
        
    }
    void Game::updatemousepos()
    {
        mouseposwindow=Mouse::getPosition(*renderwindow);
        //std::cout<<"relative mouse position "<<Mouse::getPosition().x<<" "<<Mouse::getPosition().y<<endl;
        std::cout<<"window mouse position "<<Mouse::getPosition(*renderwindow).x<<" "<<Mouse::getPosition(*renderwindow).y<<endl;
        mousepositionview = renderwindow->mapPixelToCoords(mouseposwindow); //impoertant concept mapping pixels to co-ordinates
        
    }
    void Game::render()
    {
        /*clear all framesndow
         * render objects
         * display frame in window*/
        
        
        renderwindow->clear(Color(0,0,0,255));
       // renderwindow->draw(enemy);
        renderenemies();
        renderwindow->display();
        
    }
    void Game::initVariables()
    {
        Points=0;
        
        enemiesspawntimerMax=10.f;
        enemiesspawntimer=enemiesspawntimerMax;
        maxEnemies=5;
        
    }
        void Game::spawnenemies()
        {
            
            enemy.setPosition(static_cast<float>(rand()%static_cast<int>((renderwindow->getSize().x - enemy.getSize().x))),
            0.f);
            enemy.setFillColor(Color::Green);
            enemies.push_back(enemy);
        }
        void Game::renderenemies()
        {
            for(auto& e : enemies)
            {
                renderwindow->draw(e);
            }
        }
        void Game::updateenemies()
        {
            //updating the timer for spawnning
            if(enemies.size()<maxEnemies)
            {
                if(enemiesspawntimer>=enemiesspawntimerMax)
                {
                    spawnenemies();
                    enemiesspawntimer=0.f;
                }
                    else
                    enemiesspawntimer+=1.f;
            }
            int i=0;
            
            for(auto& e: enemies)
            {
                bool deleted=false; 
                e.move(0.f,1.f);
               if(Mouse::isButtonPressed(Mouse::Left))
               {
                    if(e.getGlobalBounds().contains(mousepositionview))
                    {
                        deleted=true;
                    }
                }
               if(e.getPosition().y>renderwindow->getSize().y)
               {
                   deleted=true;
                }
                if(deleted)
                {
                    enemies.erase(enemies.begin()+i);
                    Points+=10;
                }
               i++;
            }
            
            
        }

    void Game::initEnemies()
    {
        enemy.setPosition(Vector2f(20.f,20.f));
        enemy.setSize(Vector2f(100.f,100.f));
        enemy.setScale(Vector2f(0.5f,0.5f));
        enemy.setFillColor(Color::Cyan);
      /*  enemy.setOutlineColor(Color::Green);
        enemy.setOutlineThickness(1.f);*/
        
        
        
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
        renderwindow->setFramerateLimit(144);

    }

    //Accessors
    const bool Game::running() const 
    {
        return renderwindow->isOpen();
    }
