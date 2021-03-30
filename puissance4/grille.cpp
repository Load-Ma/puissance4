#include "grille.h"

using namespace std;

//grille::grille(int nbpion, char nom) {
	//this->nbpion = nbpion;
	//this->nom = nom;
//}

void grille::drawGrille() {
	char tab[42] = { " " };

	for (int i = 0; i < size(tab); i++)
	{
		printf("| %c |", tab[i]);
		if ((i + 1) % 7 == 0) {
			printf("\n");
		}
	}
}

int grille::getNbpion() {
	return this->nbpion;
}

char grille::getNom() {
	return this->nom;
}