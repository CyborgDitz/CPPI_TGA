#pragma once

class  Player
{
    public:
    Player();
    ~Player();
    bool isWin = {};
    bool isPoor = false;
    struct Data
    {
        enum class Streak
        {
            Null,
            Win,
            Loss
        };
    };
        int myMoney = 99999;
        const int streakArrayMax = 5;
        int  winStreak[5] = {0};
private:
    
};
