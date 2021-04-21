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

vector<char> grille::place(vector<char> tab, char symbol, string name, bool isBot, joueur* joueur)
{
	srand(time(NULL));
	bool verif = true;
	bool asking = true;
	int cpt = 0;
	int choix;

	// Si c'est un joueur on demande ou il veut jouer
	if (!isBot)
	{
		while (asking)
		{
			printf("Tour de %s, veuillez choisir une colonne (entre 0 et %d / 100:exit) :\n", name.c_str(), this->largeur - 1);
			cin >> choix;
			//Verif si colonne pleine ou inexistante
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
	// Sinon c'est un bot on le fait jouer automatiquement 
	else {
		srand(time(NULL));
		printf("Le Bot choisi un placement...");
		// On fait un sleep pour que le joueur voit que le bot joue (sinon c'est trop rapide)
		Sleep(750);
		//on récupère la difficulté
		int diff = joueur->getBotDiff();
		// On fait jouer en fonction de la difficulté récupérée
		switch (diff)
		{
		default:
			break;
		case 1:
			choix = joueur->easy(tab, this->largeur, symbol);
			while (tab[choix] == 'x' || tab[choix] == 'o') {
				choix = joueur->easy(tab, this->largeur, symbol);
			}
			break;
		case 2:
			choix = joueur->medium(tab, this->largeur, symbol, this->getLastPos());
			while (tab[choix] == 'x' || tab[choix] == 'o') {
				choix = joueur->medium(tab, this->largeur, symbol, this->getLastPos());
			}
			break;
			break;
		}
	}
	cpt = 0;
	verif = true;
	if (choix == 100) {
		printf("Vous quittez le jeu\n");
		return tab;
	}
	else {
		// Ici on fait en sorte que le pion aille le plus bas possible
		while (verif == true) {
			if (choix + this->largeur > tab.size() - 1 || tab[choix + this->largeur] == 'x' || tab[choix + this->largeur] == 'o' || cpt == this->getHauteur()-1) {
				tab[choix] = joueur->getSymbol();
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
	// Définition de la hauteur
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
	// Définition de la largeur
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
	// Réinitialisation de la grille
	tab.clear();
	// Ajout de chaque case
	for (int i = 0; i < this->getDimension(); i++) {
		this->tab.push_back(' ');
	}
	this->pionsJoues = 0;
}
