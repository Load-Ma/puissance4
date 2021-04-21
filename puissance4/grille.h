#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include "joueur.h"

using namespace std;


class grille
{
public:

	void drawGrille(vector<char> tab, int largeur);
	vector<char> place(vector<char> tab, char symbol, string name, bool isBot, joueur* joueur);

	void initialiseGrille();

	void setLargeur();
	void setHauteur();
	void setDimension(int, int);
	void setLastPos(int lastpos);

	int getLastPos();
	int getDimension();
	int getHauteur();
	int getLargeur();
	vector<char> getGrille();


private:
	int lastPos;
	int hauteur;
	int largeur;
	int tailletab;
	int pionsJoues;
	vector <char> tab;
};
