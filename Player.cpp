#include "Player.h"
#include "GameMechs.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos = objPos(15, 7, '*');         //<-- Will change this 
}


Player::~Player()
{
    // delete any heap members here         <-- Will change this 
}

objPos Player::getPlayerPos() const
{
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
    int xPos, yPos, len, wid;
    len = mainGameMechsRef -> getBoardSizeY();
    wid = mainGameMechsRef -> getBoardSizeX();
    xPos = playerPos.getX();
    yPos = playerPos.getY();

    switch (myDir){
        case STOP:
            return;
        
        case UP:
            playerPos.changeY(-1);
            break;
        
        case DOWN:
            playerPos.changeY(1);
            break;

        case LEFT:
            playerPos.changeX(-1);
            break;
        
        case RIGHT:
            playerPos.changeX(1);
            break;
        
        default:
            break;

    }

    if (yPos < 1){
        //player.y = bHEIGHT - 2;
        playerPos.setY(len - 2);
    }
    else if (yPos > (len - 2))
    {
        //player.y = 1;
        playerPos.setY(1);
    }
    else if (xPos < 1){
        //player.x = bWIDTH - 2;
        playerPos.setX(wid - 2);
    }
    else if (xPos > (wid - 2)){
        //player.x = 1;
        playerPos.setX(1);
    }
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

//Getter Method for X and Y
int Player:: playX(){
    return playerPos.getX();
}

int Player:: playY() {
    return playerPos.getY();
}