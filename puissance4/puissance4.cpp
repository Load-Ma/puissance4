#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h";

using namespace std;

int main() {
	
	//detectionWin* detectInstance = new detectionWin();
	//detectInstance->setLargeur((int*)largeur);
	//detectInstance->setTab((int*)tab);

	char tab[42] = { " " };

	for (int i = 0; i < size(tab); i++)
	{
		printf("| %c ", tab[i]);
		if ((i+1)%7 == 0 && i>0) {
			printf("\n");
		}
	}
	return 0;
}

