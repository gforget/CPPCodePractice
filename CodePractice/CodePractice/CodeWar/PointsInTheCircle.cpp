#include "PointsInTheCircle.h"
#include <iostream>
#include <cmath>

//https://www.codewars.com/kata/5b55c49d4a317adff500015f/train/cpp
int PointsInTheCircle::pointsNumber(int radius)
{
    int nbPoints = 0;
    // Depth traversal of the cartesian graph
    for (int x = -radius; x <= radius; ++x) {
        for (int y = -radius; y <= radius; ++y) {
            if (sqrt(pow(x,2) + pow(y,2)) <= radius)
            {
                nbPoints++;
            }
        }
    }
    
    return nbPoints;  
}

void PointsInTheCircle::Execute()
{
    std::cout << pointsNumber(2) << ":\n";
}
