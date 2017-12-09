#include"biblio.h"
booleen achatcomp(Joueur *slayer, compagnies *comp){
	if (testliquidite(slayer,comp->prix)){
		retraitargent(slayer, comp->prix);
		acquiscomp(slayer,comp);
		colorlocate("Vous avez acquis la compagnie",45,16,FGRIS);
		getche();
		return vrai;
	}
	else{
		return faux;
	}

}

void acquiscomp(Joueur *slayer, compagnies *comp){
	comp->proprietaire = slayer;
	slayer->possession.compagnie++;
}

void pertecomp(Joueur *slayer, compagnies *comp){
	comp->proprietaire = NULL;
	slayer->possession.compagnie--;
}




booleen casecompagnie(Joueur *slayer, compagnies *tab, int de){
	menu choice;
	int loyercomp;
	if (tab->proprietaire == NULL){
		locate("Voulez-vous acheter?",52,14);
		initmenu(&choice,"monopoly.dat","menuachat");
		if (menubox(&choice) == 1){
			box(BNOIR,52,14,20,9);
			if (achatcomp(slayer,tab) == faux){
				locate("Vous n'avez pas assez!",45,16);
			}
			return vrai;
		}
		else{
			return faux;
		}
	}
	else{
	    if (tab->proprietaire->possession.compagnie == 1){
			loyercomp = de * tab->fois1;
		}
		if (tab->proprietaire->possession.compagnie >= 2){
			loyercomp = de * tab->fois2;
		}
		if ( testliquidite(slayer, loyercomp) == vrai){
			paiementloyercomp(slayer,loyercomp,tab);
		}
		else{
			slayer = byebye(slayer);
		}
		return vrai;
	}
}

void paiementloyercomp(Joueur *slayer, int somme, compagnies *comp){
	char chaine[80];
	sprintf(chaine,"%d",somme);
	locate(chaine,55,18);
	locate("Paiement du loyer...",45,16);
	getche();
	retraitargent(slayer, somme);
	gainargent(comp->proprietaire, somme);
}

void venteEncheresComp(compagnies *comp, listeJoueur *stach){ // sans commentaire
	int prix, proposition, possesseur, endless, test;
	stich toi;
	/* initialisation du menu... */
	menu choice;
	char chaine[80];
	initmenuJoueur(&choice, stach);
	choice.x = 30;
	choice.y = 8;
	cls();
	box(BJAUNE|FROUGE,0,0,80,0);
	locate("Vente aux Encheres",25,0);
	getche();
	endless = faux;
	prix = comp->prix;
	possesseur = -1;
	while ( endless == faux ){
		colorscreen(BNOIR|FGRIS);
		cls();
		box(BJAUNE|FROUGE,0,0,80,0);
		locate("Vente aux Encheres",25,0);
		locate("Mise a prix:",25,4);
		sprintf(chaine,"%d",prix);
		locate(chaine, 40,4);
		locate("Qui augmente les encheres?",24,6);
		test = menubox(&choice);
		if (test == 0){
			endless = vrai;
			if (possesseur != -1){
				toi = playerNumber(stach,possesseur);
				retraitargent(toi,prix);
				acquiscomp(toi, comp);
				locate("Compagnie Acquise",44,10);
				getche();
			}
			else{
				box(BNOIR,0,1,80,25);
				locate("Pas de Vente!!!",30,10);
				getche();
			}
		}
		else{
				
			toi = playerNumber(stach,test-1);
			proposition = dialogIntBox("Combien voulez-vous proposer?",44,10,31,BROUGE,BBLEU|FJAUNE);
			
			if (testliquidite(toi, prix) && proposition > prix){
				prix = proposition;
				possesseur = test-1;
			}
			else{
				locate("Achat impossible!!",48,12);
				getche();
			}
		}
	}
}

int nbcomppossede(Joueur *slayer, compagnies *tab){
	int i, nb;
	nb = 0;
	for (i=0; i<NBCOMPAGNIE ; i++){
		if (tab[i].proprietaire != NULL && tab[i].proprietaire->numero == slayer->numero){
			nb ++;
		}
	}
	return nb;
}

void visuelcomp(Joueur *slayer, compagnies *tab){
	compagnies *hello;
	hello =	returncomp(slayer, tab);
    if (hello != NULL){
		affiche_comp(hello,35,8);
		getche();
	}
}

compagnies* returncomp(Joueur *slayer, compagnies *tab){
	int i, j, k;
	menum choice;
	compagnies *tabcomp;
	compagnies *the_one;
	if (nbcomppossede(slayer, tab) == 0){
		the_one = NULL;
	}
	else{
		tabcomp = malloc(nbcomppossede(slayer, tab) * sizeof(compagnies));
		choice.taille = nbcomppossede(slayer, tab);
		choice.x = 5;
		choice.y = 3;
		choice.boxcolor = BROUGE;
		choice.colorchoix = BROUGE|FJAUNE;
		choice.colorelement = BROUGE|FBLEU;
		j = 0;
		for (i=0; i<NBCOMPAGNIE ; i++){
			if (tab[i].proprietaire != NULL && tab[i].proprietaire->numero == slayer->numero){
				tabcomp[j] = tab[i];
				strcpy(choice.chaine[j],tab[i].nom);
				j++;
			}
		}
		k = monomenu(&choice);
		for (i=0; i<NBCOMPAGNIE; i++){
			if (strcmp(tab[i].nom , tabcomp[k].nom)==0){
				break;
			}
		}
		the_one = tab+i;			
	}
	//free(tabcomp);   
	return the_one;
}