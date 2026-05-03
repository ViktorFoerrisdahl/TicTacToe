#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>

class board 
{
private:
    //varibles
    sf::RectangleShape game_lines_[4];
    sf::RectangleShape grid_[9];
    //int grid[3][3];

public:
    //constructor
    board();

    //functions:
    void updateBoard();
    void initBoard();
    void initBoardGrid();
    sf::RectangleShape boardInfo(int index);
    sf::RectangleShape boardGrid(int index);
};

