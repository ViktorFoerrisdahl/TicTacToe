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
    this->lines_[0].setPosition(600.f,0.f);
    this->lines_[0].setSize(sf::Vector2f(30.f,600.f));
    this->lines_[0].setFillColor(sf::Color::White);

    this->lines_[1].setPosition(60.f,0.f);
    this->lines_[1].setSize(sf::Vector2f(30.f,600.f));
    this->lines_[1].setFillColor(sf::Color::White);

    this->lines_[2].setPosition(60.f,600.f);
    this->lines_[2].setSize(sf::Vector2f(600.f,30.f));
    this->lines_[2].setFillColor(sf::Color::White);

    this->lines_[3].setPosition(600.f,60.f);
    this->lines_[3].setSize(sf::Vector2f(600.f,30.f));
    this->lines_[3].setFillColor(sf::Color::White);
}
