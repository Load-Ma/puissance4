#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h";

using namespace std;

int main() {
	
	// cas particulier : 7large
	char tab[42] = { " " };
	tab[18] = 'X'; // BASE
	tab[17] = 'L'; // left
	tab[19] = 'R'; // droite
	tab[25] = 'T'; // haut
	tab[11] = 'B'; // bas
	tab[24] = 'V'; // haut gauche
	tab[26] = 'W'; // haut droite
	tab[10] = 'X'; // bas gauche
	tab[12] = 'Y '; // Bas droite
	
	int largeur = 7;

	detectionWin* detectInstance = new detectionWin();
	detectInstance->detection(tab, largeur);

	grille* grilleInstance = new grille();
	grilleInstance->drawGrille();

	grille* lagrille = new grille();
	lagrille->drawGrille();
	
	return 0;
}

