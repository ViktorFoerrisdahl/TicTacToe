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
    int grid_values_[9];

public:
    //constructor
    board();

    //functions:
    void updateBoard(int index, int turn);
    void initBoard();
    void initBoardGrid();
    void initBoardGridValues();
    void setGridValue(int index, int value);
    sf::RectangleShape boardInfo(int index);
    sf::RectangleShape boardGrid(int index);
    sf::FloatRect getHitboxGrid(int index);
    int getGridValue(int index);

};

