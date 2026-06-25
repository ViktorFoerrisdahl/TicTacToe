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
    sf::CircleShape circles_[9];
    sf::RectangleShape crosses_[18];
    int grid_values_[9];

public:
    //constructor
    board();

    //functions:
    //Update and init board:
    void updateBoard(int index, int turn);
    void initBoard();
    void initBoardGrid();
    void initBoardGridValues();
    void initEmptyCircles();
    void initEmptyCrosses();
    sf::RectangleShape boardInfo(int index);
    sf::RectangleShape boardGrid(int index);
    int getGridValue(int index);
    sf::FloatRect getHitboxGrid(int index);

    //game logic functions
    void setGridValue(int index, int value);
    void resetGridValueAndSymbol();

    //cicle functions
    void placeCircle(int index);
    sf::CircleShape circleInfo(int index);

    //crosses functions
    void placeCross(int index);
    sf::RectangleShape crossesInfo(int index);

};

