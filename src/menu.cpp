#include "menu.h"
#include <iostream>


//public functions:
//init font and check if it is loaded in correctly.
void startMenu::initFont() {
    if (!this->font_.loadFromFile("fonts/MirandaSans-VariableFont_wght.ttf")) {
        std::cout << "Font not loaded";
    } else {
        std::cout << "Font loaded corretly";
    }
}

//init welcome text:
sf::Text startMenu::initWelcome() {

    //set the font
    this->welcome_.setFont(this->font_);

    // set the string to display
    this->welcome_.setString("Tic Tac Toe");
    
    // set the character size
    this->welcome_.setCharacterSize(90); // in pixels, not points!

    // set the color
    this->welcome_.setFillColor(sf::Color::Blue);

    // set the text style
    this->welcome_.setStyle(sf::Text::Bold);

    return this->welcome_;
}