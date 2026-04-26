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
//text
sf::Text buttonText_;
//hitbox
sf::FloatRect hitboxButton_;

public:
 //constructor
startMenu();

void initFont();

sf::FloatRect getButtonHitbox();

sf::Text initWelcomeAndReturnIt();

sf::Text initButtonTextAndReturnIt();

};