#include <iostream>
#include "board.h"

//public functions---------------

board::board() 
{
    this->initBoard();
    this->initBoardGrid();
    this->initBoardGridValues();
    this->initEmptyCircles();
    this->initEmptyCrosses();
}

sf::RectangleShape board::boardInfo(int index) 
{
    return game_lines_[index];
}

sf::RectangleShape board::boardGrid(int index) 
{
    return grid_[index];
}

sf::CircleShape board::circleInfo(int index)
{
    return circles_[index];
}

sf::RectangleShape board::crossesInfo(int index)
{
    return crosses_[index];
}

sf::FloatRect board::getHitboxGrid(int index)
{
    return grid_[index].getGlobalBounds();
}

int board::getGridValue(int index) 
{
    return this->grid_values_[index];
}

void board::initBoardGridValues() 
{
    for (int i = 0; i < 9; i++) {
        this->grid_values_[i] = 0;
    }
}

void board::resetGridValueAndSymbol() 
{
    for (int i = 0; i < 9; i++)
        {
            this->initBoardGridValues();
            this->initBoardGrid();
            this->initEmptyCircles();
            this->initEmptyCrosses();
        }
}

void board::setGridValue(int index, int value) 
{
    this->grid_values_[index] = value;
}

void board::updateBoard(int index, int turn)
{
    if (turn == 7) {
        this->grid_values_[index] = 7;
        this->placeCircle(index);
    } else {
        this->grid_values_[index] = 10;
        this->placeCross(index);
    }
    
}

void board::placeCircle(int index)
{
   this->circles_[index].setOutlineColor(sf::Color::Red);
   switch (index)
   {
   case 0:
    //top left gridbox
    this->circles_[0].setPosition(82.5,25.f);
    break;

    case 1:
     //top middle gridbox
    this->circles_[1].setPosition(505.f,25.f);
    break;

    case 2:
     //top right gridbox
    this->circles_[2].setPosition(917.5,25.f);
    break;

    case 3:
    //middle left gridbox
    this->circles_[3].setPosition(82.5,304.5);
    break;

    case 4:
    //middle middle gridbox
    this->circles_[4].setPosition(505.f,304.5);
    break;

    case 5:
     //middle right gridbox
    this->circles_[5].setPosition(917.5,304.5);
    break;

    case 6:
    //bottom left gridbox
    this->circles_[6].setPosition(82.5,584.f);
    break;

    case 7:
    //bottom middle gridbox
    this->circles_[7].setPosition(505.f,584.f);
    break;

    case 8:
    //bottom right gridbox
    this->circles_[8].setPosition(917.5,584.f);
    break;

   default:
    std::cout << "reached default at placeCircle function" << std::endl;
    break;
   }
}

