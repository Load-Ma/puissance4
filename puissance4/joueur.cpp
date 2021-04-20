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

bool joueur::getIsBot() {
	return this->isBot;
}

void joueur::setName(string name) {
	this->name = name;
}

void joueur::setWin(bool win) {
	this->win = win;
}

void joueur::setIsBot(bool isBot) {
	this->isBot = isBot;
}

void joueur::createUser() {
	string name;
	printf("Veuillez choisir un nom (un mot) : ");
	cin >> name;
	this->setName(name);
	printf("Votre joueur a ete cree avec succes. Il a pour nom \"%s\" et aura pour signe \"%c\"\n", name.c_str(), this->symbol);
	this->setIsBot(false);
}

void joueur::createBot() {
	string name = "bot";
	this->setName(name);
	this->setIsBot(true);
}