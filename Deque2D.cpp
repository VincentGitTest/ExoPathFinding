#include "Deque2D.hpp"



Deque2D::Deque2D()
{

}

// Creation du deque en regardant si on attribue au point des elements specifiques
Deque2D::Deque2D(int xSize, int ySize)
{
    std::deque<Point> tempDeque;
    Point tempPoint;
    for (int i = 0; i < xSize; i++)
    {
        for (int k = 0; k < ySize; k++)
        {
            tempPoint = { i,k };
            isAnObstacle(&tempPoint);
            tempDeque.push_back(tempPoint);
        }
        matrice.push_back(tempDeque);
        tempDeque.clear();
    }
}

Deque2D::~Deque2D()
{

}


// Recuperation du point a une position et non une coordonnee
Point* Deque2D::getPointTab(int x, int y)
{
    return &matrice[x][y];
}



// Recuperation des index du point dans le tableau
int Deque2D::getXIndex(Point* point)
{
    for (int i = 0; i < matrice.size(); i++)
    {
        for (int k = 0; k < matrice[0].size(); k++)
        {
            if (&matrice[i][k] == point)
            {
                return i;
            }
        }
    }

    return NULL;
}

int Deque2D::getYIndex(Point* point)
{
    for (int i = 0; i < matrice.size(); i++)
    {
        for (int k = 0; k < matrice[0].size(); k++)
        {
            if (&matrice[i][k] == point)
            {
                return k;
            }
        }
    }
    return NULL;
}




// Affichage de la map avec les obstacles
void Deque2D::afficherMap()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < matrice.size(); i++)
    {

        for (int k = 0; k < matrice[0].size(); k++)
        {
            if (matrice[i][k].path == true)
            {
                SetConsoleTextAttribute(hConsole, 12);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 7);

            }
            std::cout << matrice[i][k].obstacle << " ";
        }
        std::cout << std::endl;

    }
}


//Affichage de la map avec obstacles et point d'arrivee et de depart
void Deque2D::afficherMap(int xStart, int yStart, int xFinish, int yFinish)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < matrice.size(); i++)
    {

        for (int k = 0; k < matrice[0].size(); k++)
        {

            if (&matrice[i][k] == getPoint(xStart, yStart))
            {
                SetConsoleTextAttribute(hConsole, 2);
            }
            else if (&matrice[i][k] == getPoint(xFinish, yFinish))
            {
                SetConsoleTextAttribute(hConsole, 9);
            }
            else if (matrice[i][k].path == true)
            {
                SetConsoleTextAttribute(hConsole, 12);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 7);

            }
            std::cout << matrice[i][k].obstacle << " ";
        }
        std::cout << std::endl;

    }
}

// Recuperation du point a des coordonnees donnees, la fonction peut ajouter des lignes ou des colonnes si on cherche en dehors des coordonnees
Point* Deque2D::getPoint(int x, int y)
{
    // Point  au debut de la matrice
    int xSearch = matrice[0][0].x;

    // Verifications si on bouge en dehors du cadre
    if (x < xSearch)
    {
        
        moveUp();
        xSearch = matrice[0][0].x;
    }

    if (x > matrice[matrice.size() - 1][0].x)
    {

        moveDown();
        xSearch = matrice[0][0].x;
    }

    // Recherche de l'indice x correspondant au point
    int i = 0;
    while (xSearch != x)
    {
        xSearch++;
        i++;
    }

    // Point au debut de la matrice
    int ySearch = matrice[0][0].y;

    // Verifications si on bouge en dehors du cadre
    if (y < ySearch)
    {
        moveLeft();
    }


    if (y > matrice[0][matrice[0].size() - 1].y)
    {
        moveRight();
    }


    // Recherche de l'indice y correspondant au point
    int j = 0;
    while (ySearch != y)
    {
        ySearch++;
        j++;
    }



    return &matrice[i][j];


}


int Deque2D::getXSize() 
{
    return matrice.size();
}

int Deque2D::getYSize()
{
    return matrice[0].size();
}



 