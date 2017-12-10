#ifndef lololib
#define lololib
	#include "biblio.h"
	void initprgm(void);
	void cls(void);
	void colorscreen(WORD);
	void color(WORD, int, int, int);
	void box(WORD, int, int, int, int);
	int locate(char[80], int, int);
	int colorlocate(char[80], int, int, WORD);
	int getkey(void);
	int getkeyblock(void);
	double rnd(void);
	int ouvrir(char[10], char[10]);
	void lireligne(char[50]);
	void initmenu(menu*, char[10], char[10]);
	int menubox(menu*);
	int pluslongchaine(char[50][50], int);
	void sleep(double);
	WORD colorLettreHasard(void);
	WORD colorFondHasard(void);
	int dialogIntBox(char[80], int, int, int, WORD, WORD);
	void dialogCharBox(char *, char[80], int, int, int, WORD, WORD);
#endif
