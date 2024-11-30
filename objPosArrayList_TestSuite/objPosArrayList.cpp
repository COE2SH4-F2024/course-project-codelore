#include "objPosArrayList.h"
#include <stdexcept>  // For exception handling

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = 200;
    listSize = 0;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    int i;

    if (listSize < arrayCapacity){
        listSize++;

        for(i=listSize; i > 0; i--){
            aList[i] = aList[i-1];
        }
        
    aList[0] = thisPos;
    }

    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity){
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    int i;

    if (listSize > 0){
        for(i = 0; i < listSize - 1; i++){
            aList[i] = aList[i+1];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail()
{
    if (listSize > 0){
        listSize--;
    }
    
}

objPos objPosArrayList::getHeadElement() const
{
    if (listSize > 0) {
        return aList[0];
    } else {
        return objPos();  //Makes sure that an objPos value is returned bc that is the return type of the function
    }
}

objPos objPosArrayList::getTailElement() const
{
    if (listSize > 0) {
        return aList[listSize - 1];
    } else {
        return objPos();
    }
}

objPos objPosArrayList::getElement(int index) const
{
    if (index >= 0 && index < listSize) {
        return aList[index];
    } else {
        return objPos();
    }

}