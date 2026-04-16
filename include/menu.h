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

sf::Text welcome_;

public:

void initFont();

sf::Text initWelcome();

};