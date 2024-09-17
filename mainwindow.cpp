#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //initialise les variables
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    niveau=0;
    personnages=1;
    fini = false;
    jouer=false;
    regles=false;
    numPerso=1;
    compteur=0;
    nbTimer=0;
    niveauMax=1;
}

MainWindow::~MainWindow() //destructeur de mainWindow
{
    delete[] listeCaisse;
    delete[] listeCible;
    delete p;
    delete timer;
    delete ui;

}

void MainWindow::niveau1() //création du niveau 1
{
    nC=2;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(5,5);
    perso = Personnage(165,165,numPerso);
    listeCaisse[0]= Caisse(250,250);
    listeCaisse[1]= Caisse(330,250);

    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));

    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));

    // derniere ligne
    p->changerCase(1,4, new Mur(160,400));
    p->changerCase(2,4, new Mur(240,400));
    p->changerCase(3,4, new Mur(320,400));

    // derniere colonne
    p->changerCase(4,1, new Mur(400,160));
    p->changerCase(4,2, new Mur(400,240));
    p->changerCase(4,3, new Mur(400,320));
    p->changerCase(4,4, new Mur(400,400));

    // milieu
    p->changerCase(1,1, new Sol(160,160));
    p->changerCase(1,2, new Cible(240,160));
    p->changerCase(1,3, new Sol(320,160));
    p->changerCase(2,1, new Sol(160,240));
    p->changerCase(2,2, new Sol(240,240));
    p->changerCase(2,3, new Sol(320,240));
    p->changerCase(3,1, new Sol(160,320));
    p->changerCase(3,2, new Sol(240,320));
    p->changerCase(3,3, new Cible(320,320));

    listeCible[0]=Cible(240,160);
    listeCible[1]=Cible(320,320);
}

void MainWindow::niveau2() //création du niveau 2
{
    nC=2;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(6,6);
    perso = Personnage(165,165,numPerso);
    listeCaisse[0]= Caisse(250,250);
    listeCaisse[1]= Caisse(330,250);

    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));


    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));


    // derniere ligne
    p->changerCase(1,5, new Mur(160,480));
    p->changerCase(2,5, new Mur(240,480));
    p->changerCase(3,5, new Mur(320,480));
    p->changerCase(4,5, new Mur(400,480));
    p->changerCase(5,5, new Mur(480,480));


    // derniere colonne
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,2, new Mur(480,240));
    p->changerCase(5,3, new Mur(480,320));
    p->changerCase(5,4, new Mur(480,400));


    // autres
    p->changerCase(4,1, new Mur(400,160));
    p->changerCase(3,3, new Mur(320,320));


    //     milieu
    p->changerCase(1,1, new Sol(160,160));
    p->changerCase(1,2, new Cible(160,240));
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(2,1, new Sol(240,160));
    p->changerCase(2,2, new Sol(240,240));
    p->changerCase(2,3, new Sol(240,320));
    p->changerCase(2,4, new Sol(240,400));
    p->changerCase(3,1, new Sol(320,160));
    p->changerCase(3,2, new Cible(320,240));
    p->changerCase(3,4, new Sol(320,400));
    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Sol(400,400));


    listeCible[0]=Cible(160,240);
    listeCible[1]=Cible(320,240);

}



void MainWindow::niveau3() //création du niveau 3
{
nC=2;
compteur=0;

listeCaisse=new Caisse[nC];
listeCible=new Cible[nC];

p = new Plateau(7,7);
perso = Personnage(165,245,numPerso);
listeCaisse[0]= Caisse(410,250);
listeCaisse[1]= Caisse(410,330);

// 1ere ligne
p->changerCase(0,0, new Mur(80,80));
p->changerCase(1,0, new Mur(160,80));
p->changerCase(2,0, new Mur(240,80));
p->changerCase(3,0, new Mur(320,80));
p->changerCase(4,0, new Mur(400,80));
p->changerCase(5,0, new Mur(480,80));
p->changerCase(6,0, new Mur(560,80));


// 1ere colonne
p->changerCase(0,1, new Mur(80,160));
p->changerCase(0,2, new Mur(80,240));
p->changerCase(0,3, new Mur(80,320));
p->changerCase(0,4, new Mur(80,400));
p->changerCase(0,5, new Mur(80,480));
p->changerCase(0,6, new Mur(80,560));


// derniere ligne
p->changerCase(1,6, new Mur(160,560));
p->changerCase(2,6, new Mur(240,560));
p->changerCase(3,6, new Mur(320,560));
p->changerCase(4,6, new Mur(400,560));
p->changerCase(5,6, new Mur(480,560));
p->changerCase(6,6, new Mur(560,560));


// derniere colonne
p->changerCase(6,1, new Mur(560,160));
p->changerCase(6,2, new Mur(560,240));
p->changerCase(6,3, new Mur(560,320));
p->changerCase(6,4, new Mur(560,400));
p->changerCase(6,5, new Mur(560,480));

// autres
p->changerCase(1,1, new Mur(160,160));
p->changerCase(2,1, new Mur(240,160));
p->changerCase(2,4, new Mur(240,400));
p->changerCase(5,1, new Mur(480,160));
p->changerCase(5,2, new Mur(480,240));




//     milieu
p->changerCase(1,2, new Sol(160,240));
p->changerCase(1,3, new Sol(160,320));
p->changerCase(1,4, new Sol(160,400));
p->changerCase(1,5, new Sol(160,480));
p->changerCase(2,2, new Sol(240,240));
p->changerCase(2,3, new Sol(240,320));
p->changerCase(2,5, new Sol(240,480));
p->changerCase(3,1, new Sol(320,160));
p->changerCase(3,2, new Cible(320,240));
p->changerCase(3,3, new Sol(320,320));
p->changerCase(3,4, new Cible(320,400));
p->changerCase(3,5, new Sol(320,480));
p->changerCase(4,1, new Sol(400,160));
p->changerCase(4,2, new Sol(400,240));
p->changerCase(4,3, new Sol(400,320));
p->changerCase(4,4, new Sol(400,400));
p->changerCase(4,5, new Sol(400,480));
p->changerCase(5,3, new Sol(480,320));
p->changerCase(5,4, new Sol(480,400));
p->changerCase(5,5, new Sol(480,480));



listeCible[0]=Cible(320,240);
listeCible[1]=Cible(320,400);

}


