#ifndef CASE_H
#define CASE_H

#include <QPainter>

class Case
{
protected:
    int m_x; //abs
    int m_y; //ord
public:
    Case(int abs=0, int ord=0); //constructeur
    virtual void dessiner(QPainter * p) =0; //dessine la case
    virtual int get_type() =0; // retourner 1 si c'est un mur, 2 si c'est du sol, 3 si c'est cible
};

#endif // CASE_H
