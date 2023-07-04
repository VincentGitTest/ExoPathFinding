#include "Deque2D.hpp"




// Ajout du ligne vers le haut
void Deque2D::moveUp()
{

    int xAdd = (int)matrice[0][0].x - 1;


    std::deque<Point> tempDeque;
    Point tempPoint;
    for (int k = 0; k < matrice[0].size(); k++)
    {
        tempPoint = { xAdd, matrice[0][k].y };
        isAnObstacle(&tempPoint);
        tempDeque.push_back(tempPoint);
    }

    matrice.push_front(tempDeque);
}

// Ajout d'une colonne sur la droite
void Deque2D::moveRight()
{

    int yAdd = (int)matrice[0][matrice[0].size() - 1].y + 1;

    Point tempPoint;
    for (int i = 0; i < matrice.size(); i++)
    {

        tempPoint = { (int)matrice[i][0].x, yAdd };
        isAnObstacle(&tempPoint);
        matrice[i].push_back(tempPoint);
    }
}


// Ajout d'une colonne sur la gauche
void Deque2D::moveLeft()
{
    int yAdd = (int)matrice[0][0].y - 1;

    Point tempPoint;
    for (int i = 0; i < matrice.size(); i++)
    {

        tempPoint = { (int)matrice[i][0].x, yAdd };
        isAnObstacle(&tempPoint);
        matrice[i].push_front(tempPoint);

    }
}


// Ajout d'une ligne en bas
void Deque2D::moveDown()
{

    int xAdd = (int)matrice[matrice.size() - 1][0].x + 1;

    Point tempPoint;
    std::deque<Point> tempDeque;
    for (int k = 0; k < matrice[0].size(); k++)
    {
        tempPoint = { xAdd,matrice[0][k].y };
        isAnObstacle(&tempPoint);
        tempDeque.push_back(tempPoint);
    }

    matrice.push_back(tempDeque);
}

// Combinaisons des fonctions de deplacement
void Deque2D::moveHautGauche()
{
    Deque2D::moveLeft();
    Deque2D::moveUp();
}

void Deque2D::moveHautDroite()
{
    Deque2D::moveUp();
    Deque2D::moveRight();
}

void Deque2D::moveBasGauche()
{
    Deque2D::moveDown();
    Deque2D::moveLeft();
}

void Deque2D::moveBasDroite()
{
    Deque2D::moveDown();
    Deque2D::moveRight();
}