void MainWindow::niveau4() //création du niveau 4
{
    nC=3;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(8,8);
    perso = Personnage(565,245,numPerso);
    listeCaisse[0]= Caisse(490,250);
    listeCaisse[1]= Caisse(490,410);
    listeCaisse[2]= Caisse(250,410);

    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));
    p->changerCase(7,0, new Mur(640,80));


    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));
    p->changerCase(0,7, new Mur(80,640));


    // derniere ligne
    p->changerCase(1,7, new Mur(160,640));
    p->changerCase(2,7, new Mur(240,640));
    p->changerCase(3,7, new Mur(320,640));
    p->changerCase(4,7, new Mur(400,640));
    p->changerCase(5,7, new Mur(480,640));
    p->changerCase(6,7, new Mur(560,640));
    p->changerCase(7,7, new Mur(640,640));

    // derniere colonne
    p->changerCase(7,1, new Mur(640,160));
    p->changerCase(7,2, new Mur(640,240));
    p->changerCase(7,3, new Mur(640,320));
    p->changerCase(7,4, new Mur(640,400));
    p->changerCase(7,5, new Mur(640,480));
    p->changerCase(7,6, new Mur(640,560));

    // autres
    p->changerCase(1,1, new Mur(160,160));
    p->changerCase(1,2, new Mur(160,240));
    p->changerCase(3,2, new Mur(320,240));
    p->changerCase(3,3, new Mur(320,320));
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,3, new Mur(480,320));
    p->changerCase(5,5, new Mur(480,480));
    p->changerCase(5,6, new Mur(480,560));
    p->changerCase(6,1, new Mur(560,160));
    p->changerCase(6,5, new Mur(560,480));
    p->changerCase(6,6, new Mur(560,560));




    //     milieu
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(1,5, new Sol(160,480));
    p->changerCase(1,6, new Sol(160,560));
    p->changerCase(2,1, new Cible(240,160));
    p->changerCase(2,2, new Sol(240,240));
    p->changerCase(2,3, new Sol(240,320));
    p->changerCase(2,4, new Cible(240,400));
    p->changerCase(2,5, new Sol(240,480));
    p->changerCase(2,6, new Sol(240,560));
    p->changerCase(3,1, new Sol(320,160));
    p->changerCase(3,4, new Sol(320,400));
    p->changerCase(3,5, new Sol(320,480));
    p->changerCase(3,6, new Sol(320,560));
    p->changerCase(4,1, new Sol(400,160));
    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Sol(400,400));
    p->changerCase(4,5, new Sol(400,480));
    p->changerCase(4,6, new Sol(400,560));
    p->changerCase(5,2, new Sol(480,240));
    p->changerCase(5,4, new Sol(480,400));
    p->changerCase(6,2, new Sol(560,240));
    p->changerCase(6,3, new Sol(560,320));
    p->changerCase(6,4, new Cible(560,400));



    listeCible[0]=Cible(240,160);
    listeCible[1]=Cible(240,400);
    listeCible[2]=Cible(560,400);

}

void MainWindow::niveau5() //création du niveau 5
{
    nC=3;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(7,7);
    perso = Personnage(485,485,numPerso);
    listeCaisse[0]= Caisse(250,410);
    listeCaisse[1]= Caisse(330,410);
    listeCaisse[2]= Caisse(410,410);



    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));

    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));

    // derniere ligne
    p->changerCase(1,6, new Mur(160,560));
    p->changerCase(2,6, new Mur(240,560));
    p->changerCase(3,6, new Mur(320,560));
    p->changerCase(4,6, new Mur(400,560));
    p->changerCase(5,6, new Mur(480,560));
    p->changerCase(6,6, new Mur(560,560));


    // derniere colonne
    p->changerCase(6,1, new Mur(560,160));
    p->changerCase(6,2, new Mur(560,240));
    p->changerCase(6,3, new Mur(560,320));
    p->changerCase(6,4, new Mur(560,400));
    p->changerCase(6,5, new Mur(560,480));

    // autres
    p->changerCase(2,2, new Mur(240,240));
    p->changerCase(3,5, new Mur(320,480));
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,2, new Mur(480,240));


    //     milieu
    p->changerCase(1,1, new Sol(160,160));
    p->changerCase(1,2, new Sol(160,240));
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(1,5, new Sol(160,480));

    p->changerCase(2,1, new Sol(240,160));
    p->changerCase(2,3, new Sol(240,320));
    p->changerCase(2,4, new Sol(240,400));
    p->changerCase(2,5, new Sol(240,480));
    p->changerCase(3,1, new Cible(320,160));
    p->changerCase(3,2, new Cible(320,240));
    p->changerCase(3,3, new Cible(320,320));
    p->changerCase(3,4, new Sol(320,400));

    p->changerCase(4,1, new Sol(400,160));
    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Sol(400,400));
    p->changerCase(4,5, new Sol(400,480));
    p->changerCase(5,3, new Sol(480,320));
    p->changerCase(5,4, new Sol(480,400));
    p->changerCase(5,5, new Sol(480,480));




    listeCible[0]=Cible(320,160);
    listeCible[1]=Cible(320,240);
    listeCible[2]=Cible(320,320);
}

