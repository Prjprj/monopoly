#ifndef MONOINIT
#define MONOINIT
	#include "biblio.h"
	void initplateau(char[20], Case_*, propriete*, station*, compagnies*);
	void initpropriete(char[20], propriete*);
	void initgare(char[20], station*);
	void initcompagnie(char[20], compagnies*);
	void initchance(char[20], card*);
	void initcaisse(char[20], card*);
	void initcouleurtab(propriete*, int*);
#endif
