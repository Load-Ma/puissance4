#include "detectionWin.h"

//detectionWin::detectionWin(int* largeur, int tab[]) {
// 	this->largeur = largeur;
// 	this->tab = tab;
//}

int detectionWin::detection(char tab[], int largeur, int posInitiale) 
{
	int suite = 1;
	int position = posInitiale;

	int gauche = posInitiale - 1;
	int droite = posInitiale + 1;
	int bas = posInitiale + largeur;
	int haut = posInitiale - largeur;
	int basGauche = posInitiale + (largeur - 1);
	int basDroite = posInitiale + (largeur + 1);
	int hautGauche = posInitiale - (largeur + 1);
	int hautDroite = posInitiale - (largeur - 1);

	int caseVoisine[8] = { 
		posInitiale - 1, // gauche
		posInitiale + 1, // droite
		posInitiale + largeur, // bas
		posInitiale - largeur, // haut
		posInitiale + (largeur - 1), // basGauche
		posInitiale + (largeur + 1), // basDroite
		posInitiale - (largeur + 1), // hautGauche
		posInitiale - (largeur - 1) // hautDroite
	};

	// Check horizontal
	while (true)
	{
		printf("Enter");
		if (!((position+1)%largeur == 0) && (tab[position + 1] == '1' || tab[position + 1] == '2' || tab[position + 1] == '3'))
		{
			printf("OK\n");
			suite++;
			position++;
		}
		else if (!((position) % largeur == 0) && (tab[position - 1] == '1' || tab[position - 1] == '2' || tab[position - 1] == '3'))
		{
			position = posInitiale;
		}
		if (suite == 4)
		{
			printf("Win");
			break;
		}
		Sleep(100);
	}



	return 0;
}

void detectionWin::setLargeur(int* largeur) {
	this->largeur = largeur;
}

int* detectionWin::getLargeur() {
	return this->largeur;
}

void detectionWin::setTab(int tab[]) {
	this->tab = tab;
}

int* detectionWin::getTab() {
	return this->tab;
}