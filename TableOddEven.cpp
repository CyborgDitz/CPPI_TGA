#include <iostream>
#include "TableOddEven.h"

#include "Casino.h"
#include "Hasardspel.h"


void Casino::PlayOddEven(GameState& aGameState, Player& aPlayer)
{
    {
        bool isInputActive = true;
        OddCoin playerGuess = {};
        while (isInputActive)
        {
            SayRulesTable(aGameState);
            playerGuess = static_cast<OddCoin>(InputInt());
            if (playerGuess == OddCoin::Odd || playerGuess == OddCoin::Even)
            {
                isInputActive = false;
            }
            else
            {
                SayInputError();
            }
        }

        const int die = RollDie();
        std::cout << "I rolled: " << die << std::endl;

        if (playerGuess != CalcOddEven(RollDie()))
        {
            aPlayer.isWin = false;
            SayLose();
        }
        else
        {
            aPlayer.isWin = true;
            SayWin();
        }
    }
}

void Casino::SayAskReadyToRoll()
{
    std::cout << "Ready to roll? Press any key to GO!" << std::endl;
};
