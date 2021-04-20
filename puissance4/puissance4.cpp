#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h"
#include "joueur.h"

using namespace std;

int main() {
	// Initialisation de la grille et la détection
	grille* grilleInstance = new grille();
	detectionWin* detectInstance = new detectionWin();

	//Création des joueurs
	string name;
	char symbol1 = 'x';
	char symbol2 = 'o';
	joueur* player1 = new joueur(symbol1);
	joueur* player2 = new joueur(symbol2);
	

	// Création de la grille
	grilleInstance->setLargeur();
	grilleInstance->setHauteur();
	grilleInstance->setDimension(grilleInstance->getLargeur(), grilleInstance->getHauteur());
	grilleInstance->initialiseGrille();


	vector<char> tab = grilleInstance->getGrille();
	vector<char> newtab;
	int largeur = grilleInstance->getLargeur();
	int dimension = grilleInstance->getDimension();
	int tour = 0;
	int lastPos = 0;
	int choixMode = 0;
	boolean win = false;
	joueur* currentPlayer;

	while (choixMode != 1 && choixMode != 2)
	{
		printf("Veuillez choisir un mode de jeu : \n");
		printf("1 - joueur vs joueur\n");
		printf("2 - joueur vs bot\n");
		cin >> choixMode;
	}
	if (choixMode == 1)
	{
		player1->createUser();
		player2->createUser();
	}
	else if (choixMode == 2)
	{
		player1->createUser();
		player2->createBot();
	}
	while (!win)
	{
		if (tour%2==0)
		{
			currentPlayer = player1;
		}
		else
		{
			currentPlayer = player2;
		}
		newtab = grilleInstance->place(tab, currentPlayer->getSymbol(), currentPlayer->getName(), currentPlayer->getIsBot());
		system("cls");
		tab = newtab;
		lastPos = grilleInstance->getLastPos();
		printf("Le joueur precedent a choisi la case %d\n", lastPos);
		grilleInstance->drawGrille(tab, largeur);
		tour++;
		win = detectInstance->detection(tab, largeur, lastPos, currentPlayer);
		if (win && currentPlayer->getWin() == true)
		{
			printf("Joueur %s remporte la partie\n", currentPlayer->getName().c_str());
		}
		if (tour == dimension) {
			printf("Personne n'a gagne\n");
			printf("Partie terminee\n");
			win = true;

		}
		if (win)
		{
			char replay;
			printf("voulez vous rejouer (y/n) ? ");
			cin >> replay;
			if (replay == 'y') {
				grilleInstance->initialiseGrille();
				tab = grilleInstance->getGrille();
				newtab.clear();
				tour = 0;
				lastPos = 0;
				win = false;
			}
		}
	}
	

	return 0;
}

