#include "board.h"


//public functions---------------

board::board() {
    this->initBoard();
}

board::~board() {
    
}

sf::RectangleShape board::boardInfo(int index) {
    return lines_[index];
}

void board::initBoard() {
    //Left vertical line
    this->lines_[0].setPosition(375.f,0.f);
    this->lines_[0].setSize(sf::Vector2f(50.f,800.f));
    this->lines_[0].setFillColor(sf::Color::White);

    //Right vertical line
    this->lines_[1].setPosition(775.f,0.f);
    this->lines_[1].setSize(sf::Vector2f(50.f,800.f));
    this->lines_[1].setFillColor(sf::Color::White);

    //Upper horizontal line
    this->lines_[2].setPosition(0.f,241.f);
    this->lines_[2].setSize(sf::Vector2f(1200.f,50.f));
    this->lines_[2].setFillColor(sf::Color::White);

    //Lower horizontal line
    this->lines_[3].setPosition(0.f,508.f);
    this->lines_[3].setSize(sf::Vector2f(1200.f,50.f));
    this->lines_[3].setFillColor(sf::Color::White);
}
