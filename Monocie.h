#ifndef MONOCIE
#define MONOCIE
	#include "monotypes.h"
	booleen achatcomp(Joueur*, compagnies*);
	void acquiscomp(Joueur*, compagnies*);
	void pertecomp(Joueur*, compagnies*);
	void paiementloyercomp(Joueur*, int, compagnies*);
	booleen casecompagnie(Joueur*, compagnies*, int);
	void venteEncheresComp(compagnies*, listeJoueur*);
	compagnies* returncomp(Joueur *, compagnies *);
	int nbcomppossede(Joueur*, compagnies*);
	void visuelcomp(Joueur*, compagnies*);
#endif
