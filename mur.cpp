#include "mur.h"

Mur::Mur(int abs, int ord):Case(abs,ord) //constructeur
{
}

void Mur::dessiner(QPainter * p) {
    p->drawPixmap(m_x, m_y, 80, 80,QPixmap(":/images/bobfond.jpg")); //dessine nos murs de taille 80x80 à la position m_x,my
}

int Mur::get_type(){ //renvoie le type (ici)
    return 1;
}
