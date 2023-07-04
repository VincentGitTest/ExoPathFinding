#pragma once

#include <deque>
#include <iostream>
#include <vector>
#include "point.hpp"
#include "manip.hpp"
#include <windows.h>



// Classe de la carte bidimensionnelle de deque
class Deque2D
{
protected:
    std::deque<std::deque<Point>> matrice;

public:
    Deque2D();

    Deque2D(int xSize, int ySize);

    ~Deque2D();

    // Fonctions de deplacement
    void moveUp();

    void moveRight();

    void moveLeft();

    void moveDown();

    void moveHautGauche();

    void moveHautDroite();

    void moveBasGauche();

    void moveBasDroite();


    //Fonctions d'affichage
    void afficherMap();

    void afficherMap(int xStart, int yStart, int xFinish, int yFinish);


    //Fonctions pour recuperer le point en fonction de si on veut ses coordonnees ou sa place dans le tableau
    Point* getPoint(int x, int y);
    Point* getPointTab(int x, int y);

    std::vector<Point*> calculatePath(int xStart, int yStart, int xFinish, int yFinish);

    
    // Recuperation des indexes du point
    int getXIndex(Point* point);
    int getYIndex(Point* point);

    // Taille du tableau
    int getXSize();
    int getYSize();
};