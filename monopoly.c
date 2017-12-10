#include "biblio.h"

void monopoly(void) {
	int rep;
	char rien1[3];
	char rien2[3];
	int i, j, c, des, tour;
	booleen win = faux;
	int doublede;
	int replay, pasfini;
	card tabchance[NBCARTECHANCE];
	card tabcaisse[NBCARTECAISSE];
	stich moi;
	int tableaucouleur[NBCOULEUR];
	menu deb;

	initprgm();

	initplateau("monopoly.dat", &casedepart, tableaupropriete, tableaugare,
			tableaucompagnie);
	initpropriete("monopoly.dat", tableaupropriete);
	initgare("monopoly.dat", tableaugare);
	initcompagnie("monopoly.dat", tableaucompagnie);
	initchance("monopoly.dat", tabchance);
	initcaisse("monopoly.dat", tabcaisse);
	initcouleurtab(tableaupropriete, tableaucouleur);

	/* initalisation de joueurs... avec des pointeurs...!!!!!!*/

	animIntro();

	initmenu(&deb, "monopoly.dat", "*menudebut*");
	rep = menubox(&deb);

	if (rep == 1) {

		tour = chargement();
		moi = playerNumber(&monoplayers, tour);
		c = vrai;
	} else {
		initmenu(&deb, "monopoly.dat", "*menunbjoujou*");
		box((WORD) deb.boxcolor, 58, 2, 18, 2);
		colorlocate("Nombre de joueur:", 59, 3, (WORD) deb.boxcolor);
		monoplayers.nombrejoueur = menubox(&deb) + 2;
		alloc(monoplayers.nombrejoueur);
		moi = monoplayers.player1;

		strcpy(rien1, "Nom du Joueur ");
		for (i = 0; i < monoplayers.nombrejoueur; i++) {

			sprintf(rien2, "%d", i + 1);
			strcpy(rien1, strcat(rien1, rien2));
			effacerEcran(hStdOut);
			box((WORD) (colorFondHasard()), 0, 0, 80, 25);
			affiche_nom_joli("PLAYER", 23, 1, faux);
			dialogCharBox(moi->nom, rien1, 30, 9, 20, BROUGE | FBLEU,
			BTURQ | FVIOLET);

			strcpy(rien1, "Nom du Joueur ");

			moi->argent = 150000;
			moi->courant = &casedepart;
			moi->pseudo = moi->nom[0];
			moi->sortPrison = 0;
			moi->numero = i;
			moi->possession.compagnie = 0;
			moi->possession.gare = 0;
			moi->prison = 0;
			for (j = 0; j < 8; j++) {
				moi->possession.propriete[j] = 0;
			}
			moi = moi->suivant;
		}
		moi = monoplayers.player1; // moi c'est le curseur!
		c = vrai;
	}

	do {
		ecran(moi);
		doublede = 0;
		replay = 0;
		if (moi->prison != 0) {
			replay = caseprison(moi, &des);
			getche();
		} else {
			if (faux
					== menutour(moi, &monoplayers, tableaupropriete,
							tableaucouleur, tableaugare, tableaucompagnie,
							&replay)) {
				replay = 1;
				c = faux;
			}
		}
		if (monoplayers.nombrejoueur <= 1) {
			win = vrai;
			replay = 1;
			c = faux;
		}
		while (replay == 0 || replay == -1) {
			ecran(moi);
			if (replay == 0) {
				des = lancede();
			}
			if (des < 0) {
				for (i = 1; i < 25; i++) {
					colorlocate("!!!!DOUBLE!!!!", 65, i,
							(WORD) (colorLettreHasard()
									| 16 * colorLettreHasard()));
					colorlocate("!!!!DOUBLE!!!!", 51, i,
							(WORD) (colorLettreHasard()
									| 16 * colorLettreHasard()));
					sleep(0.05);
				}
				getche();
				replay = 0;
				doublede++;
				if (doublede == 3) {
					cls();
					for (i = 80; i > -50; i--) {
						affiche_nom_joli("3 DOUBLES@", i, 10, faux);
						sleep(0.05);
						cls();
					}
					entree_prison(moi);
					replay = 1;
					getche();
				}
			} else {
				replay = 1;
			}
			if (moi->prison == 0) {
				deplacementde(abs(des), moi, vrai);
				do {
					pasfini = 0;
					deplacementsurcase(moi, &monoplayers, tableaupropriete,
							tableaucouleur, tableaugare, tableaucompagnie,
							tabchance, tabcaisse, &pasfini, des);

				} while (pasfini != 0);
			}
		}
		if (monoplayers.nombrejoueur <= 1) {
			win = vrai;
			replay = 1;
			c = faux;
		}
		ecran(moi);
		moi = moi->suivant;
		getche();
	} while (c == vrai);
	cls();
	if (win == vrai) {
		winner();
	}
	colorscreen(BJAUNE | FVERT);
	affiche_nom_joli("THE END", 16, 10, vrai);
	i = 0;
	while (i != 13) {
		cadre("*", 14, 8, 45, 9, colorLettreHasard());
		i = getkey();
	}
	cls();
	exit(0);
}

void main(void) {
	int i, rep2, hasard;
	time_t temps;
	//Obtention de la date courante (en secondes)
	temps = time(NULL);
	hasard = (int) (temps % 60);
	//Execution un nombre aleatoire de fois de la fonction rand()
	for (i = 0; i < (hasard); i = i + 1) {
		do {
			rep2 = rand();
		} while ((rep2 < 0) || (rep2 > 3));
	}
	//Creation de la console
	if (AllocConsole() == 1) {
		printf("Erreur dans AllocConsole\n");
		exit(0);
	}
	//Creation du titre
	if (SetConsoleTitle(
			"                                                               Monopoly")
			== 0) {
		printf("Erreur dans SetConsoleTitle\n");
		exit(0);
	}

	monopoly();
	//initprgm();

	freememoire();

}
