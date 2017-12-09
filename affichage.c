/************************************
*                                   *
*                                   *
*                                   *
*           Affichage.c             *
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
/*Fonction permettant de déplacer le curseur à l'endroit désiré de l'écran*/
void placeCurseur(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
}
/*Fonction permettant de déplacer le curseur à l'endroit désiré de l'écran
et d'afficher 2 espaces de la couleur désirée à cet emplacement*/
void placeCurseurCouleur(int x,int y,WORD couleur){
	placeCurseur(x,y);
	if(SetConsoleTextAttribute(hStdOut,couleur)==0){
		printf("Erreur dans SetConsoleTextAttribute\n");
		exit(0);
	}
	printf("  ");
}
/*Fonction permettant de déplacer le curseur à l'endroit désiré de l'écran
et d'afficher un entier de la couleur désirée à cet emplacement*/
void placeCurseurCouleur2(int x,int y,WORD couleur,int nb){
	placeCurseur(x,y);
	if(SetConsoleTextAttribute(hStdOut,couleur)==0){
		printf("Erreur dans SetConsoleTextAttribute\n");
		exit(0);
	}
	printf("%d",nb);
}
/*Fonction affichant les couleurs des cases du plateau du monopoly*/
void couleur(void){
	placeCurseurCouleur(4,1,BROSE2);
	placeCurseurCouleur(10,1,BROSE2);
	placeCurseurCouleur(13,1,BGRIS);
	placeCurseurCouleur(19,1,BBLEUC);
	placeCurseurCouleur(25,1,BBLEUC);
	placeCurseurCouleur(28,1,BBLEUC);
	placeCurseurCouleur(31,3,BVIOLET);
	placeCurseurCouleur(31,7,BVIOLET);
	placeCurseurCouleur(31,9,BVIOLET);
	placeCurseurCouleur(31,13,BMARRON);
	placeCurseurCouleur(31,17,BMARRON);
	placeCurseurCouleur(31,19,BMARRON);
	placeCurseurCouleur(19,21,BROUGE);
	placeCurseurCouleur(22,21,BROUGE);
	placeCurseurCouleur(28,21,BROUGE);
	placeCurseurCouleur(4,21,BJAUNE);
	placeCurseurCouleur(10,21,BJAUNE);
	placeCurseurCouleur(13,21,BJAUNE);
	placeCurseurCouleur(1,3,BBLEU);
	placeCurseurCouleur(1,5,BGRIS);
	placeCurseurCouleur(1,7,BBLEU);
	placeCurseurCouleur(1,13,BVERT);
	placeCurseurCouleur(1,17,BVERT);
	placeCurseurCouleur(1,19,BVERT);
}
/*Fonction affichant les hôtels ou les maisons sur les cases du plateau du monopoly*/
void affichMaisonHotels(void){
	int i;
	COORD coord={0,0};
	for(i=0;i<NBCASESPLATEAU;i++){
		switch(i){
			case 1:{
				coord.X=4;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BROSE2|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 3:{
				coord.X=10;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BROSE2|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 4:{
				coord.X=13;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BGRIS)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 6:{
				coord.X=19;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BBLEUC|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 8:{
				coord.X=25;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BBLEUC|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 9:{
				coord.X=28;
				coord.Y=1;
				if(SetConsoleTextAttribute(hStdOut,BBLEUC|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 11:{
				coord.X=31;
				coord.Y=3;
				if(SetConsoleTextAttribute(hStdOut,BVIOLET|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 13:{
				coord.X=31;
				coord.Y=7;
				if(SetConsoleTextAttribute(hStdOut,BVIOLET|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 14:{
				coord.X=31;
				coord.Y=9;
				if(SetConsoleTextAttribute(hStdOut,BVIOLET|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 16:{
				coord.X=31;
				coord.Y=13;
				if(SetConsoleTextAttribute(hStdOut,BMARRON|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 18:{
				coord.X=31;
				coord.Y=17;
				if(SetConsoleTextAttribute(hStdOut,BMARRON|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 19:{
				coord.X=31;
				coord.Y=19;
				if(SetConsoleTextAttribute(hStdOut,BMARRON|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 21:{
				coord.X=28;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BROUGE|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 23:{
				coord.X=22;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BROUGE|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 24:{
				coord.X=19;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BROUGE|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}	
			case 26:{
				coord.X=13;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BJAUNE)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 27:{
				coord.X=10;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BJAUNE)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 29:{
				coord.X=4;
				coord.Y=21;
				if(SetConsoleTextAttribute(hStdOut,BJAUNE)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 31:{
				coord.X=1;
				coord.Y=19;
				if(SetConsoleTextAttribute(hStdOut,BVERT|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 32:{
				coord.X=1;
				coord.Y=17;
				if(SetConsoleTextAttribute(hStdOut,BVERT|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 34:{
				coord.X=1;
				coord.Y=13;
				if(SetConsoleTextAttribute(hStdOut,BVERT|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 37:{
				coord.X=1;
				coord.Y=7;
				if(SetConsoleTextAttribute(hStdOut,BBLEU|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 38:{
				coord.X=1;
				coord.Y=5;
				if(SetConsoleTextAttribute(hStdOut,BGRIS)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
			case 39:{
				coord.X=1;
				coord.Y=3;
				if(SetConsoleTextAttribute(hStdOut,BBLEU|FBLANC)==0){
					printf("Erreur dans SetConsoleTextAttribute\n");
					exit(0);
				}
				break;
			}
		}
		coord.X++;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		if((tableaupropriete[i].nbmaison>0)&&(tableaupropriete[i].nbmaison<4)){
			printf("%d",tableaupropriete[i].nbmaison);
		}
		else{
			if(tableaupropriete[i].nbmaison==5){
				printf("H");
			}
		}
	}
}
/*Fonction affichant les numéros des joueurs sur les cases du plateau du monopoly*/
void affichPositionJoueurCourant(int i){
	Joueur *actuel;
	actuel=playerNumber(&monoplayers,i);
	switch(actuel->courant->numero){
		case 0:{
			placeCurseurCouleur2(1,1,BBLANC,i+1);
			break;
		}
		case 1:{
			placeCurseurCouleur2(4,1,BROSE2|FBLANC,i+1);
			break;
		}
		case 2:{
			placeCurseurCouleur2(7,1,BBLANC,i+1);
			break;
		}
		case 3:{
			placeCurseurCouleur2(10,1,BROSE2|FBLANC,i+1);
			break;
		}
		case 4:{
			placeCurseurCouleur2(13,1,BGRIS,i+1);
			break;
		}
		case 5:{
			placeCurseurCouleur2(16,1,BBLANC,i+1);
			break;
		}
		case 6:{
			placeCurseurCouleur2(19,1,BBLEUC|FBLANC,i+1);
			break;
		}
		case 7:{
			placeCurseurCouleur2(22,1,BBLANC,i+1);
			break;
		}
		case 8:{
			placeCurseurCouleur2(25,1,BBLEUC|FBLANC,i+1);
			break;
		}
		case 9:{
			placeCurseurCouleur2(28,1,BBLEUC|FBLANC,i+1);
			break;
		}
		case 10:{
			placeCurseurCouleur2(31,1,BBLANC,i+1);
			break;
		}
		case 11:{
			placeCurseurCouleur2(31,3,BVIOLET|FBLANC,i+1);
			break;
		}
		case 12:{
			placeCurseurCouleur2(31,5,BBLANC,i+1);
			break;
		}
		case 13:{
			placeCurseurCouleur2(31,7,BVIOLET|FBLANC,i+1);
			break;
		}
		case 14:{
			placeCurseurCouleur2(31,9,BVIOLET|FBLANC,i+1);
			break;
		}
		case 15:{
			placeCurseurCouleur2(31,11,BBLANC,i+1);
			break;
		}
		case 16:{
			placeCurseurCouleur2(31,13,BMARRON|FBLANC,i+1);
			break;
		}
		case 17:{
			placeCurseurCouleur2(31,15,BBLANC,i+1);
			break;
		}
		case 18:{
			placeCurseurCouleur2(31,17,BMARRON|FBLANC,i+1);
			break;
		}
		case 19:{
			placeCurseurCouleur2(31,19,BMARRON|FBLANC,i+1);
			break;
		}
		case 20:{
			placeCurseurCouleur2(31,21,BBLANC,i+1);
			break;
		}
		case 21:{
			placeCurseurCouleur2(28,21,BROUGE|FBLANC,i+1);
			break;
		}
		case 22:{
			placeCurseurCouleur2(25,21,BBLANC,i+1);
			break;
		}
		case 23:{
			placeCurseurCouleur2(22,21,BROUGE|FBLANC,i+1);
			break;
		}
		case 24:{
			placeCurseurCouleur2(19,21,BROUGE|FBLANC,i+1);
			break;
		}
		case 25:{
			placeCurseurCouleur2(16,21,BBLANC,i+1);
		}
		case 26:{
			placeCurseurCouleur2(13,21,BJAUNE,i+1);
			break;
		}
		case 27:{
			placeCurseurCouleur2(10,21,BJAUNE,i+1);
			break;
		}
		case 28:{
			placeCurseurCouleur2(7,21,BBLANC,i+1);
			break;
		}
		case 29:{
			placeCurseurCouleur2(4,21,BJAUNE,i+1);
			break;
		}
		case 30:{
			placeCurseurCouleur2(1,21,BBLANC,i+1);
			break;
		}
		case 31:{
			placeCurseurCouleur2(1,19,BVERT|FBLANC,i+1);
			break;
		}
		case 32:{
			placeCurseurCouleur2(1,17,BVERT|FBLANC,i+1);
			break;
		}
		case 33:{
			placeCurseurCouleur2(1,15,BBLANC,i+1);
			break;
		}
		case 34:{
			placeCurseurCouleur2(1,13,BVERT|FBLANC,i+1);
			break;
		}
		case 35:{
			placeCurseurCouleur2(1,11,BBLANC,i+1);
			break;
		}
		case 36:{
			placeCurseurCouleur2(1,9,BBLANC,i+1);
			break;
		}
		case 37:{
			placeCurseurCouleur2(1,7,BBLEU|FBLANC,i+1);
			break;
		}
		case 38:{
			placeCurseurCouleur2(1,5,BGRIS,i+1);
			break;
		}
		case 39:{
			placeCurseurCouleur2(1,3,BBLEU|FBLANC,i+1);
			break;
		}
	}
}
/*Fonction affichant le plateau du monopoly*/
void grille(int j){
	//COORD coord;
	int i;
	char c[3];
	c[1] = '\0';
	for (i = 0;i<34;i++)
	{
		c[0] = (char)205;
		if (i%3 == 0)
		{
			c[0] = (char)202;
		}
		locate(c,i,2);
		
	}
	for (i = 0;i<34;i++)
	{
		c[0] = (char)186;
		if (i%3 == 0)
		{
			locate(c,i,1);
			locate(c,i,21);
		}
	
		
	}
	for (i = 0;i<34;i++)
	{
		c[0] = (char)205;
		if (i%3 == 0)
		{
			c[0] = (char)203;
		}
		locate(c,i,20);
		
	}
	
	for (i = 0;i<34;i++)
	{
		c[0] = (char)205;
		if (i%3 == 0)
		{
			c[0] = (char)203;
		}
		locate(c,i,0);
		
	}
	for (i = 0;i<34;i++)
	{
		c[0] = (char)205;
		if (i%3 == 0)
		{
			c[0] = (char)202;
		}
		locate(c,i,22);
		
	}
	for (i = 1;i<22;i++)
	{
		c[0] = (char)186;
		if (i%2 == 0)
		{
			c[0] = (char)185;
		}
		locate(c,3,i);
		
	}
	for (i = 1;i<22;i++)
	{
		c[0] = (char)186;
		if (i%2 == 0)
		{
			c[0] = (char)204;
		}
		locate(c,30,i);
		
	}
	for (i = 0;i<23;i++)
	{
		c[0] = (char)186;
		if (i%2 == 0)
		{
			c[0] = (char)204;
		}
		locate(c,0,i);
		
	}
	for (i = 0;i<23;i++)
	{
		c[0] = (char)186;
		if (i%2 == 0)
		{
			c[0] = (char)185;
		}
		locate(c,33,i);
		
	}
	for (i = 1;i<22;i++)
	{
		c[0] = (char)205;
		if (i%2 == 0)
		{
			locate(c,31,i);
			locate(c,32,i);
			locate(c,1,i);
			locate(c,2,i);
		}
		
		
	}
	c[0] = (char)201;
	locate(c,0,0);
	c[0] = (char)187;
	locate(c,33,0);
	c[0] = (char)188;
	locate(c,33,22);
	c[0] = (char)200;
	locate(c,0,22);
	c[0] = (char)206;
	locate(c,3,2);
	locate(c,30,2);
	locate(c,3,20);
	locate(c,30,20);

	
	
	
	
	//changerCouleur(BBLANC|FNOIR);
	/*coord.X=0;
	coord.Y=0;
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,187);
	coord.X=0;
	coord.Y++;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
	printf("%c",186);
	for(i=0;i<11;i++){
		coord.X=coord.X+3;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
	}
	coord.X=0;
	coord.Y++;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,206,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,206,205,205,185);
	for(i=0;i<9;i++){
		coord.X=0;
		coord.Y++;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
		coord.X=coord.X+3;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
		coord.X=coord.X+27;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
		coord.X=coord.X+3;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
		coord.X=0;
		coord.Y++;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c%c%c%c",204,205,205,185);
		coord.X=coord.X+30;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c%c%c%c",204,205,205,185);
	}
	coord.X=0;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,206,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,203,205,205,206,205,205,185);
	coord.X=0;
	coord.Y++;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
	printf("%c",186);
	for(i=0;i<11;i++){
		coord.X=coord.X+3;
		if(SetConsoleCursorPosition(hStdOut,coord)==0){
			printf("Erreur dans SetConsoleCursorPosition\n");
			exit(0);
		}
		printf("%c",186);
	}
	coord.X=0;
	coord.Y++;
	if(SetConsoleCursorPosition(hStdOut,coord)==0){
		printf("Erreur dans SetConsoleCursorPosition\n");
		exit(0);
	}
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,202,205,205,188);
	
	*/
    couleur();
	affichMaisonHotels();
	if(j==10){
		for(j=0;j<monoplayers.nombrejoueur;j++){
			affichPositionJoueurCourant(j);
		}
	}
	else{
		if(j!=-1){
			affichPositionJoueurCourant(j);
		}
	}
	//placeCurseurCouleur(34,0,BBLANC|FNOIR);
}

void afficheEtatJoueur(Joueur *slayer, int x, int y)
{
	char chaine[80];
	box(BVERT|FBLEU,x,y,13,6);
	box(BJAUNE,x+14,y,29,6);
	strcpy(chaine,slayer->nom);
	locate("Nom          :",x,y);
	locate(chaine,x+15,y);
	sprintf(chaine,"%d",slayer->courant->numero);
	locate("Case Actuelle:",x,y+1);
	locate(chaine,x+15,y+1);
	box(BVIOLET|FBLANC,x+15,y+2,28,0);
	switch(slayer->courant->type)
	{
	case terrain:
		locate(tableaupropriete[slayer->courant->place].nom,x+15,y+2);
		break;
	case gare:
		locate(tableaugare[slayer->courant->place].nom,x+15,y+2);
		break;
	case compagnie:
		locate(tableaucompagnie[slayer->courant->place].nom,x+15,y+2);
		break;
	case depart:
		locate("CASE DEPART",x+15,y+2);
		break;


	}
	sprintf(chaine,"%d",nbproppossede(slayer, tableaupropriete));
	locate("Propriete    :",x,y+3);
	locate(chaine,x+15,y+3);
	sprintf(chaine,"%d",nbgarepossede(slayer, tableaugare));
	locate("Gare         :",x,y+4);
	locate(chaine,x+15,y+4);
	sprintf(chaine,"%d",nbcomppossede(slayer, tableaucompagnie));
	locate("Compagnie    :",x,y+5);
	locate(chaine,x+15,y+5);
	sprintf(chaine,"%d",slayer->argent);
	locate("Argent       :",x,y+6);
	locate(chaine,x+15,y+6);



}

void ecran(Joueur *slayer)
{
	colorscreen(BNOIR|FGRIS);
	cls();
    cadre("$",34,0,46,25,(WORD)(colorLettreHasard()|16*colorLettreHasard()));
	box(BBLANC|FNOIR,0,0,33,22);
	grille(slayer->numero);
	afficheEtatJoueur(slayer,35,1);
	box(BMARRON|FJAUNE,0,23,33,2);
	locate("MONOPOLY",12,23);
	locate("V2.0",14,24);
}

void affiche_prop(propriete *prop,int x,int y)
{
	char chaine[80];
	locate(prop->nom,x,y);
	locate("Prix                :",x,y+2);
	sprintf(chaine,"%d",prop->prix);
	locate(chaine,x+23,y+2);
	locate("Loyer               :",x,y+3);
	sprintf(chaine,"%d",prop->loyerNu);
	locate(chaine,x+23,y+3);
	locate("Loyer avec 1 maison :",x,y+4);
	sprintf(chaine,"%d",prop->loyerMaison[0]);
	locate(chaine,x+23,y+4);
	locate("Loyer avec 2 maison :",x,y+5);
	sprintf(chaine,"%d",prop->loyerMaison[1]);
	locate(chaine,x+23,y+5);
	locate("Loyer avec 3 maison :",x,y+6);
	sprintf(chaine,"%d",prop->loyerMaison[2]);
	locate(chaine,x+23,y+6);
	locate("Loyer avec 4 maison :",x,y+7);
	sprintf(chaine,"%d",prop->loyerMaison[3]);
	locate(chaine,x+23,y+7);
	locate("Nombre de maison    :",x,y+8);
	sprintf(chaine,"%d",prop->nbmaison);
	locate(chaine,x+23,y+8);
	locate("Proprietaire        :",x,y+9);
	if (prop->proprietaire == NULL)
	{
		locate("Aucun",x+23,y+9);
	}
	else
	{
		locate(prop->proprietaire->nom,x+23,y+9);
	}
}

void affiche_gare(station *stat, int x, int y)
{
	char chaine[80];
	locate(stat->nom,x,y);
	locate("Prix                :",x,y+2);
	sprintf(chaine,"%d",stat->prix);
	locate(chaine,x+23,y+2);
	locate("Loyer avec 1 gare   :",x,y+3);
	sprintf(chaine,"%d",stat->loyergare[0]);
	locate(chaine,x+23,y+3);
	locate("Loyer avec 2 gare   :",x,y+4);
	sprintf(chaine,"%d",stat->loyergare[1]);
	locate(chaine,x+23,y+4);
	locate("Loyer avec 3 gare   :",x,y+5);
	sprintf(chaine,"%d",stat->loyergare[2]);
	locate(chaine,x+23,y+5);
	locate("Loyer avec 4 gare   :",x,y+6);
	sprintf(chaine,"%d",stat->loyergare[3]);
	locate(chaine,x+23,y+6);
	locate("Proprietaire        :",x,y+7);
	if (stat->proprietaire == NULL)
	{
		locate("Aucun",x+23,y+7);
	}
	else
	{
		locate(stat->proprietaire->nom,x+23,y+7);
		locate("Gares possedes      :",x,y+8);
	    sprintf(chaine,"%d",stat->proprietaire->possession.gare);
	    locate(chaine,x+23,y+8);
	
	}
	

}

void affiche_comp(compagnies *comp, int x, int y)
{
	char chaine[80];
	locate(comp->nom,x,y);
	locate("Prix                :",x,y+2);
	sprintf(chaine,"%d",comp->prix);
	locate(chaine,x+23,y+2);
	locate("Loyer avec 1 cie (x):",x,y+3);
	sprintf(chaine,"%d",comp->fois1);
	locate(chaine,x+23,y+3);
	locate("Loyer avec 2 cie (x):",x,y+4);
	sprintf(chaine,"%d",comp->fois2);
	locate(chaine,x+23,y+4);
	locate("Proprietaire        :",x,y+5);


	if (comp->proprietaire == NULL)
	{
		locate("Aucun",x+23,y+5);
	}
	else
	{
		locate(comp->proprietaire->nom,x+23,y+5);
		locate("Compagnies possedes :",x,y+6);
    	sprintf(chaine,"%d",comp->proprietaire->possession.compagnie);
	    locate(chaine,x+23,y+6);

	}
	
}