#pragma once

class detectionWin
{
public:
	//detectionWin(int* largeur, int tab[]);

	int detection(int tab[]);
	int checkWin(int tab[]);


	void setLargeur(int* largeur);
	int* getLargeur();
	void setTab(int tab[]);
	int* getTab();

private:
	int* largeur;
	int* tab;
};

