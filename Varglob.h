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
