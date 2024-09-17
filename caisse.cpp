#include "caisse.h"

Caisse::Caisse(int abs, int ord) //constructeur
{
    m_x=abs;
    m_y=ord;
}

void Caisse::dessiner(QPainter * p)
{
    p->drawPixmap(m_x, m_y, 60, 60,QPixmap(":/images/caisse.png")); // dessine nos méduses de taille 60x60 à la position m_x,my
}

int Caisse::get_x(){
    return m_x; //renvoie m_x
}

int Caisse::get_y(){
    return m_y;  //renvoie m_y
}

bool Caisse::getCase(int i, int j){
    if (((m_x-5)/80-1==i)&&((m_y-5)/80-1==j)) // pour centrer la caisse nous avons ajouté 5 à sa position qu'il faut donc enlever avant de verifier l'égalité
        return true; // renvoie true si la caisse est sur la case (i,j)
    return false; // renvoie false sinon
}

void Caisse::deplacerDe(int abs,int ord)
{
    m_x=m_x+abs;  //modifie m_x pour déplacer nos caisses
    m_y=m_y+ord;  //modifie m_y pour déplacer nos caisses
}