void MainWindow::niveau6() //création du niveau 6
{
    nC=3;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(7,7);
    perso = Personnage(245,165,numPerso);
    listeCaisse[0]= Caisse(250,330);
    listeCaisse[1]= Caisse(330,330);
    listeCaisse[2]= Caisse(410,330);



    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));

    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));

    // derniere ligne
    p->changerCase(1,6, new Mur(160,560));
    p->changerCase(2,6, new Mur(240,560));
    p->changerCase(3,6, new Mur(320,560));
    p->changerCase(4,6, new Mur(400,560));
    p->changerCase(5,6, new Mur(480,560));
    p->changerCase(6,6, new Mur(560,560));


    // derniere colonne
    p->changerCase(6,1, new Mur(560,160));
    p->changerCase(6,2, new Mur(560,240));
    p->changerCase(6,3, new Mur(560,320));
    p->changerCase(6,4, new Mur(560,400));
    p->changerCase(6,5, new Mur(560,480));

    // autres
    p->changerCase(1,1, new Mur(160,160));
    p->changerCase(1,5, new Mur(160,480));
    p->changerCase(3,2, new Mur(320,240));
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,5, new Mur(480,480));
    p->changerCase(6,0, new Mur(560,80));
    p->changerCase(6,6, new Mur(560,560));


    //     milieu
    p->changerCase(1,2, new Sol(160,240));
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(2,1, new Sol(240,160));
    p->changerCase(2,2, new Sol(240,240));
    p->changerCase(2,4, new Sol(240,400));
    p->changerCase(2,3, new Sol(240,320));
    p->changerCase(2,5, new Sol(240,480));
    p->changerCase(3,1, new Sol(320,160));
    p->changerCase(3,3, new Cible(320,320));
    p->changerCase(3,4, new Cible(320,400));
    p->changerCase(3,5, new Cible(320,480));
    p->changerCase(4,1, new Sol(400,160));
    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Sol(400,400));
    p->changerCase(4,5, new Sol(400,480));
    p->changerCase(5,2, new Sol(480,240));
    p->changerCase(5,3, new Sol(480,320));
    p->changerCase(5,4, new Sol(480,400));




    listeCible[0]=Cible(320,320);
    listeCible[1]=Cible(320,400);
    listeCible[2]=Cible(320,480);
}




void MainWindow::niveau7() //création du niveau 7
{
    nC=2;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(8,8);
    perso = Personnage(485,325,numPerso);
    listeCaisse[0]= Caisse(250,250);
    listeCaisse[1]= Caisse(410,330);

    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));
    p->changerCase(7,0, new Mur(640,80));


    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));
    p->changerCase(0,7, new Mur(80,640));


    // derniere ligne
    p->changerCase(1,7, new Mur(160,640));
    p->changerCase(2,7, new Mur(240,640));
    p->changerCase(3,7, new Mur(320,640));
    p->changerCase(4,7, new Mur(400,640));
    p->changerCase(5,7, new Mur(480,640));
    p->changerCase(6,7, new Mur(560,640));
    p->changerCase(7,7, new Mur(640,640));

    // derniere colonne
    p->changerCase(7,1, new Mur(640,160));
    p->changerCase(7,2, new Mur(640,240));
    p->changerCase(7,3, new Mur(640,320));
    p->changerCase(7,4, new Mur(640,400));
    p->changerCase(7,5, new Mur(640,480));
    p->changerCase(7,6, new Mur(640,560));

    // autres
    p->changerCase(1,1, new Mur(160,160));
    p->changerCase(1,2, new Mur(160,240));
    p->changerCase(2,4, new Mur(240,400));
    p->changerCase(2,5, new Mur(240,480));
    p->changerCase(3,2, new Mur(320,240));
    p->changerCase(4,6, new Mur(400,560));
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,2, new Mur(480,240));
    p->changerCase(5,4, new Mur(480,400));
    p->changerCase(5,6, new Mur(480,560));
    p->changerCase(6,1, new Mur(560,160));
    p->changerCase(6,2, new Mur(560,240));
    p->changerCase(6,6, new Mur(560,560));


    //     milieu
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(1,5, new Sol(160,480));
    p->changerCase(1,6, new Sol(160,560));
    p->changerCase(2,1, new Sol(240,160));
    p->changerCase(2,2, new Sol(240,240));
    p->changerCase(2,3, new Sol(240,320));
    p->changerCase(2,6, new Sol(240,560));
    p->changerCase(3,1, new Sol(320,160));
    p->changerCase(3,3, new Sol(320,320));
    p->changerCase(3,4, new Sol(320,400));
    p->changerCase(3,5, new Cible(320,480));
    p->changerCase(3,6, new Sol(320,560));
    p->changerCase(4,1, new Sol(400,160));
    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Sol(400,400));
    p->changerCase(4,5, new Sol(400,480));
    p->changerCase(5,3, new Sol(480,320));
    p->changerCase(5,5, new Cible(480,480));
    p->changerCase(6,3, new Sol(560,320));
    p->changerCase(6,4, new Sol(560,400));
    p->changerCase(6,5, new Sol(560,480));


    listeCible[0]=Cible(320,480);
    listeCible[1]=Cible(480,480);

}

