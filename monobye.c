#include "biblio.h"

Joueur* byebye(Joueur *slayer) {
	int i;
	stich toi;
	colorscreen(BNOIR | BGRIS);
	cls();
	/*placeCurseur(34,17);
	 printf("Vous avez perdu");
	 placeCurseur(34,18);
	 printf("Au revoir!!");*/
	perdu();
	getche();
	for (i = 0; i < NBPROPRIETE; i++) {
		if (tableaupropriete[i].proprietaire != NULL
				&& tableaupropriete[i].proprietaire->numero == slayer->numero) {
			tableaupropriete[i].proprietaire = NULL;
			tableaupropriete[i].nbmaison = 0;
		}
	}
	for (i = 0; i < NBGARES; i++) {
		if (tableaugare[i].proprietaire != NULL
				&& tableaugare[i].proprietaire->numero == slayer->numero) {
			tableaugare[i].proprietaire = NULL;
		}
	}
	for (i = 0; i < NBCOMPAGNIE; i++) {
		if (tableaucompagnie[i].proprietaire != NULL
				&& tableaucompagnie[i].proprietaire->numero == slayer->numero) {
			tableaucompagnie[i].proprietaire = NULL;
		}
	}
	if (slayer->numero == 0) {
		monoplayers.player1 = slayer->suivant;
	}
	toi = slayer;
	for (i = slayer->numero; i < monoplayers.nombrejoueur; i++) {
		toi->numero--;
		toi = toi->suivant;
	}
	toi = joueurprecedent(slayer, &monoplayers);
	//free(toi->suivant);
	toi->suivant = slayer->suivant;
	monoplayers.nombrejoueur--;
	return toi;
}

