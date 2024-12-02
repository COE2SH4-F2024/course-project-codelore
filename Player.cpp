#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef, Food* thisFoodRef)
{
    mainGameMechsRef = thisGMRef;
    foodRef = thisFoodRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList;
    playerPosList -> insertHead(objPos(15, 7, '*'));         //<-- Will change this
    // playerPosList -> insertHead(objPos(16, 7, '*'));
    // playerPosList -> insertHead(objPos(17, 7, '*'));
    // playerPosList -> insertHead(objPos(18, 7, '*'));
    // playerPosList -> insertHead(objPos(19, 7, '*'));
}


Player::~Player()
{
    delete playerPosList;
    playerPosList = nullptr;
    // delete any heap members here         <-- Will change this
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
    // return the reference to the playerPos array list <-- Will change this
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input;
    input = mainGameMechsRef -> getInput();

    if(input != 0)
    {   
        switch(input)
        {
            case 'W':
            case 'w':
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = UP;
                }
                break;

            case 'A':
            case 'a':
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = LEFT;
                }
                break;

            case 'S':
            case 's':
                if(myDir == RIGHT || myDir == LEFT || myDir == STOP)
                {
                    myDir = DOWN;
                }
                break;

            case 'D':
            case 'd':
                if(myDir == UP || myDir == DOWN || myDir == STOP)
                {
                    myDir = RIGHT;
                }
                break;
            
            case 27:
                mainGameMechsRef -> setExitTrue();
                break;
            
            case 'L':
            case 'l':
                mainGameMechsRef -> setLoseFlag();
                break;
            
            case 'P':
            case 'p':
                mainGameMechsRef -> incrementScore();
                break;

            default:
                break;
        }
    }     
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int len, wid;
    len = mainGameMechsRef -> getBoardSizeY();
    wid = mainGameMechsRef -> getBoardSizeX();

    objPos temp = playerPosList -> getHeadElement();
    // symbol = temp.getSymbol();
    // xPos = temp.getX(); //I3
    // yPos = temp.getY(); //I3

    switch (myDir){
        case STOP:
            return;
        
        case UP:
            temp.changeY(-1); //changed to be more modular
            break;
        
        case DOWN:
            temp.changeY(1);
            break;

        case LEFT:
            temp.changeX(-1);
            break;
        
        case RIGHT:
            temp.changeX(1);
            break;
        
        default:
            break;

    }

    if (temp.getY() < 1){
        //player.y = bHEIGHT - 2;
        //playerPosList -> setY(len - 2);
        temp.setY(len-2);
    }
    else if (temp.getY() > (len - 2))
    {
        //player.y = 1;
        //playerPosList -> setY(1);
        temp.setY(1);
    }
    else if (temp.getX() < 1){
        //player.x = bWIDTH - 2;
        //playerPosList -> setX(wid - 2);
        temp.setX(wid-2);
    }
    else if (temp.getX() > (wid - 2)){
        //player.x = 1;
        //playerPosList -> setX(1);
        temp.setX(1);
    }
    playerPosList -> insertHead(temp);
    playerPosList -> removeTail();
    
    // playerPosList -> removeTail();
    // if (!checkFoodConsumption()){
    //     playerPosList -> removeTail();
    // }
}

// More methods to be added

char Player::getDirection() {
    switch(myDir){
        case STOP:
            return 'S';
            
        case UP:
            return 'U';
        
        case DOWN:
            return 'D';

        case LEFT:
            return 'L';
        
        case RIGHT:
            return 'R';
        
        default:
            return 'F';
    }
}

bool Player::checkFoodConsumption(){
    objPos temp = playerPosList -> getHeadElement();
    objPos foodTemp = foodRef -> getFoodPos();
    if (foodTemp.isPosEqual(&temp)){
        return true;
    }
    return false;

}

void Player::increasePlayerLength(){

}

//Getter Method for X and Y
int Player:: playX(){
    return playerPosList -> getHeadElement().getX();
}

int Player:: playY() {
    return playerPosList -> getHeadElement().getY();
}