#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>

class board 
{
private:
    //varibles
    sf::RectangleShape lines_[4];
    //int grid[3][3];

public:
    //constructor / deconstructor
    board();
    ~board();

    //functions:
    void updateBoard();
    void initBoard();
    sf::RectangleShape boardInfo(int index);
};

