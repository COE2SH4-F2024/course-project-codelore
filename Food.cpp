#include "Food.h"

Food::Food(GameMechs* thisGMRef)
{
    foodPos = objPos(); //Default instance
    mainGameMechsRef = thisGMRef;
}

Food::~Food()
{
    // if required
}

void Food::generateFood(Player* blockOff)
{
    int randomX, randomY, i, bLength, bWidth;
    bool validPosition = false;
    //For seeding random number generation (PPA3)
    srand(time(NULL));
    bLength = mainGameMechsRef -> getBoardSizeY();
    bWidth = mainGameMechsRef -> getBoardSizeX();

    while (!validPosition){
        randomX = (rand() % (bWidth - 2)) + 1;
        randomY = (rand() % (bLength - 2)) + 1; 

        if (randomX == blockOff -> playX() && randomY == blockOff -> playY())
            {
                validPosition = false;
            }
        else {
            validPosition = true;
        }
    }
    foodPos.pos -> x = randomX;
    foodPos.pos -> y = randomY;

}

objPos Food::getFoodPos() const
{
    return foodPos;
}