void MainWindow::niveau8() //création du niveau 8
{
    nC=3;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(9,8);
    perso = Personnage(645,405,numPerso);
    listeCaisse[0]= Caisse(490,410);
    listeCaisse[1]= Caisse(570,410);
    listeCaisse[2]= Caisse(570,490);


    // 1ere ligne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));
    p->changerCase(7,0, new Mur(640,80));


    // 1ere colonne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));
    p->changerCase(0,7, new Mur(80,640));


    // derniere ligne
    p->changerCase(1,7, new Mur(160,640));
    p->changerCase(2,7, new Mur(240,640));
    p->changerCase(3,7, new Mur(320,640));
    p->changerCase(4,7, new Mur(400,640));
    p->changerCase(5,7, new Mur(480,640));
    p->changerCase(6,7, new Mur(560,640));
    p->changerCase(7,7, new Mur(640,640));

    // derniere colonne

    p->changerCase(8,0, new Mur(720,80));
    p->changerCase(8,1, new Mur(720,160));
    p->changerCase(8,2, new Mur(720,240));
    p->changerCase(8,3, new Mur(720,320));
    p->changerCase(8,4, new Mur(720,400));
    p->changerCase(8,5, new Mur(720,480));
    p->changerCase(8,6, new Mur(720,560));
    p->changerCase(8,7, new Mur(720,640));

    p->changerCase(7,1, new Mur(640,160));
    p->changerCase(7,2, new Mur(640,240));
    p->changerCase(7,3, new Mur(640,320));
    p->changerCase(7,4, new Sol(640,400));
    p->changerCase(7,5, new Sol(640,480));
    p->changerCase(7,6, new Mur(640,560));

    // autres
    p->changerCase(1,1, new Mur(160,160));
    p->changerCase(1,2, new Sol(160,240));
    p->changerCase(2,4, new Sol(240,400));
    p->changerCase(2,5, new Mur(240,480));
    p->changerCase(3,2, new Sol(320,240));
    p->changerCase(4,6, new Sol(400,560));
    p->changerCase(5,1, new Mur(480,160));
    p->changerCase(5,2, new Sol(480,240));
    p->changerCase(5,4, new Sol(480,400));
    p->changerCase(5,6, new Sol(480,560));
    p->changerCase(6,1, new Mur(560,160));
    p->changerCase(6,2, new Cible(560,240));
    p->changerCase(6,6, new Mur(560,560));



    //     milieu
    p->changerCase(1,3, new Sol(160,320));
    p->changerCase(1,4, new Sol(160,400));
    p->changerCase(1,5, new Mur(160,480));
    p->changerCase(1,6, new Mur(160,560));
    p->changerCase(2,1, new Sol(240,160));
    p->changerCase(2,2, new Cible(240,240));
    p->changerCase(2,3, new Mur(240,320));
    p->changerCase(2,6, new Mur(240,560));
    p->changerCase(3,1, new Sol(320,160));
    p->changerCase(3,3, new Sol(320,320));
    p->changerCase(3,4, new Sol(320,400));
    p->changerCase(3,5, new Sol(320,480));
    p->changerCase(3,6, new Sol(320,560));
    p->changerCase(4,1, new Sol(400,160));
    p->changerCase(4,2, new Cible(400,240));
    p->changerCase(4,3, new Mur(400,320));
    p->changerCase(4,4, new Sol(400,400));
    p->changerCase(4,5, new Mur(400,480));
    p->changerCase(5,3, new Mur(480,320));
    p->changerCase(5,5, new Sol(480,480));
    p->changerCase(6,3, new Sol(560,320));
    p->changerCase(6,4, new Sol(560,400));
    p->changerCase(6,5, new Sol(560,480));


    listeCible[0]=Cible(240,240);
    listeCible[1]=Cible(560,240);
    listeCible[2]=Cible(400,240);

}

