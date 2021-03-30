#pragma once
#include <iostream>

class detectionWin
{
public:
	//detectionWin(int* largeur, int tab[]);

	int detection(char tab[], int largeur);

	void setLargeur(int* largeur);
	int* getLargeur();
	void setTab(int tab[]);
	int* getTab();

private:
	int* largeur;
	int* tab;
};

