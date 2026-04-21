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

enum game_States {
    Menu, 
    Ingame, 
    GameOver
};


class game {
private:
    //varibles
        //window
    sf::RenderWindow* window_;
    sf::VideoMode VideoMode_;
    sf::Event window_event_;

    startMenu start_;

    board Board_;

    enum game_States state_;

    //private functions:
    void initVariables();
    void initWindow();
public:
    //varibles
    enum state_ {menu, ingame, game_Over};
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


