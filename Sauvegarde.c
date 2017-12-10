/************************************
 *                                   *
 *                                   *
 *                                   *
 *           Sauvegarde.c            *
 *        Créé pour le projet        *
 *            Monopoly               *
 *                                   *
 *                                   *
 *    Pierre Ramos                   *
 *    Laurent Nguyen                 *
 *    Azouaou Sardou                 *
 *                                   *
 *                                   *
 *                                   *
 *                                   *
 *                                   *
 *                                   *
 ************************************/
#include"biblio.h"
/*Fonction éffectuant la sauvegarde d'une partie*/
void sauvegarde(Joueur *act) {
	int boucle = 0, i;
	FILE *fichier;
	char reponse[100], rep;
	Joueur *actuel = monoplayers.player1;
	effacerEcran(hStdOut);
	do {
		boucle = 0;
		printf(
				"Entrez le nom du fichier ou vous voulez enregistrer votre partie\n");
		scanf("%s", reponse);
		fichier = fopen(reponse, "r");
		/*Vérifie si le fichier éxiste déjà, si oui propose de l'écraser*/
		if (fichier != NULL) {
			fclose(fichier);
			printf("Ce fichier existe deja, voulez vous l'ecraser?(o/n)\n");
			rep = getch();
			/*Cas où le joueur renonce à l'écrasement de la sauvegarde*/
			if (rep == 'n') {
				printf(
						"Pour entrer un nouveau nom de fichier appuyez sur n'importe quelle touche, sinonappuyez sur la touche Escape\n");
				rep = getch();
				boucle = 1;
				if (rep == 27) {
					boucle = 0;
					printf("La partie ne sera donc pas sauvegardee\n");
				}
			}
			/*Cas où le joueur écrase la sauvegarde*/
			else {
				if (rep == 'o') {
					fichier = fopen(reponse, "w");
					if (fichier == NULL) {
						printf("Impossible de creer le fichier\n");
						printf(
								"Pour entrer un nouveau nom de fichier appuyez sur n'importe quelle touche, sinonappuyez sur la touche Escape\n");
						rep = getch();
						boucle = 1;
						if (rep == 27) {
							boucle = 0;
							printf("La partie ne sera donc pas sauvegardee\n");
						}
					} else {
						/*Sauvegarde proprement dite*/
						fprintf(fichier, "%d\n", monoplayers.nombrejoueur); //Sauvegarde du nombre de joueurs
						/*Sauvegarde des joueurs*/
						for (i = 0; i < monoplayers.nombrejoueur; i++) {
							fprintf(fichier, "%s\n", actuel->nom);
							fprintf(fichier, "%c\n", actuel->pseudo);
							fprintf(fichier, "%d\n", actuel->numero);
							fprintf(fichier, "%d\n", actuel->argent);
							fprintf(fichier, "%d\n", actuel->prison);
							fprintf(fichier, "%d\n", actuel->sortPrison);
							fprintf(fichier, "%d\n", actuel->courant->numero);
							actuel = actuel->suivant;
						}
						/*Sauvegarde des propriétés*/
						for (i = 0; i < NBPROPRIETE; i++) {
							fprintf(fichier, "%s\n", tableaupropriete[i].code);
							if (tableaupropriete[i].proprietaire != NULL) {
								fprintf(fichier, "%d\n",
										tableaupropriete[i].proprietaire->numero);
							} else {
								fprintf(fichier, "%d\n", 0);
							}
							fprintf(fichier, "%d\n",
									tableaupropriete[i].nbmaison);
						}
						/*Sauvegarde des gares*/
						for (i = 0; i < NBGARES; i++) {
							fprintf(fichier, "%s\n", tableaugare[i].code);
							if (tableaugare[i].proprietaire != NULL) {
								fprintf(fichier, "%d\n",
										tableaugare[i].proprietaire->numero);
							} else {
								fprintf(fichier, "%d\n", 0);
							}
						}
						/*Sauvegarde des compagnies*/
						for (i = 0; i < NBCOMPAGNIE; i++) {
							fprintf(fichier, "%s\n", tableaucompagnie[i].code);
							if (tableaucompagnie[i].proprietaire != NULL) {
								fprintf(fichier, "%d\n",
										tableaucompagnie[i].proprietaire->numero);
							} else {
								fprintf(fichier, "%d\n", 0);
							}
						}
						fprintf(fichier, "%d\n", act->numero);
						fclose(fichier);
						printf("Partie sauvegardee\n");
					}
				}
			}
		}
		/*Cas où le fichier n'existe pas avant*/
		else {
			fichier = fopen(reponse, "w");
			if (fichier == NULL) {
				printf("Impossible de creer le fichier\n");
				printf(
						"Pour entrer un nouveau nom de fichier appuyez sur n'importe quelle touche, sinonappuyez sur la touche Escape\n");
				rep = getch();
				boucle = 1;
				if (rep == 27) {
					boucle = 0;
					printf("La partie ne sera donc pas sauvegardee\n");
				}
			} else {
				/*Sauvegarde proprement dite*/
				fprintf(fichier, "%d\n", monoplayers.nombrejoueur); //Sauvegarde du nombre de joueurs
				/*Sauvegarde des joueurs*/
				for (i = 0; i < monoplayers.nombrejoueur; i++) {
					fprintf(fichier, "%s\n", actuel->nom);
					fprintf(fichier, "%c\n", actuel->pseudo);
					fprintf(fichier, "%d\n", actuel->numero);
					fprintf(fichier, "%d\n", actuel->argent);
					fprintf(fichier, "%d\n", actuel->prison);
					fprintf(fichier, "%d\n", actuel->sortPrison);
					fprintf(fichier, "%d\n", actuel->courant->numero);
					actuel = actuel->suivant;
				}
				/*Sauvegarde des propriétés*/
				for (i = 0; i < NBPROPRIETE; i++) {
					fprintf(fichier, "%s\n", tableaupropriete[i].code);
					if (tableaupropriete[i].proprietaire != NULL) {
						fprintf(fichier, "%d\n",
								tableaupropriete[i].proprietaire->numero);
					} else {
						fprintf(fichier, "%d\n", 0);
					}
					fprintf(fichier, "%d\n", tableaupropriete[i].nbmaison);
				}
				/*Sauvegarde des gares*/
				for (i = 0; i < NBGARES; i++) {
					fprintf(fichier, "%s\n", tableaugare[i].code);
					if (tableaugare[i].proprietaire != NULL) {
						fprintf(fichier, "%d\n",
								tableaugare[i].proprietaire->numero);
					} else {
						fprintf(fichier, "%d\n", 0);
					}
				}
				/*Sauvegarde des compagnies*/
				for (i = 0; i < NBCOMPAGNIE; i++) {
					fprintf(fichier, "%s\n", tableaucompagnie[i].code);
					if (tableaucompagnie[i].proprietaire != NULL) {
						fprintf(fichier, "%d\n",
								tableaucompagnie[i].proprietaire->numero);
					} else {
						fprintf(fichier, "%d\n", 0);
					}
				}
				fprintf(fichier, "%d\n", act->numero);
				fclose(fichier);
				printf("Partie sauvegardee\n");
			}
		}
	} while (boucle != 0);
}
/*Fonction éffectuant le chargement d'une partie*/
int chargement(void) {
	int boucle = 0, i, j, res, numero;
	FILE *fichier;
	char reponse[100], rep;
	Joueur *actuel = monoplayers.player1, *act = monoplayers.player1;
	effacerEcran(hStdOut);
	do {
		boucle = 0;
		printf(
				"Entrez le nom du fichier a partir duquel vous voulez charger votre partie\n");
		scanf("%s", reponse);
		fichier = fopen(reponse, "r");
		if (fichier != NULL) {
			fscanf(fichier, "%d\n", &monoplayers.nombrejoueur); //Chargement du nombre de joueurs
			alloc(monoplayers.nombrejoueur); //Allocation des joueurs
			actuel = monoplayers.player1; //Initialisation du curseur
			/*Chargement des joueurs*/
			for (i = 0; i < monoplayers.nombrejoueur; i++) {
				fscanf(fichier, "%s\n", actuel->nom);
				fscanf(fichier, "%c\n", &actuel->pseudo);
				fscanf(fichier, "%d\n", &actuel->numero);
				fscanf(fichier, "%d\n", &actuel->argent);
				fscanf(fichier, "%d\n", &actuel->prison);
				fscanf(fichier, "%d\n", &actuel->sortPrison);
				fscanf(fichier, "%d\n", &numero);
				actuel->courant = &casedepart;
				deplacementde(numero, actuel, 0);
				for (j = 0; j < NBCOULEUR; j++) {
					actuel->possession.propriete[j] = 0;
				}
				actuel = actuel->suivant;
			}
			/*Chargement des propriétés*/
			for (i = 0; i < NBPROPRIETE; i++) {
				fscanf(fichier, "%s\n", tableaupropriete[i].code);
				fscanf(fichier, "%d\n", &res);
				if (res != 0) {
					act = playerNumber(&monoplayers, res);
					tableaupropriete[i].proprietaire = act;
					act->possession.propriete[tableaupropriete[i].zone]++;
				} else {
					tableaupropriete[i].proprietaire = NULL;
				}
				fscanf(fichier, "%d\n", &tableaupropriete[i].nbmaison);
			}
			/*Chargement des gares*/
			for (i = 0; i < NBGARES; i++) {
				fscanf(fichier, "%s\n", tableaugare[i].code);
				fscanf(fichier, "%d\n", &res);
				if (res != 0) {
					act = playerNumber(&monoplayers, res);
					tableaugare[i].proprietaire = act;
				} else {
					tableaugare[i].proprietaire = NULL;
				}
			}
			/*Chargement des compagnies*/
			for (i = 0; i < NBCOMPAGNIE; i++) {
				fscanf(fichier, "%s\n", tableaucompagnie[i].code);
				fscanf(fichier, "%d\n", &res);
				if (res != 0) {
					act = playerNumber(&monoplayers, res);
					tableaucompagnie[i].proprietaire = act;
				} else {
					tableaucompagnie[i].proprietaire = NULL;
				}
			}
			act = monoplayers.player1;
			for (i = 0; i < monoplayers.nombrejoueur; i++) {
				act->possession.gare = nbgarepossede(act, tableaugare);
				act->possession.gare = nbcomppossede(act, tableaucompagnie);
				act = act->suivant;
			}
			fscanf(fichier, "%d\n", &res);
			fclose(fichier);
			printf("Partie chargee\n");
			return (res);
		}
		/*Cas où le fichier ne peut être ouvert*/
		else {
			printf("Impossible de lire le fichier\n");
			printf(
					"Pour entrer un nouveau nom de fichier appuyez sur n'importe quelle touche, sinon appuyez sur la touche Escape\n");
			rep = getch();
			boucle = 1;
			if (rep == 27) {
				boucle = 0;
				printf("La partie ne sera donc pas chargee\n");
				return (0);
			}
		}
	} while (boucle != 0);
	return (0);
}
