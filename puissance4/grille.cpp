#include "grille.h"

void grille::drawGrille(vector<char> tab, int largeur) {
	for (int i = 0; i < size(tab); i++)
	{
		printf("| %c |", tab[i]);
		if ((i + 1) % largeur == 0) {
			printf("\n");
		}
	}
}

vector<char> grille::place(vector<char> tab, char symbol, string name, bool isBot)
{
	srand(time(NULL));
	bool verif = true;
	bool asking = true;
	int cpt = 0;
	int choix;

	if (!isBot)
	{
		while (asking)
		{
			printf("Tour de %s, veuillez choisir une colonne (entre 0 et %d / 100:exit) :\n", name.c_str(), this->largeur - 1);
			cin >> choix;
			if (choix > this->largeur - 1 || choix < 0)
			{
				printf("Cette colonne n'existe pas\n");
			}
			else if (tab[choix] == 'x' || tab[choix] == 'o') {
				printf("La colonne est pleine \n");
			}
			else {
				asking = false;
			}
		}
		
	}
	else {
		printf("Le Bot choisi un placement...");
		Sleep(750);
		choix = rand() % (this->largeur - 1) + 0;
	}
	cpt = 0;
	verif = true;
	if (choix == 100) {
		printf("Vous quittez le jeu\n");
		return tab;
	}
	else {
		while (verif == true) {
			if (choix + this->largeur > tab.size() - 1 || tab[choix + this->largeur] == 'x' || tab[choix + this->largeur] == 'o' || cpt == this->getHauteur()-1) {
				tab[choix] = symbol;
				verif = false;
				this->setLastPos(choix);
			}
			else {
				choix += largeur;
				cpt++;
			}
		}
	}

	return tab;
}

void grille::setHauteur() {
	while (this->hauteur < 4)
	{
		printf("Veuillez saisir une hauteur pour la grille (minimum 4) : ");
		cin >> this->hauteur;
		if (this->hauteur < 4)
		{
			printf("La hauteur doit etre au minimum de 4\n");
		}
	}
	
}

void grille::setLargeur() {
	while (this->largeur < 4)
	{
		printf("Veuillez saisir une largeur pour la grille (minimum 4) : ");
		cin >> this->largeur;
		if (this->largeur < 4)
		{
			printf("La largeur doit etre au minimum de 4\n");
		}
	}
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
	tab.clear();
	for (int i = 0; i < this->getDimension(); i++) {
		this->tab.push_back(' ');
	}
	this->pionsJoues = 0;
}
