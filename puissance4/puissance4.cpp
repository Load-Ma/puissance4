#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h"

using namespace std;

int main() {
	
	// cas particulier : 7 large
	char tab[42] = { ' ' };
	tab[17] = 'X'; // BASE

	tab[15] = '3';
	tab[16] = '1'; // left

	tab[18] = '1'; // droite
	tab[19] = '2';
	tab[20] = '3';
	//tab[10] = 'T'; // haut
	//tab[24] = 'B'; // bas
	//tab[9] = 'V'; // haut gauche
	//tab[11] = 'W'; // haut droite
	//tab[23] = 'X'; // bas gauche
	//tab[25] = 'Y'; // Bas droite
	
	int largeur = 7;
	int placement = 17;

	detectionWin* detectInstance = new detectionWin();
	detectInstance->detection(tab, largeur, placement);

	printf("\n");
	printf("\n");
	printf("\n");

	grille* grilleInstance = new grille();
	grilleInstance->drawGrille();
	
	return 0;
}

