#include "biblio.h"

void deplacementsurcase(Joueur *moi, listeJoueur *stach, propriete *tabprop,
		int *tabcolor, station *tabgare, compagnies *tabcomp, card *tab1,
		card *tab2, int *pasfini, int des) {
	int cartechance;
	switch (moi->courant->type) {
	default:
		if (moi->courant->type == depart) {
			colorscreen(BNOIR | FGRIS);
			cls();
			psgeDep();
		}
		if (moi->courant->numero == 10) {
			colorscreen(BNOIR | FGRIS);
			cls();
			innVisiteprison();
		}
		if (moi->courant->numero == 20) {
			colorscreen(BNOIR | FGRIS);
			cls();
			innParc();
		}
		break;

	case prison:
		entree_prison(moi);
		break;

	case terrain:
		colorscreen(BNOIR | FGRIS);
		cls();
		innPropriete();
		affiche_prop(&tabprop[moi->courant->place], 10, 13);

		getche();

		if (casepropriete(moi, &tabprop[moi->courant->place], tabcolor)
				== faux) {
			venteEncheresProp(&tabprop[moi->courant->place], stach);
		}
		break;

	case compagnie:
		colorscreen(BNOIR | FGRIS);
		cls();
		innComp();
		affiche_comp(&tabcomp[moi->courant->place], 10, 13);
		if (casecompagnie(moi, &tabcomp[moi->courant->place], des) == faux) {
			venteEncheresComp(&tabcomp[moi->courant->place], stach);
		}
		break;

	case gare:
		colorscreen(BNOIR | FGRIS);
		cls();
		innGare();
		affiche_gare(&tabgare[moi->courant->place], 10, 13);
		if (casegare(moi, &tabgare[moi->courant->place]) == faux) {
			venteEncheresGare(&tabgare[moi->courant->place], stach);
		}
		break;

	case chance:
		colorscreen(BNOIR | FGRIS);
		cls();
		CarteCh();
		cartechance = (int) (NBCARTECHANCE * rnd());
		casespecial(moi, &tab1[cartechance], pasfini, stach);
		getche();
		break;

	case communaute:
		colorscreen(BNOIR | FGRIS);
		cls();
		CaisseC();
		cartechance = (int) (NBCARTECAISSE * rnd());
		casespecial(moi, &tab2[cartechance], pasfini, stach);
		getche();
		break;

	case impot:
		colorscreen(BNOIR | FGRIS);
		cls();
		if (moi->courant->numero == 4) {
			innimpotRev();
			getche();
			if (testliquidite(moi, 20000)) {
				retraitargent(moi, 20000);
			} else {
				moi = byebye(moi);
			}
		}
		if (moi->courant->numero == 38) {
			inntaxeLux();
			getche();
			if (testliquidite(moi, 20000)) {
				retraitargent(moi, 10000);
			} else {
				moi = byebye(moi);
			}
		}
	}
}
