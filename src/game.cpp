#include "game.h"

//private functions---------

void game::initVariables() {
    this->window_ = nullptr;
}

void game::initWindow() {
    this->VideoMode_.width = 1200;
    this->VideoMode_.height = 800;
    this->window_ = new sf::RenderWindow(sf::VideoMode(this->VideoMode_), "Tic tac toe", sf::Style::Titlebar | sf::Style::Close);
    this->window_->setFramerateLimit(60);   
}

//public functions---------------

game::game() {
    this->initVariables();
    this->initWindow();
}

game::~game() {
    delete this->window_;
}

const bool game::getWindowStatus() const {
    return this->window_->isOpen();
}

void game::update() {
    this->pollEvents();
}

void game::render() {
    //clears the old frame:
    this->window_->clear();
    //add to the new frame:

    //display new frame:
    this->window_->display();
}

void game::pollEvents() {
    
    while (this->window_->pollEvent(this->window_event_))
        {
            switch (this->window_event_.type)
            {
                case sf::Event::Closed:
                    this->window_->close();
                    break;
                case sf::Event::KeyPressed:
                    if (this->window_event_.key.code == sf::Keyboard::Escape) {
                        this->window_->close();
                        break;
                    }
             }
        }
}