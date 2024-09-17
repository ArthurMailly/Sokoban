#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>

#include "plateau.h"
#include "personnage.h"
#include "caisse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Bouton_jouer_clicked(); //permet d'acceder aux niveaux
    void on_Bouton_regles_clicked(); //permet d'acceder aux règles
    void on_Bouton_suivant_clicked(); //permet d'acceder au niveau suivant
    void on_Bouton_recommencer_clicked(); //permet de recommencer le niveau
    void on_Bouton_retour_clicked(); //permet de retourner à la page d'acceuil
    void on_Bouton_perso_clicked(); //permet d'acceder à la page des personnages
    // les boutons suivants permettent de choisir le personnage
    void on_Bouton_bob_clicked();
    void on_Bouton_patrick_clicked();
    void on_Bouton_carlos_clicked();
    void on_Bouton_gary_clicked();
    void on_Bouton_krabs_clicked();
    void on_Bouton_sandy_clicked();
    void on_Bouton_plancton_clicked();
    void on_Bouton_arthur_clicked();
    void on_Bouton_manon_clicked();
    void update(); //met à jour le timer
    //les boutons suivants permettent de choisir le niveau
    void on_Bouton_niveau1_clicked();
    void on_Bouton_niveau2_clicked();
    void on_Bouton_niveau3_clicked();
    void on_Bouton_niveau4_clicked();
    void on_Bouton_niveau5_clicked();
    void on_Bouton_niveau6_clicked();
    void on_Bouton_niveau7_clicked();
    void on_Bouton_niveau8_clicked();
    void on_Bouton_niveau9_clicked();

private:
    Ui::MainWindow *ui;

    QTimer* timer;
    Plateau *p;
    Personnage perso;
    Caisse* listeCaisse;
    Cible* listeCible;
    int nC; //nbre caisse
    bool fini; //1 si niveau fini
    bool jouer; // si le bouton jouer est cliqué
    int niveauMax; // niveau maximum débloqué
    bool regles; //1 si page regles ouverte
    int niveau; // niveau en cours
    int personnages; // 1 si dans page personnages
    int numPerso; //numero du perso
    int compteur; // compteur
    int nbTimer;  //timer

    void keyPressEvent ( QKeyEvent * event);
    bool deplacementV(int x, int y); //valide (ou non) le déplacement
    void paintEvent(QPaintEvent* e);
    bool deplacementCaisse(Caisse caisse, int x,int y); //valide (ou non) le déplacement de la caisse
    bool gagne(Cible *listeCible, Caisse *listeCaisse); //valide (ou non) la fin du niveau

    //permettent de lancer le niveau:
    void niveau1();
    void niveau2();
    void niveau3();
    void niveau4();
    void niveau5();
    void niveau6();
    void niveau7();
    void niveau8();
    void niveau9();
};
#endif // MAINWINDOW_H
