#ifndef CIBLE_H
#define CIBLE_H

#include "case.h"

class Cible: public Case
{
public:
    Cible(int abs=0, int ord=0); //constructeur
    void dessiner(QPainter * p); //dessine la caisse
    int get_x();  //renvoie l'abscisse
    int get_y();  //renvoie l'ordonnée
    int get_type(); // renvoie le type de la case (ici 3)

};

#endif // CIBLE_H




