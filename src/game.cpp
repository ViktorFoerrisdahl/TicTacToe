#include "game.h"
#include "board.h"
#include "menu.h"

//private functions---------

void game::initVariables() 
{
    this->window_ = nullptr;
    this->state_ = Menu;
    this->turn_ = X;
    this->crossWins_ = false;
    this->numberOfTurns = 0;
    this->gameIsATie_ = false;
}

void game::initWindow() 
{
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

game::~game() 
{
    delete this->window_;
}

const bool game::getWindowStatus() const 
{
    return this->window_->isOpen();
}

bool game::isCrossWinner() 
{
    return this->crossWins_;
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


void game::updateMousePos() 
{
    this->mousePosWindow = sf::Mouse::getPosition(*this->window_);
    this->mousePosView = this->window_->mapPixelToCoords(this->mousePosWindow);
}

void game::update() 
{
    this->updateMousePos();
    this->pollEvents();
}

void game::render() 
{
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
        for (int i = 0; i < 4; i++) 
        {
            this->window_->draw(Board_.boardInfo(i));
        }

        //display grid
        for (int i = 0; i < 9; i++) 
        {
            //draw grid (black boxes)
            this->window_->draw(Board_.boardGrid(i));
        }

        //display crosses
        for (int i = 0; i < 18; i++)
        {
            //draw crosses if they are placed
            this->window_->draw(Board_.crossesInfo(i));
        }

        //display circles
        for (int i = 0; i < 9; i++) 
        {
            //draw circles if they are placed
            this->window_->draw(Board_.circleInfo(i));
        }

        //////////////////////////////////////////////
        //REMOVE WHEN GAME IS DONE
        //function to get position to use for measurements:
        // std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;
        //////////////////////////////////////////////

        break;
    
    case GameOver:
        //add gameover menu
        this->window_->draw(startMenu_.initGameoverTextAndReturnIt());

        if (gameIsATie_) 
        {
            this->window_->draw(startMenu_.initTieDisplayTextAndReturnIt());
        }
        else 
        {
            //draw winner text
            this->window_->draw(startMenu_.initWinnerDisplayTextAndReturnIt(isCrossWinner()));
        }
        

        //draw restart button
        this->window_->draw(startMenu_.initRestartBottonTextAndReturnIt());

        //////////////////////////////////////////////
        //REMOVE WHEN GAME IS DONE
        // function to get position to use for measurements:
        // std::cout << "x: " << sf::Mouse::getPosition(*this->window_).x << "y: " << sf::Mouse::getPosition(*this->window_).y << std::endl;
        //////////////////////////////////////////////

        break;

    default:
    std::cout << "Went to default in switch case";
    }

 //display new frame:
    this->window_->display();
}

void game::pollEvents() 
{
    
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
                        if (Board_.getGridValue(i) == 0) 
                        {
                            Board_.updateBoard(i, this->turn_);
                            switchTurn();
                            numberOfTurns++;
                            for (int i = 0; i < 400000000; i++) {
                            //delay
                            }
                        }
                        else 
                        {
                            //do nothing bc a symbol is already placed on the sqaure
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
                        this->turn_ = X;
                        this->crossWins_ = false;
                        for (int i = 0; i < 400000000; i++) {
                            //delay
                        }
                }
            }

            //checks if mouse button is pressed on the restart text
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
            {
                if ((startMenu_.getRestartBottonHitbox()).contains(this->mousePosView) && this->state_ == GameOver) 
                {   
                    Board_.resetGridValueAndSymbol();
                    this->turn_ = X;
                    this->crossWins_ = false;
                    this->state_ = Menu;
                    this->numberOfTurns = 0;
                    this->gameIsATie_ = false;
                    for (int i = 0; i < 100000000; i++) 
                        {
                        //delay
                        }
                }
            }

            //checks if game is a tie:
            if (numberOfTurns == 9) 
            {
                this->state_ = GameOver;
                this->gameIsATie_ = true;
            }

            //Game logic if statement:
            if (this->state_ == Ingame) 
            {
                for (int i = 0; i < 8; i++) 
                {
                    int temp{};
                    for (int j = 0; j < 3; j++)
                    {
                        temp += Board_.getGridValue(winningCombinations_[i][j]);
                    }

                    if (temp == 21 || temp == 30) 
                    {
                        if (temp == 30) 
                        {
                            this->crossWins_ = true;
                        }
                        temp = 0;
                        this->state_ = GameOver;
                    }
                        temp = 0;
                }
            }
        }
}