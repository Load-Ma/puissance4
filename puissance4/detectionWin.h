#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

class detectionWin
{
public:
	//detectionWin(int* largeur, int tab[]);

	int detection(vector<char> tab, int largeur, int posInitiale);
	int horizontalDetect(vector<char> tab, int largeur, int posInitiale);
	int verticalDetect(vector<char> tab, int largeur, int posInitiale);
	int SENODetect(vector<char> tab, int largeur, int posInitiale);
	int SONEDetect(vector<char> tab, int largeur, int posInitiale);

	void setLargeur(int* largeur);
	int* getLargeur();
	void setTab(int tab[]);
	int* getTab();

private:
	int* largeur;
	int* tab;
};

