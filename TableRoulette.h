#pragma once
#include <iostream>

#include "Casino.h"
#include "Player.h"

namespace TableRoulette
{
    struct Data
    {
        int myMoney = {1000};
        int myTreshBig = 2000;
        int myTreshSmall = 500;
        int myStraighGayMult = 35;
        int myRedBlackMult = 3;
        int myOddEvenMult = 1;
        int myColumnMult = 2;
        int mySlotsMax = 36;
        int mySlotsMin = 0;
        
        enum class Color
        {
            Green = 0,
            Black = 1,
            Red = 2
        };
        enum class Bets
        {
            Invalid = 0,
            Straight_Gay = 1,
            Red_Black = 2,
            Odd_Even = 3,
            Column = 4
        };
        enum class Column
        {
            Columnn_One = 1,
            Column_Two = 2,
            Column_Three = 3
        };
    };
    Data::Color CalcRoulleteOddEven();
    void PlayColumn(Player::Data& data, const int aColumnValue);
    void PlayColor(Player::Data& aPlayer);
    void PlayTable(Player::Data& aPlayer, Data& aRoulette);
    void RouletteBet(Player::Data& aPlayer, const Data& aRoulette);
    void PlayStraight(Player::Data& aPlayer, Data aRoulette);
};
