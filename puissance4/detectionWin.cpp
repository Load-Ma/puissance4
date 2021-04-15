#include "detectionWin.h"

//detectionWin::detectionWin(int* largeur, int tab[]) {
// 	this->largeur = largeur;
// 	this->tab = tab;
//}

int detectionWin::detection(vector<char> tab, int largeur, int posInitiale) {
	boolean win = false;
	win = this->horizontalDetect(tab, largeur, posInitiale);
	if (win == false) win = this->verticalDetect(tab, largeur, posInitiale);
	if (win == false) win = this->SENODetect(tab, largeur, posInitiale);
	if (win == false) win = this->SONEDetect(tab, largeur, posInitiale);
	return win;
}

int detectionWin::horizontalDetect(vector<char> tab, int largeur, int posInitiale)
{
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	while (checking)
	{
		boolean counting = true;
		if (position % largeur == 0)
		{
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position + 1) == tab.size() || tab[position + 1] != 'x') break;
				position++;
				suite++;
			}
		}
		else
		{
			while ((position % largeur != 0) && tab[position-1] == 'x')
			{
				position--;
			}
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position+1) == tab.size() || tab[position + 1] != 'x') break;
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

int detectionWin::verticalDetect(vector<char> tab, int largeur, int posInitiale) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	while (checking)
	{
		boolean counting = true;
		while (counting)
		{
			if (suite == 4) {
				win = true;
				break;
			}
			if ((position + largeur >= tab.size()) || tab[position + largeur] != 'x') break;
			position += largeur;
			suite++;
		}
		checking = false;
	}

	return win;
}

int detectionWin::SENODetect(vector<char> tab, int largeur, int posInitiale) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

	while (checking)
	{
		boolean counting = true;
		if ((position+1) % largeur == 0 || position == tab.size()-1)
		{
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur - 1) < 0 || tab[position - largeur - 1] != 'x') break;
				position = position - largeur - 1;
				suite++;
			}
		}
		else
		{
			while ((position+1) % largeur != 0 && position+largeur < tab.size() && tab[position + largeur + 1] == 'x')
			{
				position = position + largeur + 1;
			}
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur - 1) < 0 || tab[position - largeur - 1] != 'x') break;
				position = position - largeur - 1;
				suite++;
			}
		}
		checking = false;
	}

	return win;
}

int detectionWin::SONEDetect(vector<char> tab, int largeur, int posInitiale) {
	boolean win = false;
	int suite = 1;
	int position = posInitiale;
	boolean checking = true;

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
				if ((position - largeur + 1) < 0 || (position+1) % largeur == 0 || tab[position - largeur + 1] != 'x') break;
				position = position - largeur + 1;
				suite++;
			}
		}
		else
		{
			while (position % largeur != 0 && position + largeur < tab.size()-1 && tab[position + largeur - 1] == 'x')
			{
				position = position + largeur - 1;
			}
			while (counting)
			{
				if (suite == 4) {
					win = true;
					break;
				}
				if ((position - largeur + 1) < 0 || tab[position - largeur + 1] != 'x') break;
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