void MainWindow::niveau9() //création du niveau 9
{
    nC=3;
    compteur=0;

    listeCaisse=new Caisse[nC];
    listeCible=new Cible[nC];

    p = new Plateau(10,9);
    perso = Personnage(565,325,numPerso);
    listeCaisse[0]= Caisse(410,410);
    listeCaisse[1]= Caisse(330,490);
    listeCaisse[2]= Caisse(250,570);

    // 1ere colonne
    p->changerCase(0,0, new Mur(80,80));
    p->changerCase(1,0, new Mur(160,80));
    p->changerCase(2,0, new Mur(240,80));
    p->changerCase(3,0, new Mur(320,80));
    p->changerCase(4,0, new Mur(400,80));
    p->changerCase(5,0, new Mur(480,80));
    p->changerCase(6,0, new Mur(560,80));
    p->changerCase(7,0, new Mur(640,80));
    p->changerCase(8,0, new Mur(720,80));

    // 1ere ligne
    p->changerCase(0,1, new Mur(80,160));
    p->changerCase(0,2, new Mur(80,240));
    p->changerCase(0,3, new Mur(80,320));
    p->changerCase(0,4, new Mur(80,400));
    p->changerCase(0,5, new Mur(80,480));
    p->changerCase(0,6, new Mur(80,560));
    p->changerCase(0,7, new Mur(80,640));
    p->changerCase(0,8, new Mur(80,720));
    p->changerCase(9,0, new Mur(800,80));


    // derniere colonne
    p->changerCase(8,1, new Mur(720,160));
    p->changerCase(8,2, new Sol(720,240));
    p->changerCase(8,3, new Sol(720,320));
    p->changerCase(8,4, new Sol(720,400));
    p->changerCase(8,5, new Mur(720,480));
    p->changerCase(8,6, new Mur(720,560));
    p->changerCase(8,7, new Mur(720,640));
    p->changerCase(8,8, new Mur(720,720));

    // derniere ligne
    p->changerCase(9,1, new Mur(800,160));
    p->changerCase(9,2, new Mur(800,240));
    p->changerCase(9,3, new Mur(800,320));
    p->changerCase(9,4, new Mur(800,400));
    p->changerCase(9,5, new Mur(800,480));
    p->changerCase(9,6, new Mur(800,560));
    p->changerCase(9,7, new Mur(800,640));
    p->changerCase(9,8, new Mur(800,720));


    // mur
    p->changerCase(1,1, new Mur(160,160));
    p->changerCase(1,2, new Mur(160,240));
    p->changerCase(1,3, new Mur(160,320));
    p->changerCase(1,4, new Mur(160,400));
    p->changerCase(1,8, new Mur(160,720));

    p->changerCase(2,1, new Mur(240,160));
    p->changerCase(2,2, new Mur(240,240));
    p->changerCase(2,3, new Mur(240,320));
    p->changerCase(2,8, new Mur(240,720));

    p->changerCase(3,1, new Mur(320,160));
    p->changerCase(3,2, new Mur(320,240));
    p->changerCase(3,7, new Mur(320,640));
    p->changerCase(3,8, new Mur(320,720));

    p->changerCase(4,1, new Mur(400,160));
    p->changerCase(4,6, new Mur(400,560));
    p->changerCase(4,7, new Mur(400,640));
    p->changerCase(4,8, new Mur(400,720));

    p->changerCase(5,5, new Mur(480,480));
    p->changerCase(5,6, new Mur(480,560));
    p->changerCase(5,7, new Mur(480,640));
    p->changerCase(5,8, new Mur(480,720));

    p->changerCase(6,2, new Mur(560,240));
    p->changerCase(6,4, new Mur(560,400));
    p->changerCase(6,5, new Mur(560,480));
    p->changerCase(6,6, new Mur(560,560));
    p->changerCase(6,7, new Mur(560,640));
    p->changerCase(6,8, new Mur(560,720));

    p->changerCase(7,5, new Mur(640,480));
    p->changerCase(7,6, new Mur(640,560));
    p->changerCase(7,7, new Mur(640,640));
    p->changerCase(7,8, new Mur(640,720));

    //     sol

    p->changerCase(1,5, new Sol(160,480));
    p->changerCase(1,6, new Sol(160,560));
    p->changerCase(1,7, new Sol(160,640));

    p->changerCase(2,4, new Sol(240,400));
    p->changerCase(2,5, new Sol(240,480));
    p->changerCase(2,6, new Cible(240,560));
    p->changerCase(2,7, new Sol(240,640));

    p->changerCase(3,3, new Sol(320,320));
    p->changerCase(3,4, new Sol(320,400));
    p->changerCase(3,5, new Sol(320,480));
    p->changerCase(3,6, new Sol(320,560));

    p->changerCase(4,2, new Sol(400,240));
    p->changerCase(4,3, new Sol(400,320));
    p->changerCase(4,4, new Cible(400,400));
    p->changerCase(4,5, new Sol(400,480));

    p->changerCase(5,1, new Sol(480,160));
    p->changerCase(5,2, new Cible(480,240));
    p->changerCase(5,3, new Sol(480,320));
    p->changerCase(5,4, new Sol(480,400));

    p->changerCase(6,1, new Sol(560,160));
    p->changerCase(6,3, new Sol(560,320));

    p->changerCase(7,1, new Sol(640,160));
    p->changerCase(7,2, new Sol(640,240));
    p->changerCase(7,3, new Sol(640,320));
    p->changerCase(7,4, new Sol(640,400));

    listeCible[0]=Cible(480,240);
    listeCible[1]=Cible(400,400);
    listeCible[2]=Cible(240,560);
}


