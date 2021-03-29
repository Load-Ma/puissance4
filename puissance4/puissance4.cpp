#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h";

using namespace std;

int main() {
	
	//detectionWin* detectInstance = new detectionWin();
	//detectInstance->setLargeur((int*)largeur);
	//detectInstance->setTab((int*)tab);

	int largeur= 7;
	int* tab[21] = { 0 };

	printf("%d \n", sizeof(*tab));

	for (int i(0); i<sizeof(tab); i++)
	{
		//tab[i] = 0;
		printf("%p", *tab[i]);
	}

	return 0;
}

