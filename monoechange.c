#include"biblio.h"
void echange(Joueur *slayer, listeJoueur *stach, propriete *tabprop,
		station *tabstat, compagnies *tabcomp) {
	menu choice, choix;
	int moi;
	stich toi;
	initmenuJoueur(&choice, stach);
	locate("Avec quel joueur?", 8, 4);
	choice.y = 6;
	moi = menubox(&choice);
	if (moi == 0) {
		return;
	}
	toi = playerNumber(stach, moi - 1);
	initmenu(&choix, "monopoly.dat", "*menuechange*");
	colorscreen(BNOIR | FGRIS);
	cls();
	box(BBLEU | FBLANC, 0, 0, 80, 0);
	locate("Vente", 38, 0);
	switch (menubox(&choix)) {
	case 0:
		break;
	case 1:
		Venteprop(slayer, toi, tabprop);
		break;
	case 2:
		Ventegare(slayer, toi, tabstat);
		break;
	case 3:
		Ventecomp(slayer, toi, tabcomp);
		break;
	}
}

void Venteprop(Joueur *slayer1, Joueur *slayer2, propriete *tab) {
	propriete *hello;
	menu choice;
	int prix;
	box(BNOIR, 0, 1, 80, 25);
	hello = returnprop(slayer1, tab);
	if (hello != NULL) {
		if (hello->nbmaison == 0) {
			box(BNOIR, 0, 1, 80, 25);
			prix = dialogIntBox("Prix:", 65, 6, 10, BROUGE, BBLEU | FBLANC);
			if ((testliquidite(slayer2, prix))) {
				initmenu(&choice, "monopoly.dat", "menuachat");
				if (menubox(&choice) == 1) {
					printf("Joueur %s a acquis %s", slayer2->nom, hello->nom);
					gainargent(slayer1, prix);
					retraitargent(slayer2, prix);
					perteprop(slayer1, hello);
					acquisprop(slayer2, hello);
					getche();
				}
			}
		} else {
			printf("Il faut vendre toutes vos maisons...!!!");
			getche();
		}
	}
}

void Ventegare(Joueur *slayer1, Joueur *slayer2, station *tab) {
	station *hello;
	menu choice;
	int prix;
	box(BNOIR, 0, 1, 80, 25);
	hello = returngare(slayer1, tab);
	if (hello != NULL) {
		box(BNOIR, 0, 1, 80, 25);
		prix = dialogIntBox("Prix:", 65, 6, 10, BROUGE, BBLEU | FBLANC);
		if ((testliquidite(slayer2, prix))) {
			initmenu(&choice, "monopoly.dat", "menuachat");
			if (menubox(&choice) == 1) {
				printf("Joueur %s a acquis %s", slayer2->nom, hello->nom);
				gainargent(slayer1, prix);
				retraitargent(slayer2, prix);
				pertegare(slayer1, hello);
				acquisgare(slayer2, hello);
				getche();
			}
		}
	}
}

void Ventecomp(Joueur *slayer1, Joueur *slayer2, compagnies *tab) {
	compagnies *hello;
	menu choice;
	int prix;
	box(BNOIR, 0, 1, 80, 25);
	hello = returncomp(slayer1, tab);
	if (hello != NULL) {
		box(BNOIR, 0, 1, 80, 25);
		prix = dialogIntBox("Prix:", 65, 6, 10, BROUGE, BBLEU | FBLANC);
		if ((testliquidite(slayer2, prix))) {
			initmenu(&choice, "monopoly.dat", "menuachat");
			if (menubox(&choice) == 1) {
				printf("Joueur %s a acquis %s", slayer2->nom, hello->nom);
				gainargent(slayer1, prix);
				retraitargent(slayer2, prix);
				pertecomp(slayer1, hello);
				acquiscomp(slayer2, hello);
				getche();
			}
		}
	}
}
