#pragma once

class  Player
{
    public:
    struct Data
    {
        
        enum class Streak
        {
            Null,
            Win,
            Loss
        };
    };
private:
        int myMoney = 99999;
        const int streakArrayMax = 5;
        int  winStreak[5] = {0};
        bool isWin = {};
        bool isPoor = false;
    
};
