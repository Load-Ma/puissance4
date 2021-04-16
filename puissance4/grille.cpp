#include "grille.h"



void grille::drawGrille() {
	bool verif = true;
	bool verif2 = true;
	int cpt = 0;
	int choix;

	printf("checkdrawgrille");
	printf("%d", verif2);
	while (verif2 == true) {
		cout << "Veuillez choisir une colonne : " << endl;
		cin >> choix;
		cpt = 0;
		verif = true;
		printf("check3");
		if (choix == 9) {
			printf("check0");
			break;
		}
		if (this->tab[choix] == 'x') {
			printf("La colonne est pleine \n");
			printf("check1");
		}
		else {
			while (verif == true) {
				printf("check4");
				if ((this->tab[choix + this->largeur] == 'x') || cpt == 5) {
					printf("check5");
					this->tab[choix] = 'x';
					verif = false;
					for (int i = 0; i < size(this->tab); i++)
					{
						printf("| %c ", this->tab[i]);
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

void grille::setHauteur() {
	printf("Veuillez saisir une hauteur pour la grille : ");
	cin >> this->hauteur;
}

void grille::setLargeur() {
	printf("Veuillez saisir une largeur pour la grille : ");
	cin >> this->largeur;
}

int grille::getHauteur() {
	return this->hauteur;
}

int grille::getLargeur() {
	return this->largeur;
}

void grille::setDimension(int largeur, int hauteur) {
	this->tailletab = largeur * hauteur;
}

int grille::getDimension() {
	return this->tailletab;
}

vector<char>  grille::getGrille() {
	return this->tab;
}


void grille::setGrille() {
	for (int i = 0; i < this->getDimension(); i++) {
		this->tab.push_back(' ');
	}
}