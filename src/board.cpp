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
    //Left vertical line
    this->game_lines_[0].setOrigin(sf::Vector2f(25.f,0.f));
    this->game_lines_[0].setPosition(400.f,0.f);
    this->game_lines_[0].setSize(sf::Vector2f(50.f,800.f));
    this->game_lines_[0].setFillColor(sf::Color::White);

    //Right vertical line
    this->game_lines_[1].setOrigin(sf::Vector2f(25.f,0.f));
    this->game_lines_[1].setPosition(800.f,0.f);
    this->game_lines_[1].setSize(sf::Vector2f(50.f,800.f));
    this->game_lines_[1].setFillColor(sf::Color::White);

    //Upper horizontal line
    this->game_lines_[2].setOrigin(sf::Vector2f(0.f,25.f));
    this->game_lines_[2].setPosition(0.f,266.f);
    this->game_lines_[2].setSize(sf::Vector2f(1200.f,50.f));
    this->game_lines_[2].setFillColor(sf::Color::White);

    //Lower horizontal line
    this->game_lines_[3].setOrigin(sf::Vector2f(0.f,25.f));
    this->game_lines_[3].setPosition(0.f,532.f);
    this->game_lines_[3].setSize(sf::Vector2f(1200.f,50.f));
    this->game_lines_[3].setFillColor(sf::Color::White);
}

