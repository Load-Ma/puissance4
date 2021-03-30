#pragma once
#include <vector>
#include <iostream>

class grille
{
public:
//	grille(int nbpion, char nom);

	int drawGrille();

	int yellowCase();
	int redCase();
	int nullCase();

	int getNbpion();
	char getNom();
private:
	int nbpion;
	char nom;
};

