#include "biblio.h"

void gestionmaison(Joueur *slayer, propriete *tabprop, int *tabcolor) {
	menu choix;
	initmenu(&choix, "monopoly.dat", "*menumaison*");
	switch (menubox(&choix)) {
	case 0:
		break;
	case 1:
		achatmaison(slayer, tabprop, tabcolor);
		break;
	case 2:
		ventemaison(slayer, tabprop);
		break;
	}
}

int menutour(Joueur *slayer, listeJoueur *stach, propriete *tabprop,
		int *tabcolor, station *tabstat, compagnies *tabcomp, int *replay) {
	menu choice;
	int choum, choix;
	initmenu(&choice, "monopoly.dat", "*menutour*");
	choum = 1;
	while (choum == 1) {
		//effacerPartieEcranMono(10);

		ecran(slayer);
		/*placeCurseur(34,1);
		 printf("Tour a %s",slayer->nom);
		 placeCurseur(34,2);
		 printf("Case actuelle: %d",slayer->courant->numero);*/
		choix = menubox(&choice);
		switch (choix) {
		case 0:
			choum = 0;
			break;
		case 1:
			voirpossession(slayer, tabprop, tabcolor, tabstat, tabcomp);
			break;
		case 2:
			gestionmaison(slayer, tabprop, tabcolor);
			break;
		case 3:
			echange(slayer, stach, tabprop, tabstat, tabcomp);
			break;
		case 4:
			slayer = byebye(slayer);
			*replay = 1;
			return vrai;
			break;
		case 5:
			sauvegarde(slayer);
			break;
		case 6:
			return faux;
		}
	}
	return vrai;
}

void voirpossession(Joueur *slayer, propriete *tabprop, int *tabcolor,
		station *tabstat, compagnies *tabcomp) {
	menu choix;
	initmenu(&choix, "monopoly.dat", "*menuechange*");

	colorscreen(BNOIR | FGRIS);
	cls();
	ecran(slayer);
	//box(BNOIR,0,0,33,22);
	switch (menubox(&choix)) {
	case 0:
		break;
	case 1:
		visuelpropriete(slayer, tabprop);
		break;
	case 2:
		visuelgare(slayer, tabstat);
		break;
	case 3:
		visuelcomp(slayer, tabcomp);
		break;
	}
}
