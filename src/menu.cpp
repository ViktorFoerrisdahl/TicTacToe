#include "menu.h"
#include <iostream>


//public functions:

startMenu::startMenu() {
    this->initFont();
    this->hitboxButton_ = buttonText_.getGlobalBounds();
}

//init font and check if it is loaded in correctly.
void startMenu::initFont() {
    if (!this->font_.loadFromFile("fonts/MirandaSans-VariableFont_wght.ttf")) {
        std::cout << "Font not loaded";
    } else {
        std::cout << "Font loaded corretly";
    }
}

sf::FloatRect startMenu::getButtonHitbox() {
    return this->hitboxButton_ = buttonText_.getGlobalBounds();
}

//init welcome text and return it drawing function
sf::Text startMenu::initWelcomeAndReturnIt() {

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

    // set the placement (middle)
    this->welcome_.setPosition(357.f, 150.f);

    return this->welcome_;
}

//init button text and return it:
sf::Text startMenu::initButtonTextAndReturnIt() {
    
        //set the font
    this->buttonText_.setFont(this->font_);

    // set the string to display
    this->buttonText_.setString("START");
    
    // set the character size
    this->buttonText_.setCharacterSize(55); // in pixels, not points!

    // set the color
    this->buttonText_.setFillColor(sf::Color::Red);

    // set the text style
    this->buttonText_.setStyle(sf::Text::Bold);

    // set the placement (middle)
    this->buttonText_.setPosition(510.f, 350.f);

    return this->buttonText_;
}