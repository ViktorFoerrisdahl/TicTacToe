#include "board.h"

//public functions---------------

board::board() 
{
    this->initBoard();
    this->initBoardGrid();
    this->initBoardGridValues();
    this->initEmptyCircles();
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
        this->grid_[index].setFillColor(sf::Color::Blue);
    }
    
}

void board::placeCircle(int index)
{
    switch (index)
    {
    case 0:
        this->circles_[0].setPosition(10.f,10.f);
        this->circles_[0].setRadius(1000);
        this->circles_[0].setOutlineColor(sf::Color::Red);
        this->circles_[0].setOutlineThickness(10);
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
    //top left gridbox
    this->circles_[0].setPosition(12.5,10.f);
    this->circles_[0].setRadius(85);
    this->circles_[0].setOutlineColor(sf::Color::Red);
    this->circles_[0].setOutlineThickness(10);
    this->circles_[0].setFillColor(sf::Color::Black);

    //top middle gridbox
    this->circles_[1].setPosition(425.f,10.f);
    this->circles_[1].setRadius(95);
    this->circles_[1].setOutlineColor(sf::Color::Red);
    this->circles_[1].setOutlineThickness(10);
    this->circles_[1].setFillColor(sf::Color::Black);

    //top right gridbox
    this->circles_[2].setPosition(837.5,10.f);
    this->circles_[2].setRadius(65);
    this->circles_[2].setOutlineColor(sf::Color::Red);
    this->circles_[2].setOutlineThickness(10);
    this->circles_[2].setFillColor(sf::Color::Black);

    //middle left gridbox
    this->circles_[3].setPosition(12.5,292.f);
    this->circles_[3].setRadius(75);
    this->circles_[3].setOutlineColor(sf::Color::Red);
    this->circles_[3].setOutlineThickness(10);
    this->circles_[3].setFillColor(sf::Color::Black);

    //middle middle gridbox
    this->circles_[4].setPosition(425.f,292.f);
    this->circles_[4].setRadius(85);
    this->circles_[4].setOutlineColor(sf::Color::Red);
    this->circles_[4].setOutlineThickness(10);
    this->circles_[4].setFillColor(sf::Color::Black);

    //middle right gridbox
    this->circles_[5].setPosition(837.5,292.f);
    this->circles_[5].setRadius(75);
    this->circles_[5].setOutlineColor(sf::Color::Red);
    this->circles_[5].setOutlineThickness(10);
    this->circles_[5].setFillColor(sf::Color::Black);

    //bottom left gridbox
    this->circles_[6].setPosition(12.5,575.5);
    this->circles_[6].setRadius(100);
    this->circles_[6].setOutlineColor(sf::Color::Red);
    this->circles_[6].setOutlineThickness(10);
    this->circles_[6].setFillColor(sf::Color::Black);

    //bottom middle gridbox
    this->circles_[7].setPosition(425.f,575.5);
    this->circles_[7].setRadius(100);
    this->circles_[7].setOutlineColor(sf::Color::Red);
    this->circles_[7].setOutlineThickness(10);
    this->circles_[7].setFillColor(sf::Color::Black);

    //bottom right gridbox
    this->circles_[8].setPosition(837.5,575.5);
    this->circles_[8].setRadius(100);
    this->circles_[8].setOutlineColor(sf::Color::Red);
    this->circles_[8].setOutlineThickness(10);
    this->circles_[8].setFillColor(sf::Color::Black);
}
