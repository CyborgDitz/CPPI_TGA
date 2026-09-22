#pragma once
#include "TableGuess.h"
#include "TableRoulette.h"
#include "TableHighRoll.h"
#include "TableOddEven.h"

class Casino
{
    public:
    Casino();
    ~Casino();
    
    enum class OddCoin
    {
        No_Coin,
        Odd,
        Even
    };
    void SayInputError();
    int InputInt();
    int RollDie();
    int RollRoulette();
    void SayWin();
    void SayLose();
    bool isMainActive = false;
    bool IsTableActive = false;
    
    OddCoin getData() const;
    OddCoin CalcOddEven(int aDie);
    enum class TableMenu
    {
        Exit_Table,
        BeginGame,
        Print_Rules,
        Print_Streak,
    };
    enum class GameState
    {
        Exit_Main,
        Table_Guess,
        Table_OddEven,
        Table_HighRoll,
        Table_Roulette,
        Winstreak
    };
    

    private:
    TableRoulette tableRoulette;
    TableGuess tableGuess;
    TableHighRoll tableHighRoll;
    TableOddEven tableOddEven;
};
