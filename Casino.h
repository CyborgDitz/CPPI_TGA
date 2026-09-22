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
    int InputInt();
    int RollDie();
    int RollRoulette();
    void SayInputError();
    void SayWin();
    void SayLose();
    void SayAskReadyToRoll();
    void SayEnterCasino();
    void SayTableMenu();
    void SayTableOutCashed();
    void SayTableTreshold(const Casino::GameState& aGameState, 
      const  TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven, const TableHighRoll::Data& aHighRoll,const TableRoulette::Data& aRoulette);
    void SayTableMoney(const Casino::GameState& aGameState,
        const TableGuess::Data& aGuess, const TableOddEven::Data& aOddEven,const TableHighRoll::Data& aHighRoll, const TableRoulette::Data& aRoulette);
    void SayGreetingTable(const Casino::GameState& aGameState);

    void SayPlayAgain();
    void PrintWinStreak(const Player::Data& aPlayer);
    void SayByeCasino();
    void SayRulesTable(const Casino::GameState& aGameState, Casino &aCasino);
    void SayMainMenuChoices();
    void SayMoneySum(const Player::Data& aPlayer);
    void PlayOddEven(GameState& aGameState, Player& aPlayer);
    
    bool isMainActive = false;
    bool IsTableActive = false;
    
    OddCoin getData() const;
    OddCoin CalcOddEven(int aDie);

    
    
    private:
    TableRoulette tableRoulette;
    TableGuess tableGuess;
    TableHighRoll tableHighRoll;
    TableOddEven tableOddEven;
    Player player;
};
