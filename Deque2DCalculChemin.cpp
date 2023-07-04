#include "Deque2D.hpp"





// Calcul du chemin entre deux points
std::vector<Point*>  Deque2D::calculatePath(int xStart, int yStart, int xFinish, int yFinish)
{
    // Vecteur de chemin
    std::vector<Point*> path;

    //Points de depart et d arrivee
    Point* start = getPoint(xStart, yStart);
    Point* finish = getPoint(xFinish, yFinish);

    // Force le depart et l arrivee a ne pas etre des obstacles
    start->obstacle = false;
    start->path = true;
    finish->obstacle = false;

    // Premiere position egale au depart
    Point* currentPos = start;



    while (currentPos != finish)
    {
        //Initialisation des vecteurs et de la verification de chemin
        Point* bestOption = NULL;
        std::vector <Point*> calculs;

        // Remplissage du vecteur avec les huits points autour
        for (int ajoutX = -1; ajoutX < 2; ajoutX += 1)
        {
            for (int ajoutY = -1; ajoutY < 2; ajoutY += 1)
            {
                if (!(ajoutX == 0 && ajoutY == 0))
                {
                    calculs.push_back(getPoint(currentPos->x + ajoutX, currentPos->y + ajoutY));
                }

            }
        }




        // Verification pour ne pas prendre comme option initiale un obstacle 
        int i = 0;
        while (bestOption == NULL)
        {
            if (calculs[i]->obstacle == false)
            {
                bestOption = calculs[i];

                // Calculs de g h et f, on calcule le point par lequel on commence pour ne pas tomber sur des valeurs nulles
                bestOption->g = sqrt((bestOption->x - start->x) * (bestOption->x - start->x) +
                    (bestOption->y - start->y) * (bestOption->y - start->y));

                bestOption->h = sqrt((bestOption->x - finish->x) * (bestOption->x - finish->x) +
                    (bestOption->y - finish->y) * (bestOption->y - finish->y));

                bestOption->f = bestOption->g + bestOption->h;
            }
            i++;


            // Arret de la boucle si le point initial est entoure d obstacles
            if (i == calculs.size())
            {
                path.clear();
                return path;
            }
        }


        // Calcul de route
        for (int i = 0; i < calculs.size(); i++)
        {

            Point* cal = calculs[i];

            // Calcul du chemin si le point n est pas deja utilise ou si ce n est pas un obstacle
            if (cal->path == false)
            {
                if (cal->obstacle == false)
                {
                    // Calculs de g, h et f
                    // g est la distance entre le point actuel et la position de depart
                    // h est la distance estimee entre le point actuel et la position finale
                    // f est le score final qui determine quel point est le plus interessant pour avancer
                    cal->g = sqrt((cal->x - start->x) * (cal->x - start->x) +
                        (cal->y - start->y) * (cal->y - start->y));

                    cal->h = sqrt((cal->x - finish->x) * (cal->x - finish->x) +
                        (cal->y - finish->y) * (cal->y - finish->y));


                    // On multiplie le score de f par la vitesse pour voir quel point est le plus interessant
                    cal->f = (cal->g + cal->h) * (1/cal->speed);




                    // Verification si g n est pas nul
                    if (cal->g != 0)
                    {
                        // Si le f actuel est inferieur a l ancien, considerer le f actuel comme la meilleure option
                        if (cal->f < bestOption->f)
                        {

                            bestOption = cal;
                        }
                        // Si les deux f sont equivalents, choisir le chemin qui a la distance avec l'origine le plus court
                        else if (cal->f = bestOption->f)
                        {
                            if (cal->g < bestOption->g)
                            {

                                bestOption = cal;
                            }
                        }
                    }
                }


            }

            // Si malgré tout g est égal à 0, on ne trouve pas de chemin
            if (bestOption->g == 0)
            {
                std::cout << "No path found" << std::endl;
                path.clear();
                return path;
            }

        }




        path.push_back(bestOption);
        currentPos = bestOption;

        currentPos->path = true;

        std::cout << currentPos->x << "," << currentPos->y << std::endl;


    }



    // Affichage du nombre de chemins pris et du chemin en question
    std::cout << "pathSize : " << path.size() << std::endl;

    std::cout << "resultat : " << std::endl;
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << "(" << path[i]->x << "," << path[i]->y << ") ";
    }

    std::cout << std::endl;

    return path;

}