void MainWindow::paintEvent(QPaintEvent* e) {
    QWidget::paintEvent(e);
    QPainter painter(this);
    if (!jouer){ //si on est pas dans la partie jouer du jeu
        if (regles){ //si on est dans la page regles on affiche que le bouton retour et les regles
            p->dessinerRegles(&painter);
            ui->Bouton_retour->setVisible(true);
            ui->Bouton_regles->setVisible(false);
            ui->Bouton_jouer->setVisible(false);
            ui->Bouton_perso->setVisible(false);
            ui->texte_regles->setVisible(true);
        }
        else if (personnages==0){ //si on est dans la page personnage on affiche que les personnages et le bouton retour
            ui->Bouton_retour->setVisible(true);
            ui->Bouton_regles->setVisible(false);
            ui->Bouton_jouer->setVisible(false);
            ui->Bouton_perso->setVisible(false);
            ui->Bouton_bob->setVisible(true);
            ui->Bouton_patrick->setVisible(true);
            ui->Bouton_carlos->setVisible(true);
            ui->Bouton_gary->setVisible(true);
            ui->Bouton_krabs->setVisible(true);
            ui->Bouton_sandy->setVisible(true);
            ui->Bouton_plancton->setVisible(true);
            ui->Bouton_arthur->setVisible(true);
            ui->Bouton_manon->setVisible(true);
            ui->texte_perso->setVisible(true);
        }
        else{ //si on est sur la page d'accueil on affiche les boutons "jouer", "regles" et "personnages" ainsi que l'image d'acceuil
            ui->texte_niveau->setVisible(false);
            ui->texte_niveau_2->setVisible(false);
            ui->texte_regles->setVisible(false);
            ui->texte_compteur->setVisible(false);
            ui->texte_numCompteur->setVisible(false);
            ui->texte_timer->setVisible(false);
            ui->texte_numTimer->setVisible(false);
            ui->Bouton_suivant->setVisible(false);
            ui->Bouton_recommencer->setVisible(false);
            ui->Bouton_retour->setVisible(false);
            ui->Bouton_regles->setVisible(true);
            ui->Bouton_perso->setVisible(true);
            ui->Bouton_jouer->setVisible(true);
            ui->Bouton_bob->setVisible(false);
            ui->Bouton_patrick->setVisible(false);
            ui->Bouton_carlos->setVisible(false);
            ui->Bouton_gary->setVisible(false);
            ui->Bouton_krabs->setVisible(false);
            ui->Bouton_sandy->setVisible(false);
            ui->Bouton_plancton->setVisible(false);
            ui->Bouton_arthur->setVisible(false);
            ui->Bouton_manon->setVisible(false);
            ui->texte_debloquerNiveau->setVisible(false);
            ui->Bouton_niveau1->setVisible(false);
            ui->Bouton_niveau2->setVisible(false);
            ui->Bouton_niveau3->setVisible(false);
            ui->Bouton_niveau4->setVisible(false);
            ui->Bouton_niveau5->setVisible(false);
            ui->Bouton_niveau6->setVisible(false);
            ui->Bouton_niveau7->setVisible(false);
            ui->Bouton_niveau8->setVisible(false);
            ui->Bouton_niveau9->setVisible(false);
            ui->texte_fin->setVisible(false);
            p->dessinerEntree(&painter);
            ui->texte_perso->setVisible(false);
            timer->stop();

        }
    }
    else{ // si on est dans la partie jouer on affiche que le bouton retour
        ui->Bouton_bob->setVisible(false);
        ui->Bouton_patrick->setVisible(false);
        ui->Bouton_carlos->setVisible(false);
        ui->Bouton_gary->setVisible(false);
        ui->Bouton_krabs->setVisible(false);
        ui->Bouton_sandy->setVisible(false);
        ui->Bouton_plancton->setVisible(false);
        ui->Bouton_arthur->setVisible(false);
        ui->Bouton_manon->setVisible(false);
        ui->Bouton_jouer->setVisible(false);
        ui->Bouton_retour->setVisible(true);
        ui->Bouton_regles->setVisible(false);
        ui->Bouton_perso->setVisible(false);
        if (niveau!=0){ //si on est dans un niveau
            ui->Bouton_niveau1->setVisible(false);
            ui->Bouton_niveau2->setVisible(false);
            ui->Bouton_niveau3->setVisible(false);
            ui->Bouton_niveau4->setVisible(false);
            ui->Bouton_niveau5->setVisible(false);
            ui->Bouton_niveau6->setVisible(false);
            ui->Bouton_niveau7->setVisible(false);
            ui->Bouton_niveau8->setVisible(false);
            ui->Bouton_niveau9->setVisible(false);
            ui->texte_debloquerNiveau->setVisible(false);
            if (!fini) //si le niveau n'est pas gagné on affiche que les boutons "recommencer" et "retour" et le compteur, le timer et le numéro du niveau en cours
            {
                ui->Bouton_suivant->setVisible(false);
                ui->Bouton_recommencer->setVisible(true);
                ui->texte_compteur->setVisible(true);
                ui->texte_timer->setVisible(true);
                ui->texte_numCompteur->setVisible(true);
                ui->texte_numCompteur->setNum(compteur);
                ui->texte_numTimer->setVisible(true);
                ui->texte_numTimer->setNum(nbTimer);
                ui->texte_niveau->setVisible(true);
                ui->texte_niveau_2->setVisible(true);
                ui->texte_niveau_2->setNum(niveau);
                p->dessiner(&painter); //on dessine le plateau
                perso.dessiner(&painter);//on dessine le personnage
                for (int i=0;i<nC;i++) //on dessine le plateau
                    listeCaisse[i].dessiner(&painter);
            }
            else{ //si on a gagné on stoppe le timer, on félicite le joueur et on affiche le bouton "niveau suivant" (sauf si il n'y a plus de niveau)
                timer->stop();
                p->dessinerVictoire(&painter);
                ui->Bouton_recommencer->setVisible(false);
                if (niveau!=9)
                    ui->Bouton_suivant->setVisible(true);
                else{
                   ui->texte_fin->setVisible(true);
                }

                if (niveau==niveauMax)
                    niveauMax=niveau+1;
            }
        }
        else{ //si on est dans la page où on peut choisir le niveau alors on affiche les niveaux
            ui->Bouton_niveau1->setVisible(true);
            ui->Bouton_niveau2->setVisible(true);
            ui->Bouton_niveau3->setVisible(true);
            ui->Bouton_niveau4->setVisible(true);
            ui->Bouton_niveau5->setVisible(true);
            ui->Bouton_niveau6->setVisible(true);
            ui->Bouton_niveau7->setVisible(true);
            ui->Bouton_niveau8->setVisible(true);
            ui->Bouton_niveau9->setVisible(true);

        }
    }
}

