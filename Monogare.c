#include"biblio.h"
booleen achatgare(Joueur *slayer, station *stat){
	if (testliquidite(slayer,stat->prix)){
		retraitargent(slayer, stat->prix);
		acquisgare(slayer,stat);
		colorlocate("Vous avez acquis la gare",45,16,FGRIS);
		getche();
		return vrai;
	}
	else{
		return faux;
	}
}

void acquisgare(Joueur *slayer, station *stat){
	stat->proprietaire = slayer;
	slayer->possession.gare++;
}

void pertegare(Joueur *slayer, station *stat){
	stat->proprietaire = NULL;
	slayer->possession.gare--;
}



booleen casegare(Joueur *slayer, station *tab){
	menu choice;
	int loyer_gare;
	if (tab->proprietaire == NULL){
		locate("Voulez-vous acheter?",52,14);
		initmenu(&choice,"monopoly.dat","menuachat");
		if (menubox(&choice) == 1){
			box(BNOIR,52,14,20,9);
			if (achatgare(slayer,tab) == faux){
				locate("Vous n'avez pas assez!",45,16);
			}
			return vrai;
		}
		else{
			return faux;
		}
	}
	else{
	    loyer_gare = tab->loyergare[tab->proprietaire->possession.gare-1]; //bug au niveau de gare++
		if ( testliquidite(slayer, loyer_gare) == vrai){
			paiementloyergare(slayer,loyer_gare,tab);
		}
		else{
			slayer = byebye(slayer);
		}
		return vrai;	
	}
}

void paiementloyergare(Joueur *slayer, int somme, station *stat){
	locate("Paiement du loyer...",45,16);
	getche();
	retraitargent(slayer, somme);
	gainargent(stat->proprietaire, somme);
}

void venteEncheresGare(station *stat, listeJoueur *stach){ // sans commentaire
	int prix, proposition, possesseur, endless, test;
	stich toi;
	/* initialisation du menu... */
	menu choice;
	char chaine[80];
	initmenuJoueur(&choice, stach);
	choice.x = 30;
	choice.y = 8;
	colorscreen(BNOIR|FGRIS);
	cls();
	box(BJAUNE|FROUGE,0,0,80,0);
	locate("Vente aux Encheres",25,0);
	getche();
	endless = faux;
	prix = stat->prix;
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
				acquisgare(toi, stat);
				locate("Gare Acquise",44,10);
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

int nbgarepossede(Joueur *slayer, station *tab){
	int i, nb;
	nb = 0;
	for (i=0; i<NBGARES ; i++){
		if (tab[i].proprietaire != NULL && tab[i].proprietaire->numero == slayer->numero){
			nb ++;
		}
	}
	return nb;
}

station* returngare(Joueur *slayer, station *tab){
	int i, j, k;
	menum choice;
	station *tabgare;
	station *the_one;
	if (nbgarepossede(slayer, tab) == 0){
		the_one = NULL;
	}
	else{
		tabgare = malloc(nbgarepossede(slayer, tab) * sizeof(station));
		choice.taille = nbgarepossede(slayer, tab);
		choice.x = 5;
		choice.y = 3;
		choice.boxcolor = BROUGE;
		choice.colorchoix = BROUGE|FJAUNE;
		choice.colorelement = BROUGE|FBLEU;
		j = 0;
		for (i=0; i<NBGARES ; i++){
			if (tab[i].proprietaire != NULL && tab[i].proprietaire->numero == slayer->numero){
				tabgare[j] = tab[i];
				strcpy(choice.chaine[j],tab[i].nom);
				j++;
			}
		}
		k = monomenu(&choice);
		for (i=0; i<NBGARES; i++){
			if (strcmp(tab[i].nom , tabgare[k].nom)==0){
				break;
			}
		}
		the_one = tab+i;			
	}
	//free(tabgare);
	return the_one;
}

void visuelgare(Joueur *slayer, station *tab){
	station *hello;
	hello =	returngare(slayer, tab);
    if (hello != NULL){
		affiche_gare(hello,35,8);
		getche();
	}	
}