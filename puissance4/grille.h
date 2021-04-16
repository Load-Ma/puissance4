#pragma once
#include <iostream>
#include <vector>


using namespace std;


class grille
{
public:
	void setLargeur();
	void setHauteur();
	void drawGrille();
	void setGrille();
	void setDimension(int, int);
	int getDimension();
	int getHauteur();
	int getLargeur();
	vector<char> getGrille();


private:
	int hauteur;
	int largeur;
	int tailletab;
	vector <char> tab;
};

