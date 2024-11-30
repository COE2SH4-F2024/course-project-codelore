#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "stdlib.h"
#include "time.h"

class Food
{
    private:
        objPos foodPos; //Tracks the position of food

        GameMechs mainGameMechRef; // reference to main game mechanisms (if needed)

    public:
        Food();
        ~Food();

        void generateFood(objPos blockOff);
        objPos getFoodPos() const;


}