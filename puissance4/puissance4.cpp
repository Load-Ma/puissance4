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
	printf("Entrer un nom pour le joueur 1 : ");
	cin >> name;
	player1->setName(name);
	printf("Entrer un nom pour le joueur 2 : ");
	cin >> name;
	player2->setName(name);
	

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
	boolean win = false;
	joueur* currentPlayer;


	while (!win)
	{
		printf("%d tour\n", tour);
		if (tour%2==0)
		{
			printf("CHECK\n");
			currentPlayer = player1;
		}
		else
		{
			printf("CHECK 2\n");
			currentPlayer = player2;
		}
		newtab = grilleInstance->place(tab, currentPlayer->getSymbol(), currentPlayer->getName());
		if (newtab != tab)
		{
			printf("CHECK 3\n");
			system("cls");
			tab = newtab;
			lastPos = grilleInstance->getLastPos();
			grilleInstance->drawGrille(tab);
			tour++;
			win = detectInstance->detection(tab, largeur, lastPos, currentPlayer);
			if (win && currentPlayer->getWin() == true)
			{
				printf("Joueur %s remporte la partie\n", currentPlayer->getName().c_str());
			}
		}
		else if (tour == dimension)
		{
			printf("Personne n'a gagné");
			break;
		}
		else {
			printf("Partie terminee");
			break;
		}
	}
	

	return 0;
}

