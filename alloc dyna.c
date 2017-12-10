/************************************
 *                                   *
 *                                   *
 *                                   *
 *           Alloc dyna.c            *
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
/*Fonction allouant dynamiquement nb joueurs, liés comme dans une file chainée*/
void alloc(int nb) {
	Joueur* actuel;
	monoplayers.player1 = (Joueur*) malloc(sizeof(Joueur));
	actuel = monoplayers.player1;
	switch (nb) {
	case 8: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 7: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 6: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 5: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 4: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 3: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	case 2: {
		actuel->suivant = (Joueur*) malloc(sizeof(Joueur));
		actuel = actuel->suivant;
	}
	}
	actuel->suivant = monoplayers.player1;
}
/*Fonction libérant la place utilisée par les joueurs alloués dans la fonction précédente*/
void freememoire(void) {
	switch (monoplayers.nombrejoueur) {
	case 8: {
		free(
				monoplayers.player1->suivant->suivant->suivant->suivant->suivant->suivant->suivant);
	}
	case 7: {
		free(
				monoplayers.player1->suivant->suivant->suivant->suivant->suivant->suivant);
	}
	case 6: {
		free(monoplayers.player1->suivant->suivant->suivant->suivant->suivant);
	}
	case 5: {
		free(monoplayers.player1->suivant->suivant->suivant->suivant);
	}
	case 4: {
		free(monoplayers.player1->suivant->suivant->suivant);
	}
	case 3: {
		free(monoplayers.player1->suivant->suivant);
	}
	case 2: {
		free(monoplayers.player1->suivant);
	}
	default: {
		free(monoplayers.player1);
	}
	}
}