void MainWindow::update(){ //on met à jour le timer
    nbTimer++;
    repaint();
}

bool MainWindow::deplacementCaisse(Caisse caisse,int x,int y){ //verifie si on peut déplacer la caisse
    int ic = (caisse.get_x()-10)/80+(x/80)-1; //calcule l'abscisse de l'endroit ou on veut mettre la caisse
    int jc = (caisse.get_y()-10)/80+(y/80)-1; //calcule l'ordonnée de l'endroit ou on veut mettre la caisse
    if (p->getCase(ic,jc)->get_type()==1) //si il y a un mur on renvoit false
        return false;
    else{ //si il y a une autre caisse on renvoit false
        for (int k=0;k<nC;k++){
            if (listeCaisse[k].getCase(ic,jc)==true)
                return false;}
    }
    return true; //sinon on renvoit true

}

bool MainWindow::deplacementV(int x, int y) //verifie si on peut déplacer le personnage
{
    int i = (perso.get_x()-5)/80+(x/80)-1; //on calcule l'abscisse de l'endroit ou on veut mettre le personnage
    int j = (perso.get_y()-5)/80+(y/80)-1; //on calcule l'ordonnée de l'endroit ou on veut mettre le personnage

    if (p->getCase(i,j)->get_type()==1) //si il y a un mur on renvoit false
        return false;
    else
        for (int k=0;k<nC;k++){
            if (listeCaisse[k].getCase(i,j)==true){ //si il y a une caisse on appelle la fonction précedente pour savoir si on peut déplacer la caisse
                if (x>0){
                    if (deplacementCaisse(listeCaisse[k],80,0)==false)
                        return false;
                    else
                        listeCaisse[k].deplacerDe(80,0);
                }
                else if (x<0){
                    if (deplacementCaisse(listeCaisse[k],-80,0)==false)
                        return false;
                    else
                        listeCaisse[k].deplacerDe(-80,0);
                }
                else if (y<0){
                    if (deplacementCaisse(listeCaisse[k],0,-80)==false)
                        return false;
                    else
                        listeCaisse[k].deplacerDe(0,-80);
                }
                else if (y>0){
                    if (deplacementCaisse(listeCaisse[k],0,80)==false)
                        return false;
                    else
                        listeCaisse[k].deplacerDe(0,80);
                }
            }
        }
    return true; //si on peut déplacer le personnage on renvoie true
}



void MainWindow::keyPressEvent (QKeyEvent * event)
{
    if (!fini) //si ce n'est pas fini on peut déplacer le personnage
    //si on peut déplacer le personnage on le fait et on incrémente le compteur
    {
        switch(event -> key())
        {
        case Qt::Key_Left :
            if (deplacementV(-80,0)==true){
                perso.deplacerDe(-80,0);
                compteur++;
            }
            break;
        case Qt::Key_Right :
            if (deplacementV(80,0)==true){
                perso.deplacerDe(80,0);
                compteur++;
            }
            break;
        case Qt::Key_Up:
            if (deplacementV(0,-80)==true){
                perso.deplacerDe(0,-80);
                compteur++;
            }
            break;
        case Qt::Key_Down :
            if (deplacementV(0,80)==true){
                perso.deplacerDe(0,80);
                compteur++;
            }
            break;
        case Qt::Key_Q :
            if (deplacementV(-80,0)==true){
                perso.deplacerDe(-80,0);
                compteur++;
            }
            break;
        case Qt::Key_D :
            if (deplacementV(80,0)==true){
                perso.deplacerDe(80,0);
                compteur++;
            }
            break;
        case Qt::Key_Z:
            if (deplacementV(0,-80)==true){
                perso.deplacerDe(0,-80);
                compteur++;
            }
            break;
        case Qt::Key_S :
            if (deplacementV(0,80)==true){
                perso.deplacerDe(0,80);
                compteur++;
            }
            break;
        }
        fini = gagne(listeCible,listeCaisse); //on teste si on à gagné ou pas
        this->repaint();
    }
}

bool MainWindow::gagne(Cible *listeCible,Caisse *listeCaisse){ //verifie si les caisses sont sur les cibles
    int s=0;
    for (int i=0;i<nC;i++){
        for (int j=0;j<nC;j++){
            if (((listeCaisse[j].get_x()-10)==listeCible[i].get_x())&&((listeCaisse[j].get_y()-10)==listeCible[i].get_y()))
                s+=1;
        }
    }
    if (s==nC) // si il y a nC caisses sur les nC cibles alors l'utilisateur à gagné
        return true;
    return false; // sinon le joueur continue
}




