#include "detectionWin.h"

//detectionWin::detectionWin(int* largeur, int tab[]) {
// 	this->largeur = largeur;
// 	this->tab = tab;
//}

int detectionWin::detection(vector<char> tab, int largeur, int posInitiale, joueur* joueur) {
	boolean win = false;
	win = this->horizontalDetect(tab, largeur, posInitiale, joueur->getSymbol());
	if (win == false) win = this->verticalDetect(tab, largeur, posInitiale, joueur->getSymbol());
	if (win == false) win = this->SENODetect(tab, largeur, posInitiale, joueur->getSymbol());
	if (win == false) win = this->SONEDetect(tab, largeur, posInitiale, joueur->getSymbol());
	if (win)
	{
		joueur->setWin(win);
		cout << joueur->getWin() << endl;
	}
	return win;
}

int detectionWin::horizontalDetect(vector<char> tab, int largeur, int posInitiale, char symbol)
{
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	while (checking)
	{
		boolean counting = true;
		// Si le pion est dans la colonne la plus a gauche je compte en allant vers la droite
		if (position % largeur == 0)
		{
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position + 1) == tab.size() || tab[position + 1] != symbol) break;
				position++;
				suite++;
			}
		}
		// Sinon je me décale le plus a gauche possible, tant qu'il y a un pion de la meme couleur et/ou un colonne
		else
		{
			// Je me décale vers la droite
			while ((position % largeur != 0) && tab[position-1] == symbol)
			{
				position--;
			}
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				// Puis la je compte en allant vers la droite
				if ((position+1) == tab.size() || tab[position + 1] != symbol) break;
				position++;
				suite++;
				if (position % largeur == 0)
				{
					counting = false;
				}
			}
		}
		checking = false;
	}

	return win;
}

int detectionWin::verticalDetect(vector<char> tab, int largeur, int posInitiale, char symbol) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;
	// ici pas besoin de se décaler ou autre
	// Le dernier pion joué est forcement au sommet donc je juste a compter en descendant
	while (checking)
	{
		boolean counting = true;
		while (counting)
		{
			if (suite == 4) {
				win = true;
				break;
			}
			if ((position + largeur >= tab.size()) || tab[position + largeur] != symbol) break;
			position += largeur;
			suite++;
		}
		checking = false;
	}

	return win;
}

int detectionWin::SENODetect(vector<char> tab, int largeur, int posInitiale, char symbol) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	// Comme horizontal, je vais cette fois le plus en bas a droite possible
	while (checking)
	{
		boolean counting = true;
		// Je verifie que le dernier pion ne soit pas deja en bas a gauche au maximum pour éviter de compte pour rien
		if ((position+1) % largeur == 0 || position == tab.size()-1)
		{
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur - 1) < 0 || tab[position - largeur - 1] != symbol) break;
				position = position - largeur - 1;
				suite++;
			}
		}
		else
		{
			// Sinon je descends en bas a droite tant que je peux
			while ((position+1) % largeur != 0 && position+largeur < tab.size() && tab[position + largeur + 1] == symbol)
			{
				position = position + largeur + 1;
			}
			// puis je compte
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur - 1) < 0 || tab[position - largeur - 1] != symbol) break;
				position = position - largeur - 1;
				suite++;
			}
		}
		checking = false;
	}

	return win;
}

int detectionWin::SONEDetect(vector<char> tab, int largeur, int posInitiale, char symbol) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	// Exactement le même principe que pour la diagonale SENO, mais cette fois cic je vais le plus en bas a gauche.

	while (checking)
	{
		boolean counting = true;
		if (position % largeur == 0 || position == tab.size() - 1)
		{
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur + 1) < 0 || (position+1) % largeur == 0 || tab[position - largeur + 1] != symbol) break;
				position = position - largeur + 1;
				suite++;
			}
		}
		else
		{
			while (position % largeur != 0 && position + largeur < tab.size()-1 && tab[position + largeur - 1] == symbol)
			{
				position = position + largeur - 1;
			}
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur + 1) < 0 || tab[position - largeur + 1] != symbol) break;
				position = position - largeur + 1;
				suite++;
			}
		}
		checking = false;
	}

	return win;
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
