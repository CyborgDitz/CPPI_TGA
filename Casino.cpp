#include "Casino.h"

#include <iostream>
#include <random>

#include "Hasardspel.h"

int Casino::InputInt()
{
    int playerInput = {};
    int returnValue{};
    bool isInputActive = true;
    while (isInputActive)
    {
        std::cin >> playerInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            SayInputError();
            //TODO input min and Max
        }
        else
        {
            returnValue = playerInput;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            isInputActive = false;
        }
    }

    return returnValue;
}

int Casino::RollDie()
{
    std::random_device seed;
    std::mt19937 rndEngine(seed());
    std::uniform_int_distribution<int> rndDist(1, 6);
    int randomNumber = rndDist(rndEngine);
    return randomNumber;
};

int Casino::RollRoulette()
{
    std::random_device seed;
    std::mt19937 rndEngine(seed());
    std::uniform_int_distribution<int> rndDist(0, 36);
    int randomNumber = rndDist(rndEngine);
    return randomNumber;
};

void Casino::SayWin()
{
    std::cout << "You win!" << std::endl;
}

void Casino::SayLose()
{
    std::cout << "Thats your loss, you unlucky fool! \n" << std::endl;
}

void Casino::SayInputError()
{
    std::cout << "wrong input!" << std::endl;
}

Casino::OddCoin CalcOddEven(int aDie)
{
    const int die = aDie;
    if (die % 2 == 1)
    {
        std::cout << "It is Odd!" << std::endl;
        return Casino::OddCoin::Odd;
    }
    else
    {
        std::cout << "It is Even!" << std::endl;
        return Casino::OddCoin::Even;
    }
}

void SayAskReadyToRoll()
{
    std::cout << "Are you ready to start? Press any button to begin" << std::endl;
}
void SayEnterCasino()
{
    std::cout << "Welcome to the Casino, friend! \n" << std::endl;
    std::cout << "What would you like to do? \n" << std::endl;
}
void SayTableMenu()
{
    std::cout << "1: Play the game. \t 2: Show Rules.\n" "3: Show Win Streak \t 0: Leave and go back to Main Menu" << std::endl;
};
void SayTableOutCashed()
{
    std::cout << "You have claimed too much of this table, begone!" << std::endl;
}
void SayPlayAgain()
{
    std::cout << "Want to play again? Y or N?" << std::endl;
}
void SayTableTreshold(const Casino::GameState& aGameState,
                      const TableGuess::Data& aGuess,const TableOddEven::Data& aOddEven,const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette)
{
    // debug SayTableSpoils(aGameState);
    // optimizable cases for multiple usage of code (bools), use for loop if true with enum
    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            if (aGuess.myMoney >= aGuess.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aGuess.myMoney <= aGuess.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            if (aOddEven.myMoney >= aOddEven.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aOddEven.myMoney <= aOddEven.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            if (aHighRoll.myMoney >= aHighRoll.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aHighRoll.myMoney <= aHighRoll.myTreshBig)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            if (aRoulette.myMoney >= aRoulette.myTreshBig)
            {
                std::cout << "We have a big winner here, why quit when the fire is hot amiright?" << std::endl;
            }
            else if (aRoulette.myMoney <= aRoulette.myTreshSmall)
            {
                std::cout << "Try again, regain your losses!?" << std::endl;
            }
            else
            {
                std::cout << "You should  spend that money here and nowhere else!" << std::endl;
            }
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
        default:
        {
            break;
        }
        
    }
}

void SayByeCasino(Player::Data& aPlayer)
{
    SayMoneySum(aPlayer);
    std::cout << "Goodbye friend, and  good luck!" << std::endl;
    system("pause");
}
void SayGreetingTable(const Casino::GameState& aGameState)
{
    switch (aGameState)
    {
        case Casino::GameState::Table_OddEven:
        {
            std::cout << "This is the best table for the best gambler, the guessing table! \n"
                << "If you guess the sum of my 2 dice then you win! \n" << std::endl;
            break;
        }
        case Casino::GameState::Table_Guess:
        {
            std::cout << "Welcome to the odd or even table!" << std::endl;
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            std::cout << "Welcome to the ROULETTE!" << std::endl;
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}
void SayRulesTable(const Casino::GameState& aGameState, Casino& aCasino)
{
    switch (aGameState)
    {
        case Casino::GameState::Table_Guess:
        {
            std::cout << "The table is open! So give me one between 2 and 12! Lets gamble!" << std::endl;
            break;
        }
        case Casino::GameState::Table_OddEven:
        {
            std::cout << "The table is open! So guess if its 1: Odd, 2: even! 50 50!" << std::endl;
            break;
        }
        case Casino::GameState::Table_HighRoll:
        {
            std::cout << "Just roll higher than me!" << std::endl;
            break;
        }
        case Casino::GameState::Table_Roulette:
        {
            std::cout << "There are four bet types: \n"
                         << "1. Straight, guess a the number the ball lands on, between 0 and 36\n" <<
                             "2. Red or Black, guess the color of the number the ball lands on! However, the 0 is green and you cant guess that. \n" <<
                                 "3. Odd or Even, guess if the number is odd or even! However, the 0 doesnt count as either!" <<
                                     "4. Column Bet, there are three columns where the ball can land on.\n " <<
                                     "Left, middle, or right. The numbers are shown here (insert picture)" << std::endl;
                                 
            break;
        }
        case Casino::GameState::Exit_Main:
        case Casino::GameState::Winstreak:
        default:
        {
            aCasino.SayInputError();
            break;
        }
    }
}

void SayMainMenuChoices()
{
    std::cout << "You can choose between these options \n"
        << "1: Table 1: Guess the Dice \t 2: Table 2: Odd or Even \n"
        << "3: Table 3: Roll Higher \t 4: Table 4: Roulette\n"
        << "5: Show Win / Loss Statistics \t 0: Or leave the casino!\n" << std::endl;
}
void SayMoneySum(const Player& aPlayer)
{
    std::cout << "You currently have " << aPlayer.myMoney << " dollaridoos! \n";
}
void SayTableMoney(const Casino::GameState& aGameState, const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, 
    const TableHighRoll::Data& aHighRoll,const TableRoulette::Data& aRoulette)
{
    if (aGameState == Casino::GameState::Table_Guess)
    {
        std::cout << "This table currently have " << aGuess.myMoney << " dollaridoos! \n";
    }
    else if (aGameState == Casino::GameState::Table_OddEven)
    {
        std::cout << "This table currently have " << aOddEven.myMoney << " dollaridoos!\n";
    }
    else if (aGameState == Casino::GameState::Table_HighRoll)
    {
        std::cout << "This table currently have " << aHighRoll.myMoney << " dollaridoos! \n";
    }
    else if (aGameState == Casino::GameState::Table_Roulette)
    {
        std::cout << "This table currently have " << aRoulette.myMoney << " dollaridoos! \n";
    }
}
