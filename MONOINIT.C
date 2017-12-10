#include"biblio.h"
void initplateau(char fich[20], Case_ *premiereCase, propriete *tabprop,
		station *tabstat, compagnies *tabcom) {
	int i;
	plateau casecourante;
	int prop = 0;
	int gar = 0;
	int cie = 0;
	casecourante = premiereCase;
	for (i = 0; i < NBCASESPLATEAU - 1; i++) {
		casecourante->suivant = (case_*) malloc(sizeof(struct case_));
		casecourante->numero = i;
		casecourante = casecourante->suivant;
	}
	casecourante->suivant = premiereCase;
	casecourante->numero = NBCASESPLATEAU - 1;
	casecourante = casecourante->suivant;
	ouvrir(fich, "plateau");
	for (i = 0; i < NBCASESPLATEAU; i++) {
		fscanf(fichier, "%d", &casecourante->type);
		switch (casecourante->type) {
		case terrain:
			casecourante->place = prop;
			tabprop[prop].plateau = i;
			prop++;
			break;
		case gare:
			casecourante->place = gar;
			tabstat[gar].plateau = i;
			gar++;
			break;
		case compagnie:
			casecourante->place = cie;
			tabcom[cie].plateau = i;
			cie++;
			break;
		default:
			casecourante->place = 0;
		}
		casecourante = casecourante->suivant;
	}
	casecourante = premiereCase;
	fclose(fichier);
}

void initpropriete(char fich[20], propriete *tab) {
	int j;
	char tic[20] = "prop0";
	char tac[3];
	j = 0;
	for (j = 0; j < NBPROPRIETE; j++) {
		sprintf(tac, "%d", j);
		strcpy(tab[j].code, strcat(tic, tac));
		ouvrir(fich, tab[j].code);
		lireligne(tab[j].nom);
		fscanf(fichier, "%d", &tab[j].prix);
		fscanf(fichier, "%d", &tab[j].loyerNu);
		fscanf(fichier, "%d", &tab[j].loyerMaison[0]);
		fscanf(fichier, "%d", &tab[j].loyerMaison[1]);
		fscanf(fichier, "%d", &tab[j].loyerMaison[2]);
		fscanf(fichier, "%d", &tab[j].loyerMaison[3]);
		fscanf(fichier, "%d", &tab[j].loyerHotel);
		fscanf(fichier, "%d", &tab[j].prixMaison);
		fscanf(fichier, "%d", &tab[j].prixHotel);
		fscanf(fichier, "%d", &tab[j].prixHyp);
		fscanf(fichier, "%d", &tab[j].zone);
		if (j < 9) {
			strcpy(tic, "prop0");
		} else {
			strcpy(tic, "prop");
		}
		fclose(fichier);
		tab[j].proprietaire = NULL;
		tab[j].nbmaison = 0;
	}
}

void initgare(char fich[20], station *tab) {
	int i;
	char lettre[2];
	char mot[10] = "gare";
	ouvrir(fich, "*gare*");
	for (i = 0; i < NBGARES; i++) {
		sprintf(lettre, "%d", i);
		strcpy(tab[i].code, strcat(mot, lettre));
		lireligne(tab[i].nom);
		strcpy(mot, "gare");
	}
	fscanf(fichier, "%d", &tab[0].prix);
	fscanf(fichier, "%d", &tab[0].loyergare[0]);
	fscanf(fichier, "%d", &tab[0].loyergare[1]);
	fscanf(fichier, "%d", &tab[0].loyergare[2]);
	fscanf(fichier, "%d", &tab[0].loyergare[3]);
	fscanf(fichier, "%d", &tab[0].prixHyp);
	fclose(fichier);
	tab[0].proprietaire = NULL;
	for (i = 1; i < NBGARES; i++) {
		tab[i].prix = tab[0].prix;
		tab[i].loyergare[0] = tab[0].loyergare[0];
		tab[i].loyergare[1] = tab[0].loyergare[1];
		tab[i].loyergare[2] = tab[0].loyergare[2];
		tab[i].loyergare[3] = tab[0].loyergare[3];
		tab[i].prixHyp = tab[0].prixHyp;
		tab[i].proprietaire = NULL;
	}
}

void initcompagnie(char fich[20], compagnies *tab) {
	int i;
	char lettre[2];
	char mot[10] = "comp";
	ouvrir(fich, "*compagnie*");
	for (i = 0; i < NBCOMPAGNIE; i++) {
		sprintf(lettre, "%d", i);
		strcpy(tab[i].code, strcat(mot, lettre));
		lireligne(tab[i].nom);
		strcpy(mot, "comp");
	}
	fscanf(fichier, "%d", &tab[0].prix);
	fscanf(fichier, "%d", &tab[0].fois1);
	fscanf(fichier, "%d", &tab[0].fois2);
	fscanf(fichier, "%d", &tab[0].prixHyp);
	tab[0].proprietaire = NULL;
	for (i = 1; i < NBCOMPAGNIE; i++) {
		tab[i].prix = tab[0].prix;
		tab[i].fois1 = tab[0].fois1;
		tab[i].fois2 = tab[0].fois2;
		tab[i].prixHyp = tab[0].prixHyp;
		tab[i].proprietaire = NULL;
	}
	fclose(fichier);
}

void initchance(char fich[20], card *tab) {
	int i;
	ouvrir(fich, "*chance*");
	for (i = 0; i < NBCARTECHANCE; i++) {
		lireligne(tab[i].intitule);
		fscanf(fichier, "%d", &tab[i].type);
		fscanf(fichier, "%d", &tab[i].parametre);
		fscanf(fichier, "%d", &tab[i].dep);
	}
	fclose(fichier);
}

void initcaisse(char fich[20], card *tab) {
	int i;
	ouvrir(fich, "*caisse*");
	for (i = 0; i < NBCARTECAISSE; i++) {
		lireligne(tab[i].intitule);
		fscanf(fichier, "%d", &tab[i].type);
		fscanf(fichier, "%d", &tab[i].parametre);
		fscanf(fichier, "%d", &tab[i].dep);
	}
	fclose(fichier);
}

void initcouleurtab(propriete *tab, int *tab2) {
	int i, j;
	couleurpropriete test;
	j = 0;
	for (i = 0; i < NBCOULEUR; i++) {
		test = tab[j].zone;
		tab2[i] = 0;
		while (tab[j].zone == test) {
			tab2[i]++;
			j++;
		}
	}
}

