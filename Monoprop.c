#include"biblio.h"

booleen achatpropriete(Joueur *slayer, propriete *prop) {
	if (testliquidite(slayer, prop->prix)) {
		retraitargent(slayer, prop->prix);
		acquisprop(slayer, prop);
		colorlocate("Vous avez acquis la propriete", 45, 16, FGRIS);
		getche();

		return vrai;
	} else {
		return faux;
	}

}

void paiementloyerprop(Joueur *slayer, propriete *prop, int *tab2) {
	int toutnu;
	toutnu = determineloyer(prop, tab2);

	if (testliquidite(slayer, toutnu)) {

		locate("Paiement du loyer...", 45, 16);
		getche();
		retraitargent(slayer, toutnu);
		gainargent(prop->proprietaire, toutnu);

	} else {
		slayer = byebye(slayer);
	}
}

int determineloyer(propriete *prop, int *tab2) {
	int loyer;
	loyer = prop->loyerNu;
	if (prop->proprietaire->possession.propriete[prop->zone]
			>= tab2[prop->zone]) {
		locate("A toutes les couleurs!!", 45, 14);
		loyer = prop->loyerNu * 2;
	}
	if (prop->nbmaison != 0) {
		loyer = prop->loyerMaison[prop->nbmaison - 1];
	}
	return loyer;

}

booleen casepropriete(Joueur *slayer, propriete *tab, int *tab2) {
	menu choice;
	if (tab->proprietaire == NULL) {
		locate("Voulez-vous acheter?", 52, 14);
		initmenu(&choice, "monopoly.dat", "menuachat");
		if (menubox(&choice) == 1) {
			box(BNOIR, 52, 14, 20, 9);
			if (achatpropriete(slayer, tab) == faux) {
				locate("Vous n'avez pas assez!", 45, 16);
			}
			return vrai;
		} else {
			return faux;
		}
	} else {
		paiementloyerprop(slayer, tab, tab2);
		return vrai;
	}
}

void acquisprop(Joueur *slayer, propriete *prop) {
	prop->proprietaire = slayer;
	slayer->possession.propriete[prop->zone]++;
}

void perteprop(Joueur *slayer, propriete *prop) {
	prop->proprietaire = NULL;
	slayer->possession.propriete[prop->zone]--;

}

void venteEncheresProp(propriete *prop, listeJoueur *stach) { // sans commentaire
	int prix, proposition, possesseur, endless, test;
	stich toi;
	/* initialisation du menu... */
	menu choice;
	char chaine[80];
	initmenuJoueur(&choice, stach);
	choice.x = 30;
	choice.y = 8;
	colorscreen(BNOIR | FGRIS);
	cls();
	box(BJAUNE | FROUGE, 0, 0, 80, 0);
	locate("Vente aux Encheres", 25, 0);
	getche();
	endless = faux;
	prix = prop->prix;
	possesseur = -1;
	while (endless == faux) {
		colorscreen(BNOIR | FGRIS);
		cls();
		box(BJAUNE | FROUGE, 0, 0, 80, 0);
		locate("Vente aux Encheres", 25, 0);
		locate("Mise a prix:", 25, 4);
		sprintf(chaine, "%d", prix);
		locate(chaine, 40, 4);
		locate("Qui augmente les encheres?", 24, 6);
		test = menubox(&choice);
		if (test == 0) {
			endless = vrai;
			if (possesseur != -1) {
				toi = playerNumber(stach, possesseur);
				retraitargent(toi, prix);
				acquisprop(toi, prop);
				locate("Propriete Acquise", 44, 10);
				getche();
			} else {
				box(BNOIR, 0, 1, 80, 25);
				locate("Pas de Vente!!!", 30, 10);
				getche();
			}
		} else {
			toi = playerNumber(stach, test - 1);

			proposition = dialogIntBox("Combien voulez-vous proposer?", 44, 10,
					31, BROUGE, BBLEU | FJAUNE);
			if (testliquidite(toi, prix) && proposition > prix) {
				prix = proposition;
				possesseur = test - 1;
			} else {
				locate("Achat impossible!!", 48, 12);
				getche();
			}
		}
	}
}

int nbproppossede(Joueur *slayer, propriete *tab) {
	int i, nb;
	nb = 0;
	for (i = 0; i < NBPROPRIETE; i++) {
		if (tab[i].proprietaire != NULL
				&& tab[i].proprietaire->numero == slayer->numero) {
			nb++;
		}
	}
	return nb;
}

void visuelpropriete(Joueur *slayer, propriete *tab) {
	propriete *hello;
	hello = returnprop(slayer, tab);
	if (hello != NULL) {

		affiche_prop(hello, 35, 8);
		getche();
	}
}

propriete* returnprop(Joueur *slayer, propriete *tab) {
	int i, j, k;
	menum choice;
	propriete *tabprop;
	propriete *the_one;
	if (nbproppossede(slayer, tab) == 0) {
		the_one = NULL;
	} else {
		tabprop = malloc(nbproppossede(slayer, tab) * sizeof(propriete));
		choice.taille = nbproppossede(slayer, tab);
		choice.x = 5;
		choice.y = 3;
		choice.boxcolor = BROUGE;
		choice.colorchoix = BROUGE | FJAUNE;
		choice.colorelement = BROUGE | FBLEU;
		j = 0;
		for (i = 0; i < NBPROPRIETE; i++) {
			if (tab[i].proprietaire != NULL
					&& tab[i].proprietaire->numero == slayer->numero) {
				tabprop[j] = tab[i];
				strcpy(choice.chaine[j], tab[i].nom);
				j++;
			}
		}
		k = monomenu(&choice);
		for (i = 0; i < NBPROPRIETE; i++) {
			if (strcmp(tab[i].nom, tabprop[k].nom) == 0) {
				break;
			}
		}
		the_one = tab + i;
	}
	//free(tabprop);   
	return the_one;

}
