#pragma once

#include "board.h"
#include "menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

class startMenu;
class board;

class game {
private:
    //varibles
        //window
    sf::RenderWindow* window_;
    sf::VideoMode VideoMode_;
    sf::Event window_event_;

    startMenu start_;

    board Board_;

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


