#pragma once
#include <vector>
#include <iostream>

class grille
{
public:
	//grille(int nbpion, char nom);

	void drawGrille();

	int getNbpion();
	char getNom();
private:
	int nbpion;
	char nom;
};

