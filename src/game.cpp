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
    this->startMenu_.getButtonHitbox();
}

game::~game() {
    delete this->window_;
}

const bool game::getWindowStatus() const {
    return this->window_->isOpen();
}

void game::updateMousePos() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window_);
    this->mousePosView = this->window_->mapPixelToCoords(this->mousePosWindow);
}

void game::update() {
    this->updateMousePos();
    this->pollEvents();
}

void game::render() {
    //clears the old frame:
    this->window_->clear();

    //Switch to control the state of the game
    switch (this->state_) {
    case Menu:
        //add startMenu
        this->window_->draw(startMenu_.initWelcomeAndReturnIt());

        //function to get position to use for measurements:
        std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;
        
        //draw start button
        this->window_->draw(startMenu_.initButtonTextAndReturnIt());
        break;
    
    case Ingame:
        //add to the new frame:
        for (int i = 0; i < 4; i++) {
            this->window_->draw(Board_.boardInfo(i));
            }
            
        //function to get position to use for measurements:
        std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;

        break;
    
    case GameOver:
        break;

    default:
    std::cout << "Went to default in switch case";
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
                default:
                break;
            }

            //checks if mouse button is pressed on the start text
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if ((startMenu_.getButtonHitbox()).contains(this->mousePosView) && this->state_ == Menu) {
                        this->state_ = Ingame;
            }
             
        }
    }
}