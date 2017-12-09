#include"biblio.h"
void casespecial(Joueur *slayer, card *tab, int *play, listeJoueur *stuch){
	int i;
	stich moi;
    locate (tab->intitule, 25,22);
	switch (tab->type){
		case positif:
			gainargent(slayer,tab->parametre);
		break;

		case negatif:
			if (testliquidite(slayer,tab->parametre)){
				retraitargent(slayer,tab->parametre);
			}
			else{
				slayer = byebye(slayer);
			}
		break;

		case avance:
			deplacementde(tab->parametre,slayer,tab->dep);
			*play = 1;
		break;

		case recul:
			deplacementde(NBCASESPLATEAU-(tab->parametre%NBCASESPLATEAU),slayer,tab->dep);
			*play = 1;
		break;

		case avancecase:
			if (slayer->courant->numero <= tab->parametre){
				deplacementde(tab->parametre-slayer->courant->numero,slayer,tab->dep);
			}
			else{
				deplacementde(NBCASESPLATEAU+tab->parametre-slayer->courant->numero,slayer,tab->dep);
			}
			*play = 1;
		break;

		case anniversaire:
			moi = stuch->player1;
			for (i=0; i<stuch->nombrejoueur;i++){
				if (moi->numero != slayer->numero){
					if (testliquidite(moi,tab->parametre)==vrai){
						retraitargent(moi,tab->parametre);
					}
					else{
						moi = byebye(moi);
					}
				}
				moi = moi->suivant;
			}
		break;
	}
}