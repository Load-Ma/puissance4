#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h"

using namespace std;

int main() {
	
	// cas particulier : 7 large
	//vector<char> tab;
	//for (int i = 0; i < 42; i++)
	//{
	//	tab.push_back(' ');
	//}
	//int posInitiale = 17;

	//tab[posInitiale] = 'x'; // BASE

	//tab[23] = 'x';
	//tab[11] = 'x';
	//tab[5] = 'x';

	//
	//int largeur = 7;

	//detectionWin* detectInstance = new detectionWin();
	//boolean win = detectInstance->detection(tab, largeur, posInitiale);
	//if (win) printf("YOU WON");

	printf("\n");
	printf("\n");
	printf("\n");

	grille* grilleInstance = new grille();
	grilleInstance->setLargeur();
	grilleInstance->setHauteur();
	grilleInstance->setDimension(grilleInstance->getLargeur(), grilleInstance->getHauteur());
	grilleInstance->initialiseGrille();

	vector<char> tab = grilleInstance->getGrille();
	int largeur = grilleInstance->getLargeur();
	
	grilleInstance->drawGrille(tab);

	return 0;
}

