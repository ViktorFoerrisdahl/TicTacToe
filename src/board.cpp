#include "board.h"


//public functions---------------

board::board() {
    this->initBoard();
}


sf::RectangleShape board::boardInfo(int index) {
    return game_lines_[index];
}

void board::initBoard() {
    //Left vertical line
    this->game_lines_[0].setPosition(375.f,0.f);
    this->game_lines_[0].setSize(sf::Vector2f(50.f,800.f));
    this->game_lines_[0].setFillColor(sf::Color::White);

    //Right vertical line
    this->game_lines_[1].setPosition(775.f,0.f);
    this->game_lines_[1].setSize(sf::Vector2f(50.f,800.f));
    this->game_lines_[1].setFillColor(sf::Color::White);

    //Upper horizontal line
    this->game_lines_[2].setPosition(0.f,241.f);
    this->game_lines_[2].setSize(sf::Vector2f(1200.f,50.f));
    this->game_lines_[2].setFillColor(sf::Color::White);

    //Lower horizontal line
    this->game_lines_[3].setPosition(0.f,508.f);
    this->game_lines_[3].setSize(sf::Vector2f(1200.f,50.f));
    this->game_lines_[3].setFillColor(sf::Color::White);
}
