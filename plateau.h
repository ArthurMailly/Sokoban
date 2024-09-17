#ifndef PLATEAU_H
#define PLATEAU_H

#include "mur.h"
#include "sol.h"
#include "cible.h"
#include <vector>

using namespace std;


class Plateau
{
protected:
    int m_hauteur;
    int m_largeur;
    Case ***m_listeCases; //contient les cases du niveau


public:
    Plateau(int hauteur, int largeur); //constructeur
    void changerCase(int i, int j, Case *c); //modifie la case
    void dessiner(QPainter * p); //dessine les cases
    Case* getCase(int i, int j); //renvoie la case m_listeCases[i][j]
    void dessinerVictoire(QPainter * p); //dessine l'image quand le joueur réussi le niveau
    void dessinerEntree(QPainter * p); //dessine l'image quand le joueur ouvre le jeu
    void dessinerRegles(QPainter * p); //dessine l'image quand le joueur ouvre les regles du jeu
    ~Plateau(); //destructeur
};

#endif // PLATEAU_H




