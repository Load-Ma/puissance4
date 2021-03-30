#include "detectionWin.h"

//detectionWin::detectionWin(int* largeur, int tab[]) {
// 	this->largeur = largeur;
// 	this->tab = tab;
//}

int detectionWin::detection(char tab[], int largeur) 
{
	if (tab[18] == 'X')
	{
		printf("Gauche : %c\n", tab[18 - 1]);
		printf("Droite : %c\n", tab[18 + 1]);
		printf("__\n");
		printf("Bas : %c\n", tab[18 - largeur]);
		printf("Haut : %c\n", tab[18 + largeur]);
		printf("__\n");
		printf("Bas gauche : %c\n", tab[18 - (largeur - 1)]);
		printf("Bas droit : %c\n", tab[18 - (largeur + 1)]);
		printf("__\n");
		printf("Haut gauche : %c\n", tab[18 + (largeur - 1)]);
		printf("Haut droit: %c\n", tab[18 + (largeur + 1)]);
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