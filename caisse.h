#ifndef CAISSE_H
#define CAISSE_H

#include <QPainter>

class Caisse
{
protected:
    int m_x; //abscisse
    int m_y; //ordonnée
public:
    Caisse(int abs=0, int ord=0); //constructeur
    void dessiner(QPainter * p);  //permet de dessiner la caisse
    int get_x(); //permet d'obtenir l'abscisse
    int get_y(); //permet d'obtenir l'ordonnée
    bool getCase(int i, int j);  //permet de vérifier si la caisse est sur la case (i,j)
    void deplacerDe(int abs,int ord); //permet de déplacer la caisse
};

#endif // CAISSE_H
