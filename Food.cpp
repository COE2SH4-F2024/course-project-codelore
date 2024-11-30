#include "Food.h";

Food::Food()
{
    foodPos = objPos() //Default instance
}

Food::~Food()
{
    // if required
}

void Food::generateFood(objPos blockOff)
{
    int randomX, randomY, i;
    bool validPosition = false;
    //For seeding random number generation (PPA3)
    srand(time(NULL));
    length = mainGameMechsRef -> getBoardSizeY();
    width = mainGameMechsRef -> getBoardSizeX();

    while (!validPosition){
        randomX = 
    }

}

objPos Food::getFoodPos() const
{
}