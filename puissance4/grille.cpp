#include "grille.h"

void grille::drawGrille(vector<char> tab) {
	bool verif = true;
	bool verif2 = true;
	int cpt = 0;
	int choix;

	while (verif2 == true) {
		cout << "Veuillez choisir une colonne (entre 0 et " << this->largeur-1 << ") : " << endl;
		cin >> choix;
		cpt = 0;
		verif = true;
		if (choix == 100) {
			printf("Vous quittez le jeu\n");
			break;
		}
		if (choix > this->largeur-1 || choix < this->largeur)
		{
			printf("Cette colonne n'existe pas\n");
		}
		else if (tab[choix] == 'x') {
			printf("La colonne est pleine \n");
		}
		else {
			while (verif == true) {
				if (choix + this->largeur > tab.size() - 1 || tab[choix + this->largeur] == 'x' || cpt == 5) {
					tab[choix] = 'x';
					verif = false;
					for (int i = 0; i < size(tab); i++)
					{
						printf("| %c |", tab[i]);
						if ((i + 1) % 7 == 0) {
							printf("\n");
						}
					}
				}
				else {
					choix += 7;
					cpt++;
				}
			}
		}
	}
}

void grille::setHauteur() {
	printf("Veuillez saisir une hauteur pour la grille : ");
	cin >> this->hauteur;
}

void grille::setLargeur() {
	printf("Veuillez saisir une largeur pour la grille : ");
	cin >> this->largeur;
}

int grille::getHauteur() {
	return this->hauteur;
}

int grille::getLargeur() {
	return this->largeur;
}

void grille::setDimension(int largeur, int hauteur) {
	this->tailletab = largeur * hauteur;
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
}
