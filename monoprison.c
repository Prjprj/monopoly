#include"biblio.h"
int caseprison(Joueur *slayer, int *dede)
{
	menu choice;
	int choix;
	int de;
	cls();
	choice.taille = 2;
	choice.boxcolor = BROUGE;
	choice.colorchoix = BROUGE|FJAUNE;
	choice.colorelement = BROUGE|FBLEU;
	choice.x=10;
	choice.y=10;
	strcpy(choice.chaine[0],"payer 5000");
	strcpy(choice.chaine[1],"tenter le de");

	
	
	//printf("\nVous etes en prison!!!\n");

	choix = menubox(&choice);
	
	slayer->prison++;

	if (choix == 0)
	{
		if (testliquidite(slayer, 5000))
		{
			retraitargent(slayer, 5000);
			sortie_prison(slayer);
			
			return 0;
		}
		else
		{
			printf("\nPaiement Impossible!!\n");
			return 1;
		}

	}
	else
	{
		de = lancede();
		if (de < 0)
		{
			printf("\nde: %d\n",de);
			printf("Tu peux sortir de prison!!!");
			sortie_prison(slayer);
			*dede = de;
			return -1;
		}
		else
		{
			printf("\nDans ta gueule connard!!!! de: %d\n",de);
			
		}

		if (slayer->prison > NBTOURPRISON)
		{
			printf("\nVous devez payer 5000\n");
			*dede = 0;
			if (testliquidite(slayer, 5000))
			{
				retraitargent(slayer, 5000);
				sortie_prison(slayer);
				return -1;

			}
			else
			{
				byebye(slayer);
				return 1;

			}
			
		}

	}

	
	return 1;
}

void sortie_prison(Joueur *slayer)
{
	slayer->prison = 0;
	outjoueurprison();
	if (slayer->courant->numero <= 10)
	{
		deplacementde(10-slayer->courant->numero,slayer,0);
	}
	else
	{
		deplacementde(NBCASESPLATEAU+10-slayer->courant->numero,slayer,0);
	}
}

void entree_prison(Joueur *slayer){
	cls();
	innPrison();
	//prison1(20,3,FROUGE|BBLANC);
	getche();
	cls();
	slayer->prison = 1;
}