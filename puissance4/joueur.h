#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>

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
	void setBotDiff(int diff);
	
	int easy(vector<char> tab, int largeur, char symbol);
	int medium(vector<char> tab, int largeur, char symbol, int lastPos);


	string getName();
	bool getWin();
	char getSymbol();
	bool getIsBot();
	int getBotDiff();

private:
	string name;
	char symbol;
	bool win;
	bool isBot;
	int botDiff;
};

