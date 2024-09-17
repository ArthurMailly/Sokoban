#ifndef SOL_H
#define SOL_H

#include "case.h"

class Sol : public Case{
public:
    Sol(int abs=0, int ord=0); //constructeur
    void dessiner(QPainter * p); //dessine le sol
    int get_type(); //renvoie le type (ici 2)
};

#endif // SOL_H
