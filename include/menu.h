#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class startMenu
{
private:
//varibles

//Font:
sf::Font font_;

//Welcome text
sf::Text welcome_;

//startMenu bottons
//button
//text
sf::Text buttonText_;
//hitbox
sf::FloatRect hitboxButton_;

//Gameover 
//Gameover Text
sf::Text gameOverText_;

//Gameover Text
sf::Text winnerDisplayText_;

//button
//text
sf::Text restartBottonText_;
//hitbox
sf::FloatRect restartBottonTextHitbox_;




public:
 //constructor
startMenu();

//init font
void initFont();

//start menu

sf::FloatRect getButtonHitbox();

sf::Text initWelcomeAndReturnIt();

sf::Text initButtonTextAndReturnIt();

//game over menu
//restart text and button
sf::FloatRect getRestartBottonHitbox();
sf::Text initRestartBottonTextAndReturnIt();
//game over text
sf::Text initGameoverTextAndReturnIt();
//winner text
sf::Text initWinnerDisplayTextAndReturnIt(bool x);


};