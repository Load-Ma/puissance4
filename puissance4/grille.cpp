#include "grille.h"


void grille::drawGrille() {
	char tab[42] = { ' ' };
	bool verif = true;
	bool verif2 = true;

	int cpt = 0;
	int choix;

	while (verif2) {
		cin >> choix;
		cpt = 0;
		verif = true;
		if (choix == 9) {
			break;
		}
		if (tab[choix] == 'x') {
			printf("full");
		}
		else {
			while (verif) {
				if (tab[choix + 7] == 'x' || cpt == 5) {
					tab[choix] = 'x';
					verif = false;
					for (int i = 0; i < size(tab); i++)
					{
						printf("| %c ", tab[i]);
						if ((i + 1) % 7 == 0) {
							printf("\n");
						}
					}
				}
				else {
					choix += 7;
					cpt++;
				}
			}
		}
	}
}