void board::initBoardGrid() {
    //top left gridbox
    this->grid_[0].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[0].setPosition(187.5,10.f);
    this->grid_[0].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[0].setFillColor(sf::Color::Black);

    //top middle gridbox
    this->grid_[1].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[1].setPosition(600.f,10.f);
    this->grid_[1].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[1].setFillColor(sf::Color::Black);

    //top right gridbox
    this->grid_[2].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[2].setPosition(1012.5,10.f);
    this->grid_[2].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[2].setFillColor(sf::Color::Black);

    //middle left gridbox
    this->grid_[3].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[3].setPosition(187.5,292.f);
    this->grid_[3].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[3].setFillColor(sf::Color::Black);

    //middle middle gridbox
    this->grid_[4].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[4].setPosition(600.f,292.f);
    this->grid_[4].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[4].setFillColor(sf::Color::Black);

    //middle right gridbox
    this->grid_[5].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[5].setPosition(1012.5,292.f);
    this->grid_[5].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[5].setFillColor(sf::Color::Black);

    //bottom left gridbox
    this->grid_[6].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[6].setPosition(187.5,572.5);
    this->grid_[6].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[6].setFillColor(sf::Color::Black);

    //bottom middle gridbox
    this->grid_[7].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[7].setPosition(600.f,572.5);
    this->grid_[7].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[7].setFillColor(sf::Color::Black);

    //bottom right gridbox
    this->grid_[8].setOrigin(sf::Vector2f(175.f,0.f));
    this->grid_[8].setPosition(1012.5,572.5);
    this->grid_[8].setSize(sf::Vector2f(350.f,215.f));
    this->grid_[8].setFillColor(sf::Color::Black);

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
     //top left gridbox
    this->crosses_[0].setPosition(277.5,31.f);
    this->crosses_[0].setOutlineColor(sf::Color::Black);
    this->crosses_[0].setOutlineThickness(10);
    this->crosses_[0].setFillColor(sf::Color::Black);
    this->crosses_[0].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[0].setRotation(45.f);
    
    this->crosses_[1].setPosition(100.f,31.f);
    this->crosses_[1].setOutlineColor(sf::Color::Black);
    this->crosses_[1].setOutlineThickness(10);
    this->crosses_[1].setFillColor(sf::Color::Black);
    this->crosses_[1].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[1].setRotation(-45.f);

    //top middle gridbox
    this->crosses_[2].setPosition(687.5,31.f);
    this->crosses_[2].setOutlineColor(sf::Color::Black);
    this->crosses_[2].setOutlineThickness(10);
    this->crosses_[2].setFillColor(sf::Color::Black);
    this->crosses_[2].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[2].setRotation(45.f);
    
    this->crosses_[3].setPosition(510.f,31.f);
    this->crosses_[3].setOutlineColor(sf::Color::Black);
    this->crosses_[3].setOutlineThickness(10);
    this->crosses_[3].setFillColor(sf::Color::Black);
    this->crosses_[3].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[3].setRotation(-45.f);

    //top right gridbox
    this->crosses_[4].setPosition(1100,31.f);
    this->crosses_[4].setOutlineColor(sf::Color::Black);
    this->crosses_[4].setOutlineThickness(10);
    this->crosses_[4].setFillColor(sf::Color::Black);
    this->crosses_[4].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[4].setRotation(45.f);
    
    this->crosses_[5].setPosition(922.5,31.f);
    this->crosses_[5].setOutlineColor(sf::Color::Black);
    this->crosses_[5].setOutlineThickness(10);
    this->crosses_[5].setFillColor(sf::Color::Black);
    this->crosses_[5].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[5].setRotation(-45.f);

    //middle left gridbox
    this->crosses_[6].setPosition(277.5,310.f);
    this->crosses_[6].setOutlineColor(sf::Color::Black);
    this->crosses_[6].setOutlineThickness(10);
    this->crosses_[6].setFillColor(sf::Color::Black);
    this->crosses_[6].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[6].setRotation(45.f);

    this->crosses_[7].setPosition(100.f,310.f);
    this->crosses_[7].setOutlineColor(sf::Color::Black);
    this->crosses_[7].setOutlineThickness(10);
    this->crosses_[7].setFillColor(sf::Color::Black);
    this->crosses_[7].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[7].setRotation(-45.f);

    //middle middle gridbox
    this->crosses_[8].setPosition(687.5,310.f);
    this->crosses_[8].setOutlineColor(sf::Color::Black);
    this->crosses_[8].setOutlineThickness(10);
    this->crosses_[8].setFillColor(sf::Color::Black);
    this->crosses_[8].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[8].setRotation(45.f);

    this->crosses_[9].setPosition(510.f,310.f);
    this->crosses_[9].setOutlineColor(sf::Color::Black);
    this->crosses_[9].setOutlineThickness(10);
    this->crosses_[9].setFillColor(sf::Color::Black);
    this->crosses_[9].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[9].setRotation(-45.f);

    //middle right gridbox
    this->crosses_[10].setPosition(1100.f,310.f);
    this->crosses_[10].setOutlineColor(sf::Color::Black);
    this->crosses_[10].setOutlineThickness(10);
    this->crosses_[10].setFillColor(sf::Color::Black);
    this->crosses_[10].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[10].setRotation(45.f);

    this->crosses_[11].setPosition(922.5,310.f);
    this->crosses_[11].setOutlineColor(sf::Color::Black);
    this->crosses_[11].setOutlineThickness(10);
    this->crosses_[11].setFillColor(sf::Color::Black);
    this->crosses_[11].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[11].setRotation(-45.f);

    //bottom left gridbox
    this->crosses_[12].setPosition(277.5,590.f);
    this->crosses_[12].setOutlineColor(sf::Color::Black);
    this->crosses_[12].setOutlineThickness(10);
    this->crosses_[12].setFillColor(sf::Color::Black);
    this->crosses_[12].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[12].setRotation(45.f);

    this->crosses_[13].setPosition(100.f,590.f);
    this->crosses_[13].setOutlineColor(sf::Color::Black);
    this->crosses_[13].setOutlineThickness(10);
    this->crosses_[13].setFillColor(sf::Color::Black);
    this->crosses_[13].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[13].setRotation(-45.f);

    //bottom middle gridbox
    this->crosses_[14].setPosition(687.5,590.f);
    this->crosses_[14].setOutlineColor(sf::Color::Black);
    this->crosses_[14].setOutlineThickness(10);
    this->crosses_[14].setFillColor(sf::Color::Black);
    this->crosses_[14].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[14].setRotation(45.f);

    this->crosses_[15].setPosition(510.f,590.f);
    this->crosses_[15].setOutlineColor(sf::Color::Black);
    this->crosses_[15].setOutlineThickness(10);
    this->crosses_[15].setFillColor(sf::Color::Black);
    this->crosses_[15].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[15].setRotation(-45.f);

    //bottom right gridbox
    this->crosses_[16].setPosition(1100.f,590.f);
    this->crosses_[16].setOutlineColor(sf::Color::Black);
    this->crosses_[16].setOutlineThickness(10);
    this->crosses_[16].setFillColor(sf::Color::Black);
    this->crosses_[16].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[16].setRotation(45.f);

    this->crosses_[17].setPosition(922.5,590.f);
    this->crosses_[17].setOutlineColor(sf::Color::Black);
    this->crosses_[17].setOutlineThickness(10);
    this->crosses_[17].setFillColor(sf::Color::Black);
    this->crosses_[17].setSize(sf::Vector2f(0.f,250.f));
    this->crosses_[17].setRotation(-45.f);
}