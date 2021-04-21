#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h"
#include "joueur.h"

using namespace std;

int main() {
	// Initialisation de la grille et la d�tection
	grille* grilleInstance = new grille();
	detectionWin* detectInstance = new detectionWin();

	//Cr�ation des joueurs
	string name;
	char symbol1 = 'x';
	char symbol2 = 'o';
	joueur* player1 = new joueur(symbol1);
	joueur* player2 = new joueur(symbol2);
	

	// Cr�ation de la grille
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

	//Choix du mode
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
		int diff = 0;
		//Quand joueur vs bot on demande la difficult�
		while (diff != 1 && diff != 2)
		{
			printf("Choisissez une difficult� : \n");
			printf("1 - easy\n");
			printf("2 - Medium\n");
			cin >> diff;
		}
		player2->setBotDiff(diff);
		
	}
	//La boucle de jeu (tour/win)
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
		// Demande du placement
		newtab = grilleInstance->place(tab, currentPlayer->getSymbol(), currentPlayer->getName(), currentPlayer->getIsBot(), currentPlayer);
		// CLear de la console
		system("cls");
		tab = newtab;
		lastPos = grilleInstance->getLastPos();
		printf("Le joueur precedent a choisi la case %d\n", lastPos);
		//Affichage de la grille
		grilleInstance->drawGrille(tab, largeur);
		tour++;
		win = detectInstance->detection(tab, largeur, lastPos, currentPlayer);
		// Check si victoire d'un joueur
		if (win && currentPlayer->getWin() == true)
		{
			printf("Joueur %s remporte la partie\n", currentPlayer->getName().c_str());
		}
		// Check si grille pleine
		if (tour == dimension) {
			printf("Personne n'a gagne\n");
			printf("Partie terminee\n");
			win = true;

		}
		//condition pour rejouer
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

