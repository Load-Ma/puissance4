#pragma once
#include <iostream>

using namespace std;


class Joueur
{
private :

	int nbrpion;
	string nom;

public :

	void afficherNom(string);
	void afficherPion(int);
	string getNom();
	int getPion();
	void setNom();
	void setPion();


};

