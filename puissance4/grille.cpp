#include "grille.h"

void grille::drawGrille(vector<char> tab) {
	for (int i = 0; i < size(tab); i++)
	{
		printf("| %c |", tab[i]);
		if ((i + 1) % 7 == 0) {
			printf("\n");
		}
	}
}

vector<char> grille::place(vector<char> tab, char symbol, string name)
{
	bool verif = true;
	bool asking = true;
	int cpt = 0;
	int choix;

	printf("Tour de %s, veuillez choisir une colonne (entre 0 et %d / 100:exit) :\n", name.c_str(), this->largeur - 1);
	cin >> choix;
	cpt = 0;
	verif = true;
	if (choix == 100) {
		printf("Vous quittez le jeu\n");
		return tab;
	}
	if (choix > this->largeur - 1 || choix < this->largeur)
	{
		printf("Cette colonne n'existe pas\n");
	}
	if (tab[choix] == 'x') {
		printf("La colonne est pleine \n");
	}
	else {
		while (verif == true) {
			if (choix + this->largeur > tab.size() - 1 || tab[choix + this->largeur] == 'x' || tab[choix + this->largeur] == 'o' || cpt == 5) {
				tab[choix] = symbol;
				verif = false;
				this->setLastPos(choix);
			}
			else {
				choix += 7;
				cpt++;
			}
		}
		asking = false;
	}

	return tab;
}

void grille::setHauteur() {
	printf("Veuillez saisir une hauteur pour la grille : ");
	cin >> this->hauteur;
}

void grille::setLargeur() {
	printf("Veuillez saisir une largeur pour la grille : ");
	cin >> this->largeur;
}

void grille::setDimension(int largeur, int hauteur) {
	this->tailletab = largeur * hauteur;
}

void grille::setLastPos(int lastpos) {
	this->lastPos = lastpos;
}

int grille::getLastPos() {
	return this->lastPos;
}

int grille::getHauteur() {
	return this->hauteur;
}

int grille::getLargeur() {
	return this->largeur;
}

int grille::getDimension() {
	return this->tailletab;
}

vector<char>  grille::getGrille() {
	return this->tab;
}

void grille::initialiseGrille() {
	for (int i = 0; i < this->getDimension(); i++) {
		this->tab.push_back(' ');
	}
	this->pionsJoues = 0;
}
