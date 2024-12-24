#include "KillerGarageDoor.h"

#include <iostream>


std::string KillerGarageDoor::ProcessEvents(std::string events)
{
    int CurrentPosition = 0;
    bool isClosed = true;
    bool isClosing = false;
    bool isOpened = false;
    bool isOpening = false;
    bool isStopped = false;
    
    std::string MovementHistory;

    for (int i=0; i<events.size(); i++)
    {
        int MovementVelocity = 0;
        if (events[i] == '.')
        {
            if (isClosing && CurrentPosition > 0 && !isStopped)
            {
                MovementVelocity = -1;
            }
            else if (isOpening && CurrentPosition < 5 && !isStopped)
            {
                MovementVelocity = 1;
            }
        }
        else if (events[i] == 'P')
        {
            if (isClosed)
            {
                isClosed = false;
                isOpening = true;
                MovementVelocity = 1;
            } else if (isOpened)
            {
                isOpened = false;
                isClosing = true;
                MovementVelocity = -1;
            }
            else if ((isClosing || isOpening) && !isStopped)
            {
                MovementVelocity = 0;
                isStopped = true;
            }
            else if ((isClosing || isOpening) && isStopped)
            {
                MovementVelocity = isOpening ? 1 : -1;
                isStopped = false;
            }
        }
        else if (events[i] == 'O')
        {
            if (isClosing && !isStopped)
            {
                isClosing = false;
                isOpening = true;
                MovementVelocity = 1;
            }
            else if (isOpening && !isStopped)
            {
                isOpening = false;
                isClosing = true;
                MovementVelocity = -1;
            }
        }
        
        CurrentPosition += MovementVelocity;
        if (CurrentPosition == 0)
        {
            isClosed = true;
            isClosing = false;
        } else if (CurrentPosition == 5)
        {
            isOpened = true;
            isOpening = false;
        }
        
        MovementHistory.append(std::to_string(CurrentPosition));
    }
    
    return MovementHistory;
}

void KillerGarageDoor::Execute()
{
    std::cout << ProcessEvents("..P...O.....") << std::endl;
}
