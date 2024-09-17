#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QPainter>

class Personnage
{
protected:
    int m_x;
    int m_y;
    int m_num; // permet de savoir avec quel personnage on joue
public:
    Personnage(int abs=0, int ord=0,int num=1); //constructeur
    int get_x(void); //renvoie l'abscisse
    int get_y(void); //renvoie l'ordonné
    void dessiner(QPainter * p); //dessine le personnage
    void deplacerDe(int abs,int ord); //deplace le personnage
    void set_num(int num); //modifie la valeur de m_num
    int get_num(void); //renvoie m_num
};

#endif // PERSONNAGE_H
