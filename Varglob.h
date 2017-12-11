/************************************
 *                                   *
 *                                   *
 *                                   *
 *            Varglob.h              *
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
#ifndef Varglob
#define Varglob
	#include<stdio.h>
	#include<windows.h>
	#include "monotypes.h"
	#include "monoconst.h"
	int nombrejoueur;
	int tableau[NBCASESPLATEAU];
	Case_ casedepart;
	propriete tableaupropriete[NBPROPRIETE];
	station tableaugare[NBGARES];
	compagnies tableaucompagnie[NBCOMPAGNIE];
	Joueur player[NBJOUEURMAX];
	HANDLE hStdOut;
	HANDLE hStdIn;
	time_t start;
	int seconde;
	FILE *fichier;
	listeJoueur monoplayers;
#endif
