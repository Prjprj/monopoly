#include"biblio.h"

void achatmaison(Joueur *slayer, propriete *tab, int *tab2){
	int i;
	propriete *hello;
	hello =	returnprop(slayer, tab);
	if (hello != NULL){
		if (hello->proprietaire->possession.propriete[hello->zone] >= tab2[hello->zone]){
			if (hello->nbmaison < 4){
				if (testliquidite(slayer, hello->prixMaison)){
					placeCurseur(34,20);
					printf("Vous venez d'acheter 1 maison sur %s",hello->nom);
					retraitargent(slayer, hello->prixMaison);
					for (i=0;i<NBPROPRIETE;i++){
						if (strcmp(hello->nom,tab[i].nom)==0){
							break;
						}
					}
					tab[i].nbmaison++;
				}
				else {
					placeCurseur(34,20);
					printf("Peut pas!!!");
				}
			}
			else{
				placeCurseur(34,21);
				printf("Vous avez deja 4 maisons!!!");
			}
		}
		else{
			placeCurseur(34,22);
			printf("Vous n'avez pas le monopole de la couleur!!!");
		}
	}
	getche();
}

void ventemaison(Joueur *slayer, propriete *tab){
	int i;
	propriete *hello;
	hello =	returnprop(slayer, tab);
	if (hello != NULL){
		if (hello->nbmaison > 0){
			placeCurseur(34,20);
			printf("Vous venez de vendre une maison...");
			gainargent(slayer, hello->prixMaison);
			for (i=0;i<NBPROPRIETE;i++){
				if (strcmp(hello->nom,tab[i].nom)==0){
					break;
				}
			}
			tab[i].nbmaison--;
		}
		else{
			placeCurseur(34,20);
			printf("Vous n'avez pas de maisons!!!");
		}
	}
	getche();
}