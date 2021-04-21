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

int joueur::getBotDiff() {
	return this->botDiff;
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

void joueur::setBotDiff(int diff) {
	this->botDiff = diff;
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

int joueur::easy(vector<char> tab, int largeur, char symbol) {
	int choix = rand() % (largeur)+0;
	return choix;
}

int joueur::medium(vector<char> tab, int largeur, char symbol, int lastPost) {
	int choix = 0;
	int suite = 1;
	int position = lastPost;
	bool checking = true;

	bool counting = true;
	while (counting)
	{
		//Joue aléatoirement ou joue au dessus d'une colone quand 3pions sont alignés
		choix = rand() % (largeur)+0;
		if (suite == 3) {
			choix = position % largeur;
			break;
		}
		if ((position + largeur >= tab.size()) || tab[position + largeur] != 'x') break;
		position += largeur;
		suite++;
	}
	checking = false;

	return choix;
}