void MainWindow::on_Bouton_jouer_clicked()
{
    jouer=1; //permet d'amener à la page pour choisir le niveau
    this->repaint();
    nbTimer=0; //initialise le timer
}


void MainWindow::on_Bouton_regles_clicked()
{
    regles=true; //permet d'amener à la page règles
    this->repaint();
}


void MainWindow::on_Bouton_suivant_clicked()
{
    niveau+=1; //ajoute 1 au niveau car on passe au niveau suivant
    switch ( niveau ) //en fonction de "niveau" on lance le bon niveau
    {
    case 2:
        niveau2();
        fini = false;
        break;
    case 3:
        niveau3();
        fini = false;
        break;
    case 4:
        niveau4();
        fini = false;
        break;
    case 5:
        niveau5();
        fini = false;
        break;
    case 6:
        niveau6();
        fini = false;
        break;
    case 7:
        niveau7();
        fini = false;
        break;
    case 8:
        niveau8();
        fini = false;
        break;
    case 9:
        niveau9();
        fini = false;
        break;
    }
    this->repaint();
    nbTimer=0; //on initialise le timer
    timer->start(1000);

}


void MainWindow::on_Bouton_recommencer_clicked()
{
    switch ( niveau ) //on fonction de "niveau" on relance le niveau actuel
    {
    case 1:
        niveau1();
        fini = false;
        break;
    case 2:
        niveau2();
        fini = false;
        break;
    case 3:
        niveau3();
        fini = false;
        break;
    case 4:
        niveau4();
        fini = false;
        break;
    case 5:
        niveau5();
        fini = false;
        break;
    case 6:
        niveau6();
        fini = false;
        break;
    case 7:
        niveau7();
        fini = false;
        break;
    case 8:
        niveau8();
        fini = false;
        break;
    case 9:
        niveau9();
        fini = false;
        break;

    }
    this->repaint();
    nbTimer=0; //on initialise le timer

}


void MainWindow::on_Bouton_retour_clicked()
{
    //on réinitialise les paramètres
    regles=false;
    jouer= false;
    fini=false;
    personnages=1;
    niveau=0;
    this->repaint();
}


void MainWindow::on_Bouton_perso_clicked()
{
    personnages=0;//on active la page personnage
    this->repaint();
}

//modifient le personnage
void MainWindow::on_Bouton_bob_clicked()
{
    numPerso=1;
    perso.set_num(1);
    personnages=1;
    this->repaint();

}


void MainWindow::on_Bouton_patrick_clicked()
{
    numPerso=2;
    perso.set_num(2);
    personnages=1;
    this->repaint();
}


void MainWindow::on_Bouton_carlos_clicked()
{
    numPerso=3;
    perso.set_num(3);
    personnages=1;
    this->repaint();
}


void MainWindow::on_Bouton_gary_clicked()
{
    numPerso=4;
    perso.set_num(4);
    personnages=1;
    this->repaint();
}


void MainWindow::on_Bouton_krabs_clicked()
{
    numPerso=5;
    perso.set_num(5);
    personnages=1;
    this->repaint();

}


void MainWindow::on_Bouton_sandy_clicked()
{
    numPerso=6;
    perso.set_num(6);
    personnages=1;
    this->repaint();

}


void MainWindow::on_Bouton_plancton_clicked()
{
    numPerso=7;
    perso.set_num(7);
    personnages=1;
    this->repaint();
}


void MainWindow::on_Bouton_arthur_clicked()
{
    numPerso=8;
    perso.set_num(8);
    personnages=1;
    this->repaint();
}


void MainWindow::on_Bouton_manon_clicked()
{
    numPerso=9;
    perso.set_num(9);
    personnages=1;
    this->repaint();
}

//lance le niveau
void MainWindow::on_Bouton_niveau1_clicked()
{

    niveau1();
    niveau=1;
    this->repaint();
    timer->start(1000);

}

//lance le niveau si le niveau est débloqué
void MainWindow::on_Bouton_niveau2_clicked()
{
    if (niveauMax>1){
        niveau2();
        niveau=2;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);
}


void MainWindow::on_Bouton_niveau3_clicked()
{
    if (niveauMax>2){
        niveau3();
        niveau=3;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);

}


void MainWindow::on_Bouton_niveau4_clicked()
{
    if (niveauMax>3){
        niveau4();
        niveau=4;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);

}



void MainWindow::on_Bouton_niveau5_clicked()
{
    if (niveauMax>4){
        niveau5();
        niveau=5;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);
}


void MainWindow::on_Bouton_niveau6_clicked()
{
    if (niveauMax>5){
        niveau6();
        niveau=6;
        this->repaint();
        timer->start(1000);
    }
    else
    {
        ui->texte_debloquerNiveau->setVisible(true);
    }
}


void MainWindow::on_Bouton_niveau7_clicked()
{
    if (niveauMax>6){
        niveau7();
        niveau=7;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);

}


void MainWindow::on_Bouton_niveau8_clicked()
{
    if (niveauMax>7){
        niveau8();
        niveau=8;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);

}


void MainWindow::on_Bouton_niveau9_clicked()
{
    if (niveauMax>8){
        niveau9();
        niveau=9;
        this->repaint();
        timer->start(1000);
    }
    else
        ui->texte_debloquerNiveau->setVisible(true);
}

