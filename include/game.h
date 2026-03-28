#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>

class game {
private:
    //varibles
        //window
    sf::RenderWindow* window_;
    sf::VideoMode VideoMode_;
    sf::Event window_event_;    


    //private functions:
    void initVariables();
    void initWindow();
public:
    //constructor / deconstructor
    game();
    ~game();

    //bool for window status
    const bool getWindowStatus() const; 

    //functions:
    void update();
    void render();
    void pollEvents();
};


