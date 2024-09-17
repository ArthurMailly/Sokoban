#ifndef MUR_H
#define MUR_H

#include "case.h"

class Mur : public Case
{
public:
    Mur(int abs=0, int ord=0); //constructeur
    void dessiner(QPainter * p); //dessine le mur
    int get_type(); //renvoie le type (ici )
};

#endif // MUR_H
