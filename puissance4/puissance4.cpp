#include <iostream>
#include <vector>
#include "grille.h"
#include "detectionWin.h";

using namespace std;

int main() {
	
	//detectionWin* detectInstance = new detectionWin();
	//detectInstance->setLargeur((int*)largeur);
	//detectInstance->setTab((int*)tab);

	grille* lagrille = new grille();
	lagrille->drawGrille();
	
	return 0;
}

