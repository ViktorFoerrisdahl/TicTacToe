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
//text
sf::Text gameOverText_;

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

sf::FloatRect getRestartBottonHitbox();

sf::Text initRestartBottonTextAndReturnIt();

sf::Text initGameoverTextAndReturnIt();

};