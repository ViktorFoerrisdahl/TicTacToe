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

enum Turn {
    X = 10,
    O = 7,
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

    enum Turn turn_;

    bool crossWins_;

    bool gameIsATie_;

    int numberOfTurns;

    int winningCombinations_[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6},
    };

    //private functions:
    void initVariables();
    void initWindow();
public:
    //varibles
    
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    bool isCrossWinner();
    
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
    void switchTurn();
    void delay(int x);
};


