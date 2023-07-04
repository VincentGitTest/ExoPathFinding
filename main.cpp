

#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream>
#include <vector>
#include <windows.h> 
#include "point.hpp"
#include "Deque2D.hpp"
#include "manip.hpp"




int main()
{
    unsigned int seed = (unsigned)time(NULL);

    // Seed fixée
    //unsigned int seed = 40;
    srand(seed);

    // taille de base de la map
    int xSize = 10;
    int ySize = 10;

    // Generation de la map
    Deque2D* mat = new Deque2D(xSize, ySize);
    





    // Coordonnees de depart
    int xStart = 1;
    int yStart = 1;


    // Coordonnees finales
    int xFinish = 2;
    int yFinish = 3;
    

    // Test des fonctions de deplacement
    mat->moveUp(); mat->moveUp(); mat->moveUp(); 


    // Calcul du chemin 
    std::vector<Point*> path = mat->calculatePath(xStart, yStart, xFinish, yFinish);

    // Affichage de la carte avec debut et fin en bleu et vert
    mat->afficherMap(xStart, yStart, xFinish, yFinish);




    // Definition de la taille de la fenetre sfml et creation de celle-ci
    int wSize = 700;

    sf::RenderWindow window(sf::VideoMode(wSize, wSize), "TP Pathfinding");

    // Vecteur de points
    std::vector<sf::RectangleShape> carte;


    // Recuperation de la taille de la carte
    int xTable = mat->getXSize();
    int yTable = mat->getYSize();


    // Calcul de la carte
    for (int i = 0; i < xTable; i++)
    {
        for (int k = 0; k < yTable; k++)
        {
            //Recuperation du point actuel
            Point* point = mat->getPointTab(i,k);

            // Definition de la taille du point
            sf::RectangleShape shape(sf::Vector2f(wSize / (1.5* yTable ), wSize / (1.5 * xTable)));


            // Affichages en fonction des attribus
            if (point->obstacle == true)
            {
                shape.setFillColor(sf::Color::Black);
            }
            else if (point->speed == 1.2f)
            {
                shape.setFillColor(sf::Color::Green);
            }
            else if (point->speed == 0.3f)
            {
                shape.setFillColor(sf::Color::Red);
            }
            else
            {
                shape.setFillColor(sf::Color::Yellow);
            }

            // Position du point
            shape.setPosition(sf::Vector2f(  (wSize / yTable) * k, (wSize / xTable) * i) );


            carte.push_back(shape);
        }
    }

    //// Vecteur de lignes correspondant au chemin
    //std::vector<sf::VertexArray> lines;

    //for (int i = 0; i < path.size() -1; i++)
    //{
    //    // Recuperation des points
    //    Point* point1 = path[i];
    //    Point* point2 = path[i + 1];

    //    // Recuperation des coordonnees
    //    int x1 = mat->getXIndex(point1);
    //    int x2 = mat->getXIndex(point2);

    //    int y1 = mat->getYIndex(point1);
    //    int y2 = mat->getYIndex(point2);

    //    sf::VertexArray line(sf::Triangles, 2);

    //    // Definition des positions
    //    line[0].position = sf::Vector2f((wSize / yTable) * y1, (wSize / xTable) * x1);
    //    line[1].position = sf::Vector2f((wSize / yTable) * y2, (wSize / xTable) * x2);
    //    
    //    // Couleur de la ligne
    //    line[0].color = sf::Color::Blue;
    //    line[1].color = sf::Color::Blue;


    //    lines.push_back(line);
    //}




    // Fonction de dessin tant que la fenêtre est ouverte
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < carte.size(); i++)
        {
            window.draw(carte[i]);
        }
        
        /*for (int i = 0; i < lines.size(); i++)
        {
            window.draw(lines[i]);
        }*/

        
        window.display();
    }







    delete mat;
    return 0;
}