#ifndef MONOPROP
#define MONOPROP
	#include "biblio.h"
	booleen achatpropriete(Joueur*, propriete*);
	booleen casepropriete(Joueur*, propriete*, int*);
	void acquisprop(Joueur*, propriete*);
	void perteprop(Joueur*, propriete*);
	void paiementloyerprop(Joueur*, propriete*, int*);
	void venteEncheresProp(propriete*, listeJoueur*);
	int determineloyer(propriete*, int*);
	int nbproppossede(Joueur*, propriete*);
	void visuelpropriete(Joueur*, propriete*);
	propriete* returnprop(Joueur*, propriete*);
#endif
