#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "joueur.h"

using namespace std;

class detectionWin
{
public:
	//detectionWin(int* largeur, int tab[]);

	int detection(vector<char> tab, int largeur, int posInitiale, joueur* joueur);
	int horizontalDetect(vector<char> tab, int largeur, int posInitiale, char symbol);
	int verticalDetect(vector<char> tab, int largeur, int posInitiale, char symbol);
	int SENODetect(vector<char> tab, int largeur, int posInitiale, char symbol);
	int SONEDetect(vector<char> tab, int largeur, int posInitiale, char symbol);

	void setLargeur(int* largeur);
	int* getLargeur();
	void setTab(int tab[]);
	int* getTab();

private:
	int* largeur;
	int* tab;
};

