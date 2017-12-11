/************************************
 *                                   *
 *                                   *
 *                                   *
 *            monotypes.h            *
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
#ifndef monotypes
#define monotypes
	#include "monoconst.h"
	typedef struct {
		char chaine[10][LONGNOMMAX];
		int taille;
		int boxcolor;
		int colorelement;
		int colorchoix;
		int x;
		int y;
	} menu;
	typedef enum {
		faux, vrai
	} booleen;
	typedef enum {
		depart, terrain, gare, compagnie, chance, communaute, impot, prison, vide
	} attribut;
	typedef enum {
		rose, bleu, violet, orange, rouge, jaune, vert, bleue
	} couleurpropriete;
	typedef enum {
		positif, negatif, avance, recul, avancecase, anniversaire
	} typecarte;
	typedef struct {
		char intitule[80];
		typecarte type;
		int parametre;
		booleen dep;
	} card;
	typedef struct {
		int propriete[8];
		int gare;
		int compagnie;
	} avoir;
	typedef struct Case_ {
		int numero;
		attribut type;
		int place;
		struct Case_ *suivant;
	} Case_;
	typedef Case_ *plateau;
	typedef struct joueur {
		char nom[LONGNOMMAX];
		char pseudo;
		int numero;
		int argent;
		avoir possession;
		plateau courant;
		struct joueur* suivant;
		int prison;
		int sortPrison;
	} Joueur;
	typedef Joueur *stich;
	typedef struct {
		Joueur *player1;
		int nombrejoueur;
	} listeJoueur;
	typedef char Code[LONGCODE];
	typedef struct {
		char nom[LONGNOMMAX];
		int prix;
		int loyergare[4];
		int prixHyp;
		int plateau;
		Joueur *proprietaire;
		Code code;
	} station;

	typedef struct {
		char nom[LONGNOMMAX];
		int prix;
		int fois1;
		int fois2;
		int prixHyp;
		int plateau;
		Joueur *proprietaire;
		Code code;
	} compagnies;
	typedef struct {
		char nom[LONGNOMMAX];
		int prix;
		int prixHyp;
		int loyerNu;
		int loyerMaison[4];
		int loyerHotel;
		int prixMaison;
		int prixHotel;
		int nbmaison;
		couleurpropriete zone;
		Joueur *proprietaire;
		int plateau;
		int etat;
		Code code;
	} propriete;
	typedef propriete tabProprietes[NBPROPRIETE];
	typedef struct {
		int de1;
		int de2;
	} doublede;
	typedef struct {
		char chaine[NBPROPRIETE][LONGNOMMAX];
		int taille;
		int boxcolor;
		int colorelement;
		int colorchoix;
		int x;
		int y;
	} menum;
#endif
