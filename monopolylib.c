//#include "biblio.h"

#include<windows.h>
#include "monoconst.h"
#include "monotypes.h"
#include "monopolylib.h"
#include "affichage.h"
#include "monoanim.h"

/*void initplayer(void)
 {
 int i;
 printf("Entrez le nombre de joueur:");
 scanf("%d",&nombrejoueur);
 for (i=0;i<nombrejoueur;i++)
 {
 printf("Entrez le nom du joueur %d:",i+1);
 scanf("%s",player[i].nom);
 player[i].argent = 10000;
 player[i].kase = 0;
 }
 }*/
int lancede(void) {     //les des 
	doublede de;
	int depla;
	char c;
	char touch[10];
	colorscreen(BNOIR | FGRIS);
	cls();
	box(BJAUNE | FROUGE, 0, 0, 80, 0);
	locate("LANCEMENT DES DES !!!", 29, 0);
	c = getch();
	if (c == 27) {
		scanf("%d", &depla);
		return depla;
	}
	c = 0;
	cadre("?", 7, 7, 11, 11,
			(WORD) (colorLettreHasard() | 16 * colorLettreHasard()));
	cadre("?", 32, 7, 11, 11,
			(WORD) (colorLettreHasard() | 16 * colorLettreHasard()));
	while (c != 13) {
		de.de1 = (int) (rnd() * 6 + 1);
		sprintf(touch, "%d", de.de1);
		box(0, 10, 10, 4, 4);
		affiche_nom_joli(touch, 10, 10, faux);

		c = getkey();
	}
	c = 0;
	while (c != 13) {
		de.de2 = (int) (rnd() * 6 + 1);
		sprintf(touch, "%d", de.de2);
		box(0, 35, 10, 4, 4);
		affiche_nom_joli(touch, 35, 10, faux);

		c = getkey();
	}
	getche();
	if (de.de1 == de.de2) {
		return -(de.de1 + de.de2);
	} else {
		return de.de1 + de.de2;
	}
}

void deplacementde(int nb, Joueur *slayer, booleen start) {
	int i;
	for (i = 0; i < nb; i++) {
		slayer->courant = (slayer->courant)->suivant;
		if (start == vrai && slayer->courant->type == depart) {
			colorscreen(BNOIR | FGRIS);
			cls();
			psgeDep();
			gainargent(slayer, PASSAGEDEPART);
		}
	}
}

void retraitargent(Joueur *slayer, int somme) {
	slayer->argent = slayer->argent - somme;
}

void gainargent(Joueur *slayer, int somme) {
	slayer->argent = slayer->argent + somme;

}

booleen testliquidite(Joueur *slayer, int somme) {
	if (slayer->argent < somme) {
		return faux;
	} else {
		return vrai;
	}
}

void initmenuJoueur(menu *choum, listeJoueur *stoch) {
	int i;
	stich moi;
	moi = stoch->player1;
	for (i = 0; i < stoch->nombrejoueur; i++) {
		strcpy(choum->chaine[i + 1], moi->nom);
		moi = moi->suivant;
	}
	strcpy(choum->chaine[0], "fin");
	choum->boxcolor = BROUGE;
	choum->colorchoix = BROUGE | FJAUNE;
	choum->colorelement = BROUGE | FBLEU;
	choum->taille = stoch->nombrejoueur + 1;
	choum->x = 10;
	choum->y = 10;
}

Joueur* playerNumber(listeJoueur *stoch, int num) { // la fonction qui retourne le numero du joueur
	stich moi, toi;
	int i;
	moi = stoch->player1;
	for (i = 0; i < stoch->nombrejoueur; i++) {
		if (moi->numero == num) {
			toi = moi;
		}
		moi = moi->suivant;
	}
	return toi;
}

int demandeprix(Joueur *slayer) {
	int c = 0;
	int heu;
	printf("Entrez le prix: ");
	scanf("%d", &heu);
	if (testliquidite(slayer, heu)) {
		c = 1;
	} else {
		printf("\nVous avez pas assez...\n");
		c = 1;
		heu = -1;
	}
	return heu;
}

Joueur* joueurprecedent(Joueur *slayer, listeJoueur *stach) {
	stich moi;
	moi = stach->player1;
	do {
		moi = moi->suivant;
	} while (moi->suivant->numero != slayer->numero);
	return moi;
}

int monomenu(menum *current) {
	int i;
	int c = -1;
	int key;
	int keycours = 0;
	int longchaine;
	longchaine = pluslongchaine(current->chaine, current->taille);
	box((WORD) current->boxcolor, (int) current->x, (int) current->y,
			(int) longchaine + 3, (int) current->taille + 1);
	for (i = 0; i < current->taille; i++) {
		colorlocate(current->chaine[i], current->x + 2, current->y + 1 + i,
				(WORD) current->colorelement);
		color((WORD) current->colorelement, current->x + 1, current->y + 1 + i,
				longchaine + 2);
	}
	while (c == -1) {
		colorlocate(current->chaine[keycours], current->x + 2,
				current->y + 1 + keycours, (WORD) current->colorchoix);
		color((WORD) current->colorchoix, current->x + 1,
				current->y + 1 + keycours, longchaine + 2);
		key = getkeyblock();
		if (key == 302) {
			colorlocate(current->chaine[keycours], current->x + 2,
					current->y + 1 + keycours, (WORD) current->colorelement);
			color((WORD) current->colorelement, current->x + 1,
					current->y + 1 + keycours, longchaine + 2);
			if (keycours < current->taille - 1) {
				keycours++;
			} else {
				keycours = 0;
			}
		}
		if (key == 301) {
			colorlocate(current->chaine[keycours], current->x + 2,
					current->y + 1 + keycours, (WORD) current->colorelement);
			color((WORD) current->colorelement, current->x + 1,
					current->y + 1 + keycours, longchaine + 2);
			if (keycours > 0) {
				keycours--;
			} else {
				keycours = current->taille - 1;
			}
		}
		if (key == 13) {
			c = keycours;
		}
	}
	return keycours;
}
