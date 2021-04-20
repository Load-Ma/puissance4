#pragma once
#include <iostream>

using namespace std;

class joueur
{
public:
	joueur(char symbol);

	void createUser();
	void createBot();
	void setName(string name);	
	void setWin(bool win);
	void setIsBot(bool isBot);

	string getName();
	bool getWin();
	char getSymbol();
	bool getIsBot();

private:
	string name;
	char symbol;
	bool win;
	bool isBot;
};

