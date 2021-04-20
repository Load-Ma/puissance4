#include "joueur.h"

joueur::joueur(char pSymbol) {
	this->win = false;
	this->symbol = pSymbol;
}

string joueur::getName() {
	return this->name;
}

bool joueur::getWin() {
	return this->win;
}

char joueur::getSymbol() {
	return this->symbol;
}

void joueur::setName(string name) {
	this->name = name;
}

void joueur::setWin(bool win) {
	this->win = win;
}

void joueur::createUser() {
	string name;
	printf("Veuillez choisir un nom : ");
	cin >> name;
	this->setName(name);
	printf("Votre joueur a ete cree avec succes. Il a pour nom \"%s\" et aura pour signe \"%c\"\n", name.c_str(), this->symbol);
}