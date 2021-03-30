#include "grille.h"

using namespace std;

//grille::grille(int nbpion, char nom) {
//	this->nbpion = nbpion;
//	this->nom = nom;
//}

int grille::drawGrille() {
    char tab[42] = { " " };

    int u = 2;
    while (u < size(tab)) {
        if (tab[u] == ' ') {
            tab[u] = 'x';
            u = size(tab);
        }
        u = u + 7;
    }
    for (int i = 0; i < size(tab); i++)
    {
        printf("| %c ", tab[i]);
        if ((i + 1) % 7 == 0 ) {
            printf("\n");
        }
    }


    return 0;
}

int grille::getNbpion() {
	return this->nbpion;
}

char grille::getNom() {
	return this->nom;
}