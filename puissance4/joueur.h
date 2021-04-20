#pragma once
#include <iostream>

using namespace std;

class joueur
{
public:
	joueur(char symbol);

	void createUser();
	void setName(string name);	
	void setWin(bool win);

	string getName();
	bool getWin();
	char getSymbol();

private:
	string name;
	char symbol;
	bool win;
};

