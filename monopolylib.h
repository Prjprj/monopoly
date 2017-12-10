#ifndef MONOPOLYLIB
#define MONOPOLYLIB
	#include "biblio.h"
	booleen testliquidite(Joueur*, int);
	void retraitargent(Joueur*, int);
	void gainargent(Joueur*, int);
	int lancede(void);
	void deplacementde(int, Joueur*, booleen);
	int demandeprix(Joueur*);
	Joueur* joueurprecedent(Joueur*, listeJoueur*);
	Joueur* playerNumber(listeJoueur*, int);
	void initmenuJoueur(menu*, listeJoueur*);
	int monomenu(menum*);
#endif