void board::placeCross(int index) 
{
    switch (index)
    {
    case 0:
        this->crosses_[0].setOutlineColor(sf::Color::Blue);
        this->crosses_[0 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 1:
        this->crosses_[2].setOutlineColor(sf::Color::Blue);
        this->crosses_[2 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 2:
        this->crosses_[4].setOutlineColor(sf::Color::Blue);
        this->crosses_[4 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 3:
        this->crosses_[6].setOutlineColor(sf::Color::Blue);
        this->crosses_[6 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 4:
        this->crosses_[8].setOutlineColor(sf::Color::Blue);
        this->crosses_[8 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 5:
        this->crosses_[10].setOutlineColor(sf::Color::Blue);
        this->crosses_[10 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 6:
        this->crosses_[12].setOutlineColor(sf::Color::Blue);
        this->crosses_[12 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 7:
        this->crosses_[14].setOutlineColor(sf::Color::Blue);
        this->crosses_[14 + 1].setOutlineColor(sf::Color::Blue);
        break;
    case 8:
        this->crosses_[16].setOutlineColor(sf::Color::Blue);
        this->crosses_[16 + 1].setOutlineColor(sf::Color::Blue);
        break;
    default:
        break;
    }

}

void board::initBoard()
{
    //make all sqaures white:
    for (auto i = 0; i < 4; i++)
    {
        this->game_lines_[i].setFillColor(sf::Color::White);
        if (i < 2)
        {
            this->game_lines_[i].setOrigin(sf::Vector2f(25.f,0.f));
            this->game_lines_[i].setSize(sf::Vector2f(50.f,800.f));
        }
        else 
        {
            this->game_lines_[i].setOrigin(sf::Vector2f(0.f,25.f));
            this->game_lines_[i].setSize(sf::Vector2f(1200.f,50.f));
        }
    }
    //Left vertical line
    this->game_lines_[0].setPosition(400.f,0.f);

    //Right vertical line
    this->game_lines_[1].setPosition(800.f,0.f);

    //Upper horizontal line
    this->game_lines_[2].setPosition(0.f,266.f);

    //Lower horizontal line
    this->game_lines_[3].setPosition(0.f,532.f);
}

void board::initBoardGrid() {
    //init everything but position
    for (auto i = 0; i < 9; i++)
    {
        this->grid_[i].setOrigin(sf::Vector2f(175.f,0.f));
        this->grid_[i].setSize(sf::Vector2f(350.f,215.f));
        this->grid_[i].setFillColor(sf::Color::Black);
    }

    //top left gridbox
    this->grid_[0].setPosition(187.5,10.f);

    //top middle gridbox
    this->grid_[1].setPosition(600.f,10.f);

    //top right gridbox
    this->grid_[2].setPosition(1012.5,10.f);

    //middle left gridbox
    this->grid_[3].setPosition(187.5,292.f);

    //middle middle gridbox
    this->grid_[4].setPosition(600.f,292.f);

    //middle right gridbox
    this->grid_[5].setPosition(1012.5,292.f);

    //bottom left gridbox
    this->grid_[6].setPosition(187.5,572.5);

    //bottom middle gridbox
    this->grid_[7].setPosition(600.f,572.5);

    //bottom right gridbox
    this->grid_[8].setPosition(1012.5,572.5);
}

void board::initEmptyCircles()
{
    for (int i = 0; i < 9; i++) {
        this->circles_[i].setPosition(1200.f,800.f);
        this->circles_[i].setRadius(95);
        this->circles_[i].setOutlineColor(sf::Color::Black);
        this->circles_[i].setOutlineThickness(10);
        this->circles_[i].setFillColor(sf::Color::Black);
    }
}

void board::initEmptyCrosses() 
{
    //init everything but position
    for (auto i = 0; i < 18; i++)
    {
        this->crosses_[i].setOutlineColor(sf::Color::Black);
        this->crosses_[i].setOutlineThickness(10);
        this->crosses_[i].setFillColor(sf::Color::Black);
        this->crosses_[i].setSize(sf::Vector2f(0.f,250.f));
        if (i % 2 == 0) 
        {
            this->crosses_[i].setRotation(45.f);
        }
        else 
        {
            this->crosses_[i].setRotation(-45.f);
        }
    }

    //top left gridbox
    this->crosses_[0].setPosition(277.5,31.f);
    this->crosses_[1].setPosition(100.f,31.f);

    //top middle gridbox
    this->crosses_[2].setPosition(687.5,31.f);
    this->crosses_[3].setPosition(510.f,31.f);

    //top right gridbox
    this->crosses_[4].setPosition(1100,31.f);
    this->crosses_[5].setPosition(922.5,31.f);

    //middle left gridbox
    this->crosses_[6].setPosition(277.5,310.f);
    this->crosses_[7].setPosition(100.f,310.f);

    //middle middle gridbox
    this->crosses_[8].setPosition(687.5,310.f);
    this->crosses_[9].setPosition(510.f,310.f);

    //middle right gridbox
    this->crosses_[10].setPosition(1100.f,310.f);
    this->crosses_[11].setPosition(922.5,310.f);

    //bottom left gridbox
    this->crosses_[12].setPosition(277.5,590.f);
    this->crosses_[13].setPosition(100.f,590.f);

    //bottom middle gridbox
    this->crosses_[14].setPosition(687.5,590.f);
    this->crosses_[15].setPosition(510.f,590.f);

    //bottom right gridbox
    this->crosses_[16].setPosition(1100.f,590.f);
    this->crosses_[17].setPosition(922.5,590.f);
}