#include "biblio.h"

void initprgm(void) {
	time_t t1;
	int i = 0;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hStdIn = GetStdHandle(STD_INPUT_HANDLE);
	srand(time(&start));
	t1 = time(&start);
	while (time(&start) <= t1) {
		i++;
	}
	seconde = i;
}

/* Efface l'ecran */
void cls(void) {
	COORD origine = { 0, 0 }; /* point en haut à gauche */
	DWORD nombreCaracteresEcrits;
	CONSOLE_SCREEN_BUFFER_INFO csbi; /* Variable pour stocker le Console Screen Buffer Info */
	DWORD tailleEcran; /* Taille de l'ecran */

	// Lire le taille de l'ecran
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	tailleEcran = csbi.dwSize.X * csbi.dwSize.Y;

	// Remplir l'ecran avec des espaces
	FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', tailleEcran, origine,
			&nombreCaracteresEcrits);

	// Remplir l'ecran avec la couleur courante

	FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, tailleEcran, origine,
			&nombreCaracteresEcrits);

	// Mettre le curseur en haut à gauche
	SetConsoleCursorPosition(hStdOut, origine);
}

/* Attribut les couleurs à tout l'écran */
void colorscreen(WORD couleur) {
	SetConsoleTextAttribute(hStdOut, couleur);
	cls();
}

/* Attribut les couleurs à une certaine zone de l'écran */
void color(WORD couleur, int x, int y, int taille) {
	COORD point;

	point.X = x;
	point.Y = y;

	FillConsoleOutputAttribute(hStdOut, couleur, taille, point, &taille);
}

/* Fonction qui affiche un rectangle d'une certaine couleur à l'ecran */

/* (x,y): coordonnées du sommet en haut à gauche du rectangle
 (L,l): taille du rectangle*/
void box(WORD couleur, int x, int y, int L, int l) {
	int i, j;
	for (j = y; j <= y + l; j++) {
		for (i = x; i <= x + L; i++) {
			color(couleur, i, j, 1);
		}
	}
}

int pluslongchaine(char courant[50][50], int taille) {
	int i = 0;
	int c;
	c = strlen(courant[i]);
	for (i = 1; i < taille; i++) {
		if ((signed) strlen(courant[i]) > c) {
			c = strlen(courant[i]);
		}
	}
	return c;
}

/* Fonction pour écrire du texte à l'ecran à une position particulière... */
int locate(char chaine[80], int x, int y) {
	COORD curseur;
	DWORD nombreCaracteres;

	if (x > 84 || y > 24) {
		return 0;
	}
	curseur.X = x;
	curseur.Y = y;
	WriteConsoleOutputCharacter(hStdOut, chaine, strlen(chaine), curseur,
			&nombreCaracteres);
	return 1;
}

/* Pareil avec les couleurs en plus...*/
int colorlocate(char chaine[80], int x, int y, WORD couleur) {
	color(couleur, x, y, strlen(chaine));
	return locate(chaine, x, y);
}

/* Lit une touche à la volée!!! */
int getkey() {
	INPUT_RECORD touch;
	DWORD attente;
	DWORD lus = 0;
	int c = -1;
	GetNumberOfConsoleInputEvents(hStdIn, &attente);
	if (attente != 0) {
		ReadConsoleInput(hStdIn, &touch, 1, &lus);
		if (touch.EventType == KEY_EVENT) {
			if (touch.Event.KeyEvent.bKeyDown == 1) {
				c = touch.Event.KeyEvent.uChar.AsciiChar;
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_UP) {
					c = 301;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_DOWN) {
					c = 302;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
					c = 303;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
					c = 304;
				}
			}
		}
	}
	if (c == 0)
		c = -1;
	return c;
}
int getkeyblock() {
	INPUT_RECORD touch;
	DWORD attente;
	DWORD lus = 0;
	int c;
	do {
		GetNumberOfConsoleInputEvents(hStdIn, &attente);
		ReadConsoleInput(hStdIn, &touch, 1, &lus);
		if (touch.EventType == KEY_EVENT) {
			if (touch.Event.KeyEvent.bKeyDown == 1) {
				c = touch.Event.KeyEvent.uChar.AsciiChar;
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_UP) {
					c = 301;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_DOWN) {
					c = 302;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_LEFT) {
					c = 303;
				}
				if (touch.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT) {
					c = 304;
				}
			}
		}
	} while ((attente == 0) && ((c < 301) && (c > 304)) && (c != 13));
	return c;
}

/* Fonction qui retourne un nombre au hasard entre 0 et 1 */
double rnd(void) {
	double nombre;
	nombre = 10 * (rand() / (PI * rand()));
	nombre = nombre - floor(nombre);
	return nombre;
}

/* Fonction qui ouvre un fichier dans la variable globale fichier à une certaine balise */

int ouvrir(char fich[10], char balise[10]) {
	int c = -1;
	char test[50];
	fichier = fopen(fich, "r");
	while (c == -1) {
		fscanf(fichier, "%s", test);
		if (strcmp(test, balise) == 0) {
			c = 1;
		}
		if (strcmp(test, "fin") == 0) {
			c = 0;
		}
	}
	return c;
}

void initmenu(menu *toc, char fich[10], char balise[10]) {
	int g;
	ouvrir(fich, balise);
	fscanf(fichier, "%d", &toc->taille);
	fscanf(fichier, "%d", &toc->x);
	fscanf(fichier, "%d", &toc->y);
	fscanf(fichier, "%d", &toc->boxcolor);
	fscanf(fichier, "%d", &toc->colorchoix);
	fscanf(fichier, "%d", &toc->colorelement);
	for (g = 0; g < toc->taille; g++) {
		lireligne(toc->chaine[g]);
	}
	fclose(fichier);
}

/* Fonction de gestion de menus */
int menubox(menu *current) {
	int i;
	int c = -1;
	int key;
	int keycours = 0;
	int longchaine;
	longchaine = pluslongchaine(current->chaine, current->taille);
	box((WORD) current->boxcolor, (int) current->x, (int) current->y,
			(int) longchaine + 3, (int) 2 * current->taille);
	for (i = 0; i < (*current).taille; i++) {
		colorlocate(current->chaine[i], current->x + 2, current->y + 1 + 2 * i,
				(WORD) current->colorelement);
		color((WORD) current->colorelement, current->x + 1,
				current->y + 1 + 2 * i, longchaine + 2);
	}
	while (c == -1) {
		colorlocate(current->chaine[keycours], current->x + 2,
				current->y + 1 + 2 * keycours, (WORD) current->colorchoix);
		color((WORD) current->colorchoix, current->x + 1,
				current->y + 1 + 2 * keycours, longchaine + 2);
		key = getkeyblock();
		if (key == 302) {
			colorlocate(current->chaine[keycours], current->x + 2,
					current->y + 1 + 2 * keycours,
					(WORD) current->colorelement);
			color((WORD) current->colorelement, current->x + 1,
					current->y + 1 + 2 * keycours, longchaine + 2);
			if (keycours < current->taille - 1) {
				keycours++;
			} else {
				keycours = 0;
			}
			c = -1;
		}
		if (key == 301) {
			colorlocate(current->chaine[keycours], current->x + 2,
					current->y + 1 + 2 * keycours,
					(WORD) current->colorelement);
			color((WORD) current->colorelement, current->x + 1,
					current->y + 1 + 2 * keycours, longchaine + 2);
			if (keycours > 0) {
				keycours--;
			} else {
				keycours = current->taille - 1;
			}
			c = -1;
		}
		if (key == 13) {
			c = keycours;
		}
	}
	FlushConsoleInputBuffer(hStdIn);
	return keycours;
}

void lireligne(char ligne[80]) {
	int i = 0;
	char c;
	c = fgetc(fichier);
	c = fgetc(fichier);
	do {
		ligne[i] = c;
		i++;
		c = fgetc(fichier);
	} while (c != '\n');
	ligne[i] = '\0';
}

void sleep(double sec) {
	clock_t goal;
	goal = (long) (sec * CLOCKS_PER_SEC) + clock();
	while (goal > clock())
		;
}

WORD colorLettreHasard(void) {
	return (WORD) (16 * rnd() + 1);
}

WORD colorFondHasard(void) {
	return (WORD) (16 * (int) (16 * rnd()));
}

int dialogIntBox(char c[80], int x, int y, int taille, WORD couleurboite,
		WORD couleurchoix) {
	int rep;
	COORD point;
	point.X = x + 2;
	point.Y = y + 3;
	box(couleurboite, x, y, taille, 5);
	locate(c, x + 2, y + 1);
	box(couleurchoix, x + 2, y + 3, taille - 4, 0);
	lignelettre1(" ", x + 2, y + 3, taille - 4, couleurchoix, faux);
	SetConsoleCursorPosition(hStdOut, point);
	scanf("%d", &rep);
	return rep;
}

void dialogCharBox(char *reponse, char c[80], int x, int y, int taille,
		WORD couleurboite, WORD couleurchoix) {
	COORD point;

	point.X = x + 2;
	point.Y = y + 3;
	box(couleurboite, x, y, taille, 5);
	locate(c, x + 2, y + 1);
	box(couleurchoix, x + 2, y + 3, taille - 4, 0);
	lignelettre1(" ", x + 2, y + 3, taille - 4, couleurchoix, faux);
	SetConsoleCursorPosition(hStdOut, point);
	scanf("%s", reponse);

}
