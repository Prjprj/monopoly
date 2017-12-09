/************************************
*                                   *
*                                   *
*                                   *
*           Consolenew.c            *
*        Cr�� pour le projet        *
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
/*Fonction permettant d'�ffacer l'�cran*/
void effacerEcran(HANDLE h){
	COORD origine={0,0};
	DWORD nombreCaracteresEcrits;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD tailleEcran;
	GetConsoleScreenBufferInfo(h,&csbi);
	tailleEcran=csbi.dwSize.X*csbi.dwSize.Y;
	FillConsoleOutputCharacter(h,(TCHAR)' ',tailleEcran,origine,&nombreCaracteresEcrits);
	GetConsoleScreenBufferInfo(h,&csbi);
	FillConsoleOutputAttribute(h,csbi.wAttributes,tailleEcran,origine,&nombreCaracteresEcrits);
	SetConsoleCursorPosition(h,origine);	
	return;
}
/*Fonction permettant de modifier rapidement la couleur du fond et de la police*/
void changerCouleur(WORD couleur){
	if(SetConsoleTextAttribute(hStdOut,couleur)==0){
		printf("Erreur dans SetConsoleTextAttribute\n");
		exit(0);
	}
	effacerEcran(hStdOut);
}
/*Fonction �ffacant l'�cran et affichant le plateau du monopoly*/
void effacerPartieEcranMono(int i){
	effacerEcran(hStdOut);
	grille(i);
}