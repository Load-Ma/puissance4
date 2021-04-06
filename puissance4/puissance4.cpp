#include <iostream>
#include "Joueur.h"
#include "grille.h"


using namespace std;

int main()
{
    string nom;
    int nbrpion;
    Joueur* France = new Joueur();
    France->setNom();
    nom = France->getNom();
    France->afficherNom(nom);
    France->setPion();
    nbrpion = France->getPion();
    France->afficherPion(nbrpion);

    grille* grilleinstance = new grille();
    grilleinstance->drawGrille();
}

