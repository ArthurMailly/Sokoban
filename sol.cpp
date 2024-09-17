#include "sol.h"

Sol::Sol(int abs, int ord):Case(abs,ord) //constructeur
{
}

void Sol::dessiner(QPainter * p) { //dessine le sol à la position m_x,m_y
    p->drawPixmap(m_x, m_y, 80, 80,QPixmap(":/images/sol_herbe.jpg"));
}

int Sol::get_type(){ //renvoie le type (ici 2)
    return 2;
}
