#include "Joueur.h"


using namespace std;


void Joueur::afficherNom(string nomjoueur) {
	cout << "Votre nom est : " << nomjoueur << endl;
}

void Joueur::afficherPion(int pion) {
	cout << "Vous avez : " << pion << "pion" << endl;
}

string Joueur::getNom() {
	return this->nom;
}

int Joueur::getPion() {
	return this->nbrpion;
}

void Joueur::setNom() {
	cout << "Veuillez saisir un nom : " << endl;
	cin >> this->nom;
}

void Joueur::setPion() {
	this->nbrpion = 21;
}

int Joueur::getChoixJoueur() {
	return this->choix;
}

int Joueur::choixJoueur() {
	cout << "Veuillez saisir une colonne : ";
	return this->choix;
}