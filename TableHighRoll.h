#pragma once
#include "Casino.h"
#include "Player.h"
#include "Data.h"

class TableHighRoll
{
public:
    
    struct Data
    {
        int myMoney = {100};
        int myTreshBig = 200;
        int myTreshSmall = 50;
        int myTableMultiplier = 1;
        int myTableBonus = 69;
    };
private:
    void PlayTable(Player::Data& aPlayer);
    void SayAskReadyToRoll();
};
