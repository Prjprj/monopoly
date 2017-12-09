#include "biblio.h"

void winner(void){
	colorscreen(BNOIR|FGRIS);
	cls();
	affiche_nom_joli("LE GAGNANT",2,2,vrai);
	affiche_nom_joli("EST",2,8,vrai);
	affiche_nom_joli(monoplayers.player1->nom,2,14,vrai);
	getche();
	cls();
}

