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

//button
sf::Text buttonText_;


public:
 //constructor
startMenu();

void initFont();

sf::Text initWelcomeAndReturnIt();

sf::Text initButtonTextAndReturnIt();

};