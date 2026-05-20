#include "menu.h"
#include <iostream>


//public functions:

startMenu::startMenu() {
    this->initFont();
    this->hitboxButton_ = buttonText_.getGlobalBounds();
    this->restartBottonTextHitbox_ = restartBottonText_.getGlobalBounds();
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

sf::FloatRect startMenu::getRestartBottonHitbox() {
    return this->restartBottonTextHitbox_ = restartBottonText_.getGlobalBounds(); 
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

    //set outline
    this->welcome_.setOutlineColor(sf::Color::Red);

    //set outline size
    this->welcome_.setOutlineThickness(1.f);

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

    //set outline
    this->buttonText_.setOutlineColor(sf::Color::Blue);

    //set outline size
    this->buttonText_.setOutlineThickness(1.f);

    return this->buttonText_;
}

//init gameover text and return it drawing function
sf::Text startMenu::initGameoverTextAndReturnIt() {

    //set the font
    this->gameOverText_.setFont(this->font_);

    // set the string to display
    this->gameOverText_.setString("GAME OVER!");
    
    // set the character size
    this->gameOverText_.setCharacterSize(90); // in pixels, not points!

    // set the color
    this->gameOverText_.setFillColor(sf::Color::Blue);

    // set the text style
    this->gameOverText_.setStyle(sf::Text::Bold);

    // set the placement (middle)
    this->gameOverText_.setPosition(325.f, 100.f);

    // //set outline
    // this->gameOverText_.setOutlineColor(sf::Color::Red);

    // //set outline size
    // this->gameOverText_.setOutlineThickness(1.f);

    return this->gameOverText_;
}

//init button text and return it:
sf::Text startMenu::initRestartBottonTextAndReturnIt() {
    
        //set the font
    this->restartBottonText_.setFont(this->font_);

    // set the string to display
    this->restartBottonText_.setString("RESTART");
    
    // set the character size
    this->restartBottonText_.setCharacterSize(55); // in pixels, not points!

    // set the color
    this->restartBottonText_.setFillColor(sf::Color::Red);

    // set the text style
    this->restartBottonText_.setStyle(sf::Text::Bold);

    // set the placement (middle)
    this->restartBottonText_.setPosition(460.f, 650.f);

    //set outline
    this->restartBottonText_.setOutlineColor(sf::Color::Blue);

    //set outline size
    this->restartBottonText_.setOutlineThickness(1.f);

    return this->restartBottonText_;
}

//init winner text and return it:
sf::Text startMenu::initWinnerDisplayTextAndReturnIt(bool x) 
{
    if (x) 
    {
    //set the font
    this->winnerDisplayText_.setFont(this->font_);

    // set the string to display
    this->winnerDisplayText_.setString("X WINS!");
    
    // set the character size
    this->winnerDisplayText_.setCharacterSize(75); // in pixels, not points!

    // set the color
    this->winnerDisplayText_.setFillColor(sf::Color::Red);

    // set the text style
    this->winnerDisplayText_.setStyle(sf::Text::Bold);

    // set the placement (middle)
    this->winnerDisplayText_.setPosition(460.f, 250.f);

    //set outline
    this->winnerDisplayText_.setOutlineColor(sf::Color::Blue);

    //set outline size
    this->winnerDisplayText_.setOutlineThickness(1.f);

    return this->winnerDisplayText_;
    }
    else 
    {
    //set the font
    this->winnerDisplayText_.setFont(this->font_);

    // set the string to display
    this->winnerDisplayText_.setString("O WINS!");
    
    // set the character size
    this->winnerDisplayText_.setCharacterSize(75); // in pixels, not points!

    // set the color
    this->winnerDisplayText_.setFillColor(sf::Color::Blue);

    // set the text style
    this->winnerDisplayText_.setStyle(sf::Text::Bold);

    // set the placement (middle)
    this->winnerDisplayText_.setPosition(452.f, 250.f);

    //set outline
    this->winnerDisplayText_.setOutlineColor(sf::Color::Red);

    //set outline size
    this->winnerDisplayText_.setOutlineThickness(1.f);

    return this->winnerDisplayText_;
    }
}