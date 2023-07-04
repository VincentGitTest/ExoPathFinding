#pragma once

struct Point
{

    // coordonnees
    int x;
    int y;

    // obstacle ou non
    bool obstacle = false;

    // Calcul de pathfinding
    float g = 0;
    float h = 0;
    float f = 0;

    // Verification si on est deja passe par ce poitn
    bool path = false;

    // Vitesse du terrain
    float speed = 1;
};