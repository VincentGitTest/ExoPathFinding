#include "manip.hpp"
#include <iostream>



// Definit de maniere aleatoire si les points sont des obstacles et si leur vitesse varie
void isAnObstacle(Point* point)
{
    int v1 = rand() % 100;

    if (v1 < 15)
    {
        point->obstacle = true;
    }
    if (v1 > 80)
    {
        if (v1 > 90)
        {
            point->speed = 0.3;
        }
        else
        {
            point->speed = 1.2;
        }
    }
}