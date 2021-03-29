#include "grille.h"

using namespace std;

grille::grille(int nbpion, char nom) {
	this->nbpion = nbpion;
	this->nom = nom;
}

int grille::drawGrille() {
	printf("Grille\n\n");

	return 0;
}

int grille::getNbpion() {
	return this->nbpion;
}

char grille::getNom() {
	return this->nom;
}