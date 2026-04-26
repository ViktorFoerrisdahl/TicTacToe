#pragma once

#include "board.h"
#include "menu.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>

class board;

enum game_States {
    Menu, 
    Ingame, 
    GameOver
};

class startMenu;

class game {
private:
    //varibles
        //window
    sf::RenderWindow* window_;
    sf::VideoMode VideoMode_;
    sf::Event window_event_;

    startMenu startMenu_;

    board Board_;

    enum game_States state_;

    //private functions:
    void initVariables();
    void initWindow();
public:
    //varibles
    
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    
    //constructor / deconstructor
    game();
    ~game();

    //bool for window status
    const bool getWindowStatus() const; 


    //functions:
    void updateMousePos();
    void update();
    void render();
    void pollEvents();
};


