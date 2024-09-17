#include "personnage.h"

Personnage::Personnage(int abs, int ord,int num) //constructeur
{
    m_x=abs;
    m_y=ord;
    m_num=num;
}


void Personnage::dessiner(QPainter * p) //dessine le personnage en fonction de m_num
{

    switch ( m_num )
    {
    case 1:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/bob2.png"));
        break;
    case 2:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/Patrick_perso.png"));
        break;
    case 3:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/Carlos_perso.png"));
        break;
    case 4:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/Gary_perso2.png"));
        break;
    case 5:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/Capitaine_crabs_perso.png"));
        break;
    case 6:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/sandy_perso.png"));
        break;
    case 7:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/Plankton_perso.png"));
        break;
    case 8:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/arthur_perso2.png"));
        break;
    case 9:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/manon_perso.png"));
        break;
    default:
        p->drawPixmap(m_x, m_y, 70, 70,QPixmap(":/images/bob2.png"));

    }

}

void Personnage::deplacerDe(int abs,int ord)
{
    m_x=m_x+abs; //change l'abscisse du personnage
    m_y=m_y+ord; //change l'ordonné du personnage
}

int Personnage::get_x(void){return m_x;} //renvoie m_x

int Personnage::get_y(void){return m_y;} //renvoie m_y

void Personnage::set_num(int num){ //modifie la valeur de m_num
    m_num=num;
}

int Personnage::get_num(void){return m_num;} //renvoie la valeur de m_num
