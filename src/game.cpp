#include "game.h"
#include "board.h"
#include "menu.h"

//private functions---------

void game::initVariables() {
    this->window_ = nullptr;
    this->state_ = Menu;
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
    this->Board_.initBoard();
    this->start_.initFont();
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

    //Switch to control the state of the game
    switch (this->state_) {
    case Menu:
        //add startMenu
        this->window_->draw(start_.initWelcome());
        break;
    
    case Ingame:
        //add to the new frame:
        for (int i = 0; i < 4; i++) {
            this->window_->draw(Board_.boardInfo(i));
            }
        break;
    
    case GameOver:
        break;

    default:
    std::cout << "Went to default mode";
    }

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
