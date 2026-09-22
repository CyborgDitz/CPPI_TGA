#include "TableRoulette.h"
#include <iostream>
#include <ostream>
#include "Data.h"
#include "Casino.h"
#include "Player.h"

namespace TableRoulette
{
    void PlayStraight(Player::Data& aPlayer, Data aRoulette)
    {

        bool isInputActive = true;
        const int die1 = Casino::RollRoulette();
        const int DiceSum = die1;

        int playerGuess = Casino::InputInt();

        while (isInputActive)
        {

            if (aRoulette.mySlotsMin <= playerGuess && playerGuess <= aRoulette.mySlotsMax)
            {
                std::cout << "Gotcha!" << std::endl;
                isInputActive = false;
            }
            //cheat  codes to win, input 69 or 67
            else if (playerGuess == 69 || playerGuess == 67)
            {
                playerGuess = DiceSum;
                isInputActive = false;
            }
            else
            {
                isInputActive = true;
            }
        }
        std::cout << "I spun the ball on: " << die1 << std::endl;
        if (playerGuess != DiceSum)
        {
            aPlayer.isWin = false;
            Casino::SayLose();
        }
        else
        {
            aPlayer.isWin = true;
            Casino::SayWin();
        }
    }
    void PlayColumn(Player::Data& aPlayer, const int aColumnValue)
    {
        const int divideToThirds = 2;
        int randomColumn = Casino::RollDie() / divideToThirds;
        
        if (aColumnValue!= randomColumn)
        {
            aPlayer.isWin = false;
            Casino::SayLose();
        }
        else
        {
            aPlayer.isWin = true;
            Casino::SayWin();
        }
    }
    void RouletteBet(Player::Data& aPlayer, const Data& aRoulette)
    {
        bool isBetting = true;
        std::cout << "gimme these" << aPlayer.myMoney << std::endl;
        std::cout << "Pick what you want to bet on!\n 1. Straight\t2. Red/Black 3.\n Odd/Even\t4. Column bet!!" << std::endl;
        while (isBetting)
        {
            switch (static_cast<Data::Bets>(Casino::InputInt()))
            {
                case Data::Bets::Invalid:
                {
                    std::cout << "Nope, you have to bet" << std::endl;
                    break;
                }
                case Data::Bets::Straight_Gay:
                {
                    std::cout << "What are you betting on of 0-36?" << std::endl;
                    PlayStraight(aPlayer, aRoulette);
                    isBetting = false;
                    break;
                }

                case Data::Bets::Red_Black:
                {
                    std::cout << "Are you betting 1. Red or  2. Black" << std::endl;
                    Data::Color color = static_cast<Data::Color>(Casino::InputInt());
                    switch (color)
                    {
                        case Data::Color::Black:
                        {
                            std::cout << "black!" << std::endl;
                            break;
                        }
                        case Data::Color::Red:
                        {
                            std::cout << "red!" << std::endl;
                            break;
                        }
                        case Data::Color::Green:
                        default:
                        {
                            std::cout << "No!" << std::endl;
                            break;
                        }
                    }
                    PlayColor(aPlayer);
                    isBetting = false;
                    break;
                }
                case Data::Bets::Odd_Even:
                {
                    std::cout << "Are you betting 1. Odd or  2. Even?" << std::endl;
                    Data::Color color = static_cast<Data::Color>(Casino::InputInt());
                    switch (color)
                    {
                        case Data::Color::Black:
                        {
                            std::cout << "Odd!!" << std::endl;
                            break;
                        }
                        case Data::Color::Red:
                        {
                            std::cout << "Even!" << std::endl;
                            break;
                        }
                        case Data::Color::Green:
                        default:
                        {
                            std::cout << "No!" << std::endl;
                            break;
                        }

                    }
                    PlayColor(aPlayer);
                    isBetting = false;
                    break;
                }
                case Data::Bets::Column:
                {

                    std::cout << "What colum are you betting on?\n 1. left\t2. middle\t3. right" << std::endl;
                    Data::Column column = static_cast<Data::Column>(Casino::InputInt());
                    int columnValue = {};
                    bool isColumnActive = true;
                    while (isColumnActive)
                    {


                        switch (column)
                        {
                            case Data::Column::Columnn_One:
                            {
                                columnValue = 1;
                                std::cout << "Columnn One" << std::endl;
                                break;
                            }

                            case Data::Column::Column_Two:
                            {
                                columnValue = 2;
                                std::cout << "Column Two" << std::endl;
                                break;
                            }
                            case Data::Column::Column_Three:
                            {

                                columnValue = 3;
                                std::cout << "Column Three" << std::endl;
                                break;
                            }
                            default:
                            {
                                columnValue = 3;
                                std::cout << "You cant do that!" << std::endl;
                                break;
                            }
                        }

                    }
                    PlayColumn(aPlayer, columnValue);
                    isBetting = false;

                    break;
                }
            }
        }
    }
    void PlayColor(Player::Data& aPlayer)
    {
        {
            Data::Color  spinLogic = {};
            
            if (spinLogic != CalcRoulleteOddEven())
            {
                aPlayer.isWin = false;
                Casino::SayLose();
            }
            else
            {
                aPlayer.isWin = true;
                Casino::SayWin();
            }
        }
    }

  Data::Color CalcRoulleteOddEven()
    {
        int returnValue = {};
        const int die = Casino::RollRoulette();
        if (die % 2 == 1)
        {
            std::cout << "It is Odd!" << std::endl;
           returnValue = 1;
        }
        else if ( die % 2 == 0)
        {
            std::cout << "It is Even!" << std::endl;
            returnValue = 2;
        }
        else
        {
            std::cout << "It is a zero! oof!" << std::endl;
            returnValue = 0;
        }
        return;
    }
    void PlayTable(Player::Data& aPlayer, Data& aRoulette)
    {
        RouletteBet(aPlayer, aRoulette);
    }
}
