/************************************
 *                                   *
 *                                   *
 *                                   *
 *           Affichage.h             *
 *        couplé à Affichage.c       *
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
#ifndef Affichage
#define Affichage
	#include "biblio.h"
	void couleur(void);
	void affichMaisonHotels(void);
	void affichPositionJoueurCourant(int);
	void grille(int);
	void placeCurseur(int, int);
	void placeCurseurCouleur(int, int, WORD);
	void placeCurseurCouleur2(int, int, WORD, int);

	void ecran(Joueur *);

	void affiche_gare(station *, int, int);
	void affiche_comp(compagnies *, int, int);
	void affiche_prop(propriete *, int, int);
#endif
