#include "cible.h"

Cible::Cible(int abs, int ord):Case(abs,ord) //constructeur
{

}

void Cible::dessiner(QPainter * p) {
    p->drawPixmap(m_x, m_y, 81 , 81,QPixmap(":/images/sol_sable.png"));//dessine nos cibles de taille 80x80 à la position m_x,my
}

int Cible::get_type(){ //renvoie le type de la case (3)
    return 3;
}

int Cible::get_x(){ //renvoie m_x
    return m_x;
}

int Cible::get_y(){ //renvoie m_y
    return m_y;
}
