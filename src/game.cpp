#include "game.h"
#include "board.h"
#include "menu.h"

//private functions---------

void game::initVariables() {
    this->window_ = nullptr;
    this->state_ = Menu;
    this->turn_ = X;
}

void game::initWindow() {
    this->VideoMode_.width = 1200;
    this->VideoMode_.height = 800;
    this->window_ = new sf::RenderWindow(sf::VideoMode(this->VideoMode_), "Tic tac toe", sf::Style::Titlebar | sf::Style::Close);
    this->window_->setFramerateLimit(60);   
}

//public functions---------------
game::game()
{
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

void game::switchTurn()
{
    if (this->turn_ == X) 
    {
        this->turn_ = O;
    } 
    else 
    {
        this->turn_ = X;
    }
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

        //////////////////////////////////////////////
        //REMOVE WHEN GAME IS DONE
        //function to get position to use for measurements:
        //std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;
        //////////////////////////////////////////////

        //draw start button
        this->window_->draw(startMenu_.initButtonTextAndReturnIt());
        break;
    
    case Ingame:
        //add to the new frame:
        for (int i = 0; i < 4; i++) {
            this->window_->draw(Board_.boardInfo(i));
            }

        //display grid
        for (int i = 0; i < 9; i++) {
            this->window_->draw(Board_.boardGrid(i));
        }

        //////////////////////////////////////////////
        //REMOVE WHEN GAME IS DONE
        //function to get position to use for measurements:
        //std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;
        //////////////////////////////////////////////

        break;
    
    case GameOver:
        //add gameover menu
        this->window_->draw(startMenu_.initGameoverTextAndReturnIt());

        //draw start button
        this->window_->draw(startMenu_.initRestartBottonTextAndReturnIt());
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
            //Switch case to handle window events
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

            //for - if statements to handle grid presses and switch turn
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->state_ == Ingame) 
            {
                for (int i = 0; i < 9; i ++) 
                {
                    if (Board_.getHitboxGrid(i).contains(this->mousePosView))
                    {
                        Board_.updateBoard(i, this->turn_);
                        switchTurn();
                        for (int i = 0; i < 100000000; i++) {
                            //delay
                        }
                    }
                }
            }

            //checks if mouse button is pressed on the start text
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                if ((startMenu_.getButtonHitbox()).contains(this->mousePosView) && this->state_ == Menu) 
                {
                        this->state_ = Ingame;
                        for (int i = 0; i < 100000000; i++) {
                            //delay
                        }
                }
            }

            //Game logic if statement:
            if (this->state_ == Ingame) 
            {
                int temp{};
                //check if we have a winner in the top horizontial line
                for (int i = 0; i < 3; i++) 
                {
                    temp += Board_.getGridValue(i);
                }
                if (temp == 21 || temp == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp1{};
                //check if we have a winner in the middle horizontial line
                for (int i = 3; i < 6; i++) 
                {
                    temp1 += Board_.getGridValue(i);
                }
                if (temp1 == 21 || temp1 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp2{};
                //check if we have a winner in the bottom horizontial line
                for (int i = 6; i < 9; i++) 
                {
                    temp2 += Board_.getGridValue(i);
                }
                if (temp2 == 21 || temp2 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp3{};
                //check if we have a winner left vertical line
                for (int i = 0; i < 7; i++) 
                {
                    temp3 += Board_.getGridValue(i);
                    i++;
                    i++;
                }
                if (temp3 == 21 || temp3 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp4{};
                //check if we have a winner middle vertical line
                for (int i = 1; i < 8; i++) 
                {
                    temp4 += Board_.getGridValue(i);
                    i++;
                    i++;
                }
                if (temp4 == 21 || temp4 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp5{};
                //check if we have a winner right vertical line
                for (int i = 2; i < 9; i++) 
                {
                    temp5 += Board_.getGridValue(i);
                    i++;
                    i++;
                }
                if (temp5 == 21 || temp5 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp6{};
                //check if we have a winner from left top to right bottom
                for (int i = 0; i < 9; i++) 
                {
                    temp6 += Board_.getGridValue(i);
                    i++;
                    i++;
                    i++;
                }
                if (temp6 == 21 || temp6 == 30) 
                {
                    this->state_ = GameOver;
                }

                int temp7{};
                //check if we have a winner from right top to left bottom
                for (int i = 2; i < 7; i++) 
                {
                    temp7 += Board_.getGridValue(i);
                    i++;
                }
                if (temp7 == 21 || temp7 == 30) 
                {
                    this->state_ = GameOver;
                }
            }
         }
}