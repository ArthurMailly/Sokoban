#include "plateau.h"

Plateau::Plateau(int hauteur, int largeur) //constructeur
{
    m_hauteur=hauteur;
    m_largeur=largeur;
    m_listeCases = new Case**[m_hauteur];
    for (int i=0;i<m_hauteur;i++)
    {
        m_listeCases[i] = new Case*[m_largeur];
        for (int j=0;j<m_largeur;j++)
        {
            m_listeCases[i][j] = NULL;
        }
    }
}

Plateau::~Plateau() //destructeur
{
    for(int i=0;i<m_hauteur;i++)
    {
        delete[] m_listeCases[i];
    }

    delete[] m_listeCases;
}

void Plateau::changerCase(int i, int j, Case *c) //modifie (i,j) de m_listeCases en la case c
{
    m_listeCases[i][j] = c;
}



void Plateau::dessiner(QPainter * p) //dessine les cases du plateau
{

    for (int i=0;i<m_hauteur;i++)
        for (int j=0;j<m_largeur;j++)
            m_listeCases[i][j]->dessiner(p);
}

Case* Plateau::getCase(int i, int j){  //renvoie la case m_listeCases[i][j]
    return m_listeCases[i][j];
}

void Plateau::dessinerVictoire(QPainter * p) {
    p->drawPixmap(100,100, 500, 500,QPixmap(":/images/Bravo.png"));
}

void Plateau::dessinerEntree(QPainter * p) {
    p->drawPixmap(100,100, 500, 500,QPixmap(":/images/bob_debut.png"));
}

void Plateau::dessinerRegles(QPainter * p) {
    p->drawPixmap(100,100, 500, 500,QPixmap(":/images/regles_bob.jpeg"));
}

