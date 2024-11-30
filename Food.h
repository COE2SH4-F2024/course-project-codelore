#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "stdlib.h"
#include "time.h"
#include "Player.h"

class Food
{
    private:
        objPos foodPos; //Tracks the position of food

        GameMechs* mainGameMechsRef; // reference to main game mechanisms (if needed)

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(Player* blockOff);
        objPos getFoodPos() const;


};

#endif