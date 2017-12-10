#include "biblio.h"

void lignelettre0(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	for (i = x; i >= longueur; i--) {
		colorlocate(c, i, y, couleur);
		if (paf == vrai) {
			sleep(0.001);
		}
	}
}
void lignelettre1(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	for (i = x; i < longueur + x; i++) {
		colorlocate(c, i, y, couleur);
		if (paf == vrai) {
			sleep(0.001);
		}
	}
}
void colonnelettre0(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	for (i = y; i >= longueur; i--) {
		colorlocate(c, x, i, couleur);
		if (paf == vrai) {
			sleep(0.001);
		}
	}
}
void colonnelettre1(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	for (i = y; i < longueur + y; i++) {
		colorlocate(c, x, i, couleur);
		if (paf == vrai) {
			sleep(0.001);
		}
	}
}
void diagolettre(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	int j;
	for (i = 0; i < longueur; i++) {
		for (j = 0; j < longueur; j++) {
			if (j == i) {
				colorlocate(c, x + i, y + j, couleur);
				if (paf == vrai) {
					sleep(0.001);
				}
			}
		}
	}
}

void diagolettre1(char c[1], int x, int y, int longueur, WORD couleur,
		booleen paf) {
	int i;
	int j;
	for (i = longueur; i > 0; i--) {
		for (j = 0; j < longueur; j++) {
			if (j == longueur - i) {
				colorlocate(c, x + i, y + j, couleur);
				if (paf == vrai) {
					sleep(0.001);
				}
			}
		}
	}
}

void EXCL(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("!", x + 2, y, 3, couleur, paf);
	colonnelettre1("!", x + 2, y + 4, 1, couleur, paf);

}

void UN(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("1", x + 2, y, 5, couleur, paf);
	diagolettre1("1", x - 1, y + 1, 2, couleur, paf);
	lignelettre1("1", x, y + 4, 5, couleur, paf);
}
void DEUX(int x, int y, WORD couleur, booleen paf) {
	diagolettre1("2", x - 1, y, 2, couleur, paf);
	lignelettre1("2", x + 2, y, 1, couleur, paf);
	diagolettre("2", x + 3, y, 2, couleur, paf);
	diagolettre1("2", x, y + 2, 3, couleur, paf);
	lignelettre1("2", x, y + 4, 5, couleur, paf);
	lignelettre1("2", x + 1, y + 3, 1, couleur, paf);
}
void TROIS(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("3", x, y, 4, couleur, paf);
	colonnelettre1("3", x + 4, y + 1, 3, couleur, paf);
	lignelettre1("3", x, y + 4, 4, couleur, paf);
	lignelettre1("3", x + 2, y + 2, 2, couleur, paf);
}
void QUATRE(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("4", x + 3, y, 5, couleur, paf);
	lignelettre1("4", x, y + 2, 5, couleur, paf);
	colonnelettre1("4", x, y, 2, couleur, paf);

}

void CINQ(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("5", x, y, 5, couleur, paf);
	colonnelettre1("5", x, y, 3, couleur, paf);
	lignelettre1("5", x, y + 2, 4, couleur, paf);
	lignelettre1("5", x + 4, y + 3, 1, couleur, paf);
	lignelettre1("5", x, y + 4, 4, couleur, paf);
}
void SIX(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("5", x + 1, y, 4, couleur, paf);
	colonnelettre1("5", x, y + 1, 2, couleur, paf);
	lignelettre1("5", x + 1, y + 2, 3, couleur, paf);
	lignelettre1("5", x + 4, y + 3, 1, couleur, paf);
	lignelettre1("5", x + 1, y + 4, 3, couleur, paf);
	lignelettre1("5", x, y + 3, 1, couleur, paf);

}
void SEPT(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("7", x, y, 4, couleur, paf);
	colonnelettre1("7", x + 3, y, 5, couleur, paf);
	lignelettre1("7", x + 2, y + 2, 3, couleur, paf);
}
void HUIT(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("8", x + 1, y, 3, couleur, paf);
	colonnelettre1("8", x, y + 1, 1, couleur, paf);
	colonnelettre1("8", x + 4, y + 1, 1, couleur, paf);
	colonnelettre1("8", x, y + 3, 1, couleur, paf);
	colonnelettre1("8", x + 4, y + 3, 1, couleur, paf);
	lignelettre1("8", x + 1, y + 2, 3, couleur, paf);
	lignelettre1("8", x + 1, y + 4, 3, couleur, paf);

}
void NEUF(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("9", x + 1, y, 3, couleur, paf);
	colonnelettre1("9", x, y + 1, 1, couleur, paf);
	colonnelettre1("9", x + 4, y + 1, 2, couleur, paf);

	colonnelettre1("9", x + 4, y + 3, 1, couleur, paf);
	lignelettre1("9", x + 1, y + 2, 3, couleur, paf);
	lignelettre1("9", x, y + 4, 4, couleur, paf);
}
void ZERO(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("0", x + 1, y, 3, couleur, paf);
	colonnelettre1("0", x, y + 1, 3, couleur, paf);
	colonnelettre1("0", x + 4, y + 1, 3, couleur, paf);
	lignelettre1("0", x + 1, y + 4, 3, couleur, paf);
	diagolettre1("0", x, y + 1, 3, couleur, paf);
}
void A(int x, int y, WORD couleur, booleen paf) {
	colonnelettre0("A", x, y + 4, y + 1, couleur, paf);
	lignelettre1("A", x + 1, y, 2, couleur, paf);
	colonnelettre1("A", x + 3, y + 1, 4, couleur, paf);
	lignelettre1("A", x + 1, y + 2, 2, couleur, paf);
}

void B(int x, int y, WORD couleur, booleen paf) {
	colonnelettre0("B", x, y + 4, y, couleur, paf);
	lignelettre1("B", x, y, 4, couleur, paf);
	colonnelettre1("B", x + 4, y + 1, 1, couleur, paf);
	lignelettre0("B", x + 3, y + 2, x + 1, couleur, paf);
	colonnelettre1("B", x + 4, y + 3, 1, couleur, paf);
	lignelettre0("B", x + 3, y + 4, x + 1, couleur, paf);
}
void C(int x, int y, WORD couleur, booleen paf) {
	lignelettre0("C", x + 4, y, x + 1, couleur, paf);
	colonnelettre1("C", x, y + 1, 3, couleur, paf);
	lignelettre1("C", x + 1, y + 4, 4, couleur, paf);
}
void D(int x, int y, WORD couleur, booleen paf) {
	colonnelettre0("D", x, y + 4, y, couleur, paf);
	lignelettre1("D", x + 1, y, 3, couleur, paf);
	colonnelettre1("D", x + 4, y + 1, 3, couleur, paf);
	lignelettre0("D", x + 3, y + 4, x + 1, couleur, paf);
}
void E(int x, int y, WORD couleur, booleen paf) {
	lignelettre0("E", x + 4, y, x, couleur, paf);
	colonnelettre1("E", x, y + 1, 4, couleur, paf);
	lignelettre1("E", x + 1, y + 4, 4, couleur, paf);
	lignelettre1("E", x + 1, y + 2, 4, couleur, paf);
}
void F(int x, int y, WORD couleur, booleen paf) {
	lignelettre0("F", x + 4, y, x, couleur, paf);
	colonnelettre1("F", x, y + 1, 4, couleur, paf);
	lignelettre1("F", x + 1, y + 2, 3, couleur, paf);
}
void G(int x, int y, WORD couleur, booleen paf) {
	lignelettre0("G", x + 4, y, x + 1, couleur, paf);
	colonnelettre1("G", x, y + 1, 2, couleur, paf);
	lignelettre1("G", x + 1, y + 3, 3, couleur, paf);
	lignelettre1("G", x + 3, y + 2, 2, couleur, paf);
	colonnelettre1("G", x + 4, y + 3, 2, couleur, paf);
}
void H(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("H", x, y, 5, couleur, paf);
	lignelettre1("H", x + 1, y + 2, 3, couleur, paf);
	colonnelettre1("H", x + 4, y, 5, couleur, paf);
}
void I(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("I", x, y, 5, couleur, paf);
	colonnelettre1("I", x + 2, y + 1, 4, couleur, paf);
	lignelettre1("I", x, y + 4, 5, couleur, paf);
}
void J(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("J", x + 2, y, 3, couleur, paf);
	colonnelettre1("J", x + 3, y + 1, 3, couleur, paf);
	lignelettre0("J", x + 2, y + 4, x + 1, couleur, paf);
	lignelettre1("J", x, y + 3, 1, couleur, paf);
}
void K(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("K", x + 2, y, 5, couleur, paf);
	lignelettre1("K", x + 5, y, 1, couleur, paf);
	colonnelettre1("K", x + 3, y + 3, 1, couleur, paf);
	lignelettre1("K", x + 2, y + 2, 1, couleur, paf);
	diagolettre("K", x + 3, y + 3, 2, couleur, paf);
}

void L(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("L", x, y, 5, couleur, paf);
	lignelettre1("L", x + 1, y + 4, 4, couleur, paf);
}
void M(int x, int y, WORD couleur, booleen paf) {
	colonnelettre0("M", x, y + 4, y, couleur, paf);
	diagolettre("M", x + 1, y + 1, 2, couleur, paf);
	diagolettre("M", x + 3, y + 1, 1, couleur, paf);
	colonnelettre1("M", x + 4, y, 5, couleur, paf);
}
void N(int x, int y, WORD couleur, booleen paf) {
	colonnelettre0("N", x, y + 4, y, couleur, paf);
	diagolettre("N", x + 1, y + 1, 3, couleur, paf);
	colonnelettre0("N", x + 4, y + 4, y, couleur, paf);
}
void O(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("O", x, y + 1, 3, couleur, paf);
	lignelettre1("O", x + 1, y + 4, 3, couleur, paf);
	colonnelettre0("O", x + 4, y + 3, y + 1, couleur, paf);
	lignelettre0("O", x + 3, y, x + 1, couleur, paf);

}
void P(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("P", x, y, 5, couleur, paf);
	lignelettre1("P", x + 1, y, 3, couleur, paf);
	colonnelettre1("P", x + 4, y + 1, 1, couleur, paf);
	lignelettre0("P", x + 3, y + 2, x + 1, couleur, paf);
}
void Q(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("Q", x, y + 1, 3, couleur, paf);
	lignelettre1("Q", x + 1, y + 4, 3, couleur, paf);
	colonnelettre0("Q", x + 4, y + 3, y + 1, couleur, paf);
	lignelettre0("Q", x + 3, y, x + 1, couleur, paf);
	diagolettre("Q", x + 3, y + 3, 3, couleur, paf);
}
void R(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("R", x, y, 5, couleur, paf);
	lignelettre1("R", x + 1, y, 3, couleur, paf);
	colonnelettre1("R", x + 4, y + 1, 1, couleur, paf);
	lignelettre0("R", x + 3, y + 2, x + 1, couleur, paf);
	diagolettre("R", x + 3, y + 3, 2, couleur, paf);
}
void S(int x, int y, WORD couleur, booleen paf) {
	lignelettre0("S", x + 3, y, x + 1, couleur, paf);
	colonnelettre1("S", x, y + 1, 1, couleur, paf);
	lignelettre1("S", x + 1, y + 2, 3, couleur, paf);
	colonnelettre1("S", x + 4, y + 3, 1, couleur, paf);
	lignelettre0("S", x + 3, y + 4, x + 1, couleur, paf);
}
void T(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("T", x + 2, y + 1, 4, couleur, paf);
	lignelettre1("T", x, y, 5, couleur, paf);
}
void U(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("U", x, y, 4, couleur, paf);
	lignelettre1("U", x + 1, y + 4, 3, couleur, paf);
	colonnelettre0("U", x + 4, y + 3, y, couleur, paf);
}
void V(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("V", x, y, 2, couleur, paf);
	diagolettre("V", x, y + 2, 3, couleur, paf);
	diagolettre("V", x + 3, y + 3, 1, couleur, paf);
	diagolettre("V", x + 4, y + 2, 1, couleur, paf);
	colonnelettre0("V", x + 4, y + 1, y, couleur, paf);
}
void W(int x, int y, WORD couleur, booleen paf) {
	colonnelettre1("W", x, y, 3, couleur, paf);
	diagolettre("W", x, y + 3, 2, couleur, paf);
	diagolettre("W", x + 3, y + 4, 1, couleur, paf);
	colonnelettre1("W", x + 2, y + 3, 1, couleur, paf);
	diagolettre("W", x + 4, y + 3, 1, couleur, paf);
	colonnelettre0("W", x + 4, y + 2, y, couleur, paf);
}
void X(int x, int y, WORD couleur, booleen paf) {
	diagolettre("X", x, y, 5, couleur, paf);
	diagolettre("X", x + 3, y + 1, 1, couleur, paf);
	diagolettre("X", x + 4, y, 1, couleur, paf);
	diagolettre("X", x + 1, y + 3, 1, couleur, paf);
	diagolettre("X", x, y + 4, 1, couleur, paf);
}
void Y(int x, int y, WORD couleur, booleen paf) {
	diagolettre("Y", x, y, 3, couleur, paf);
	diagolettre("Y", x + 4, y, 1, couleur, paf);
	diagolettre("Y", x + 3, y + 1, 1, couleur, paf);
	colonnelettre1("Y", x + 2, y + 3, 2, couleur, paf);
}
void Z(int x, int y, WORD couleur, booleen paf) {
	lignelettre1("Z", x, y, 5, couleur, paf);
	diagolettre("Z", x + 3, y + 1, 1, couleur, paf);
	diagolettre("Z", x + 2, y + 2, 1, couleur, paf);
	diagolettre("Z", x + 1, y + 3, 1, couleur, paf);
	lignelettre1("Z", x, y + 4, 5, couleur, paf);
}

void grille2(char c[1], int x, int y, int longueur, WORD couleur) {
	int i;
	for (i = 52; i >= x; i = i - 5) {
//		colonnelettre1("||",x,y,longueur,couleur,paf);
	}
}

void affiche_nom(char nom[50], int x, int y, WORD couleur, booleen paf) {
	int i;
	int longueur;
	longueur = strlen(nom);
	for (i = 0; i < longueur; i++) {
		switch (nom[i]) {
		case 'A':
			A(6 * i + x, y, couleur, paf);
			break;
		case 'B':
			B(6 * i + x, y, couleur, paf);
			break;
		case 'C':
			C(6 * i + x, y, couleur, paf);
			break;
		case 'D':
			D(6 * i + x, y, couleur, paf);
			break;
		case 'E':
			E(6 * i + x, y, couleur, paf);
			break;
		case 'F':
			F(6 * i + x, y, couleur, paf);
			break;
		case 'G':
			G(6 * i + x, y, couleur, paf);
			break;
		case 'H':
			H(6 * i + x, y, couleur, paf);
			break;
		case 'I':
			I(6 * i + x, y, couleur, paf);
			break;
		case 'J':
			J(6 * i + x, y, couleur, paf);
			break;
		case 'K':
			K(6 * i + x, y, couleur, paf);
			break;
		case 'L':
			L(6 * i + x, y, couleur, paf);
			break;
		case 'M':
			M(6 * i + x, y, couleur, paf);
			break;
		case 'N':
			N(6 * i + x, y, couleur, paf);
			break;
		case 'O':
			O(6 * i + x, y, couleur, paf);
			break;
		case 'P':
			P(6 * i + x, y, couleur, paf);
			break;
		case 'Q':
			Q(6 * i + x, y, couleur, paf);
			break;
		case 'R':
			R(6 * i + x, y, couleur, paf);
			break;
		case 'S':
			S(6 * i + x, y, couleur, paf);
			break;
		case 'T':
			T(6 * i + x, y, couleur, paf);
			break;
		case 'U':
			U(6 * i + x, y, couleur, paf);
			break;
		case 'V':
			V(6 * i + x, y, couleur, paf);
			break;
		case 'W':
			W(6 * i + x, y, couleur, paf);
			break;
		case 'X':
			X(6 * i + x, y, couleur, paf);
			break;
		case 'Y':
			Y(6 * i + x, y, couleur, paf);
			break;
		case 'Z':
			Z(6 * i + x, y, couleur, paf);
			break;
		case '1':
			UN(6 * i + x, y, couleur, paf);
			break;
		case '2':
			DEUX(6 * i + x, y, couleur, paf);
			break;
		case '3':
			TROIS(6 * i + x, y, couleur, paf);
			break;
		case '4':
			QUATRE(6 * i + x, y, couleur, paf);
			break;
		case '5':
			CINQ(6 * i + x, y, couleur, paf);
			break;
		case '6':
			SIX(6 * i + x, y, couleur, paf);
			break;
		case '7':
			SEPT(6 * i + x, y, couleur, paf);
			break;
		case '8':
			HUIT(6 * i + x, y, couleur, paf);
			break;
		case '9':
			NEUF(6 * i + x, y, couleur, paf);
			break;
		case '0':
			ZERO(6 * i + x, y, couleur, paf);
			break;
		case '@':
			EXCL(6 * i + x, y, couleur, paf);
			break;
		}

	}
}

void affiche_nom_joli(char nom[50], int x, int y, booleen paf) {
	int i;
	int longueur;
	longueur = strlen(nom);
	for (i = 0; i < longueur; i++) {
		switch (nom[i]) {
		case 'a':
		case 'A':
			A(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'b':
		case 'B':
			B(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'c':
		case 'C':
			C(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'd':
		case 'D':
			D(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'e':
		case 'E':
			E(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'f':
		case 'F':
			F(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'g':
		case 'G':
			G(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'h':
		case 'H':
			H(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'i':
		case 'I':
			I(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'j':
		case 'J':
			J(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'k':
		case 'K':
			K(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'l':
		case 'L':
			L(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'm':
		case 'M':
			M(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'n':
		case 'N':
			N(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'o':
		case 'O':
			O(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'p':
		case 'P':
			P(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'q':
		case 'Q':
			Q(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'r':
		case 'R':
			R(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 's':
		case 'S':
			S(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 't':
		case 'T':
			T(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'u':
		case 'U':
			U(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'v':
		case 'V':
			V(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'w':
		case 'W':
			W(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'x':
		case 'X':
			X(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'y':
		case 'Y':
			Y(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case 'z':
		case 'Z':
			Z(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '1':
			UN(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '2':
			DEUX(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '3':
			TROIS(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '4':
			QUATRE(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '5':
			CINQ(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '6':
			SIX(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '7':
			SEPT(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '8':
			HUIT(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '9':
			NEUF(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '0':
			ZERO(6 * i + x, y, colorLettreHasard(), paf);
			break;
		case '@':
			EXCL(6 * i + x, y, colorLettreHasard(), paf);
			break;
		}

	}
}
void animIntro(void) {
	int x = 15, y = 0;

	char c = -1;
	booleen paf;
	paf = faux;
	box(FROUGE | BVERT, 0, 0, 80, 25);

	for (y = 30; y >= 7; y--) {

		M(x, y, colorLettreHasard(), paf);
		O(x + 7, y + 2, colorLettreHasard(), paf);
		N(x + 14, y + 4, colorLettreHasard(), paf);
		O(x + 21, y + 6, colorLettreHasard(), paf);
		P(x + 28, y + 8, colorLettreHasard(), paf);
		O(x + 35, y + 10, colorLettreHasard(), paf);
		L(x + 42, y + 12, colorLettreHasard(), paf);
		Y(x + 49, y + 14, colorLettreHasard(), paf);
		sleep(0.07);
		box(FVERT | BVERT, x, y, 55, 20);

	}

	for (y = 7; y >= -6; y--) {

		M(x, 7, colorLettreHasard(), paf);

		if (y + 2 <= 7) {
			O(x + 7, 7, colorLettreHasard(), paf);
		} else {
			O(x + 7, y + 2, colorLettreHasard(), paf);
		}

		if (y + 4 <= 7) {
			N(x + 14, 7, colorLettreHasard(), paf);
		} else {
			N(x + 14, y + 4, colorLettreHasard(), paf);
		}

		if (y + 6 <= 7) {
			O(x + 21, 7, colorLettreHasard(), paf);
		} else {
			O(x + 21, y + 6, colorLettreHasard(), paf);
		}

		if (y + 8 <= 7) {
			P(x + 28, 7, colorLettreHasard(), paf);
		} else {
			P(x + 28, y + 8, colorLettreHasard(), paf);
		}

		if (y + 10 <= 7) {
			O(x + 35, 7, colorLettreHasard(), paf);
		} else {
			O(x + 35, y + 10, colorLettreHasard(), paf);
		}

		if (y + 12 <= 7) {
			L(x + 42, 7, colorLettreHasard(), paf);
		} else {
			L(x + 42, y + 12, colorLettreHasard(), paf);
		}
		if (y + 14 <= 7) {
			Y(x + 49, 7, colorLettreHasard(), paf);
		} else {
			Y(x + 49, y + 14, colorLettreHasard(), paf);
		}

		sleep(0.07);
		box(FVERT | BVERT, x, y, 55, 20);
	}
	for (x = 15; (x > 3) && (c == -1); x = x - 3) {

		cadre("*", x - 2, 5, 57, 9, FBLEU | BVERT);
		cadre("*", 0, 0, 80, 25, FROUGE | BTURQ);

		M(x, 7, colorLettreHasard(), paf);
		O(x + 7, 7, colorLettreHasard(), paf);
		N(x + 14, 7, colorLettreHasard(), paf);
		O(x + 21, 7, colorLettreHasard(), paf);
		P(x + 28, 7, colorLettreHasard(), paf);
		O(x + 35, 7, colorLettreHasard(), paf);
		L(x + 42, 7, colorLettreHasard(), paf);
		Y(x + 49, 7, colorLettreHasard(), paf);
		sleep(0.07);
		box(FVERT | BVERT, x - 2, 5, 57, 9);
		c = getkey();
	}
	do {
		for (x = 3; (x < 24) && (c == -1); x = x + 3) {

			cadre("*", x - 2, 5, 57, 9, FBLEU | BVERT);
			cadre("*", 0, 0, 80, 25, FROUGE | BTURQ);

			M(x, 7, colorLettreHasard(), paf);
			O(x + 7, 7, colorLettreHasard(), paf);
			N(x + 14, 7, colorLettreHasard(), paf);
			O(x + 21, 7, colorLettreHasard(), paf);
			P(x + 28, 7, colorLettreHasard(), paf);
			O(x + 35, 7, colorLettreHasard(), paf);
			L(x + 42, 7, colorLettreHasard(), paf);
			Y(x + 49, 7, colorLettreHasard(), paf);
			sleep(0.07);
			box(FVERT | BVERT, x - 2, 5, 57, 9);
			c = getkey();
		}
		for (x = 24; (x > 3) && (c == -1); x = x - 3) {
			cadre("*", x - 2, 5, 57, 9, FBLEU | BVERT);
			cadre("*", 0, 0, 80, 25, FROUGE | BTURQ);
			M(x, 7, colorLettreHasard(), paf);
			O(x + 7, 7, colorLettreHasard(), paf);
			N(x + 14, 7, colorLettreHasard(), paf);
			O(x + 21, 7, colorLettreHasard(), paf);
			P(x + 28, 7, colorLettreHasard(), paf);
			O(x + 35, 7, colorLettreHasard(), paf);
			L(x + 42, 7, colorLettreHasard(), paf);
			Y(x + 49, 7, colorLettreHasard(), paf);
			sleep(0.07);
			box(FVERT | BVERT, x - 2, 5, 57, 9);
			c = getkey();
		}

	} while (c == -1);
	cls();
	box(FROUGE | BVERT, 0, 0, 80, 25);
	cadre("*", 0, 0, 80, 25, FROUGE | BTURQ);

	affiche_nom_joli("MONOPOLY", 15, 7, faux);
	cadre("*", 13, 5, 51, 9, FBLEU | BVERT);
}

void initpaysg(void) {
	box(BBLEUC, 0, 0, 80, 23);
	lignelettre1(" ", 0, 25, 80, BGRIS, faux);
	lignelettre1(" ", 0, 24, 80, BGRIS, faux);
	lignelettre1(" ", 75, 0, 5, BJAUNE, faux);
	lignelettre1(" ", 75, 1, 5, BJAUNE, faux);
	lignelettre1(" ", 75, 2, 5, BJAUNE, faux);
	lignelettre1(" ", 75, 3, 5, BJAUNE, faux);
}
void initpaysp(void) {
	box(BBLEUC, 0, 0, 80, 9);
	lignelettre1(" ", 0, 11, 80, BGRIS, faux);
	lignelettre1(" ", 0, 10, 80, BGRIS, faux);
	lignelettre1(" ", 77, 0, 3, BJAUNE, faux);
	lignelettre1(" ", 77, 1, 3, BJAUNE, faux);

}

void cadre(char c[3], int x, int y, int L, int l, WORD couleur) {
	lignelettre1(c, x, y, L, couleur, faux);
	lignelettre1(c, x, y + l - 1, L, couleur, faux);
	colonnelettre1(c, x, y, l, couleur, faux);
	colonnelettre1(c, x + L - 1, y, l, couleur, faux);
}

void Dessintrain(int x, int y) {
	lignelettre1(" ", x, y + 4, 6, BVERT, faux);
	lignelettre1(" ", x, y + 3, 5, BVERT, faux);
	lignelettre1(" ", x + 3, y + 2, 1, BROUGE, faux);
	lignelettre1(" ", x, y + 2, 2, BVERT, faux);
	lignelettre1(" ", x + 1, y + 5, 1, BNOIR, faux);
	lignelettre1(" ", x + 3, y + 5, 1, BNOIR, faux);

}
void Dessincompagnie(int x, int y, WORD couleur) {
	lignelettre1(" ", x, y + 1, 5, couleur, faux);
	lignelettre1(" ", x, y + 2, 5, couleur, faux);
	lignelettre1(" ", x, y + 3, 5, couleur, faux);
	lignelettre1(" ", x + 4, y, 1, couleur, faux);

}
void Dessinpanneau(void) {
	lignelettre1(" ", 30, 8, 3, BROUGE, faux);
	lignelettre1(" ", 30, 7, 3, BROUGE, faux);
	lignelettre1(" ", 32, 9, 1, BGRIS, faux);

}
void Animejoueur(void) {
	int a;

	for (a = -5; a <= 15; a++) {
		box(BBLEUC, 0, 0, 30, 9);
		Dessinpion(a, 9);

		sleep(0.07);
	}

}
void Dessinpion(int x, int y) {

	lignelettre1(" ", x + 1, y, 1, BNOIR, faux);
	lignelettre1(" ", x + 3, y, 1, BNOIR, faux);
	lignelettre1(" ", x, y - 1, 5, BROUGE, faux);
	lignelettre1(" ", x, y - 2, 5, BROUGE, faux);
	lignelettre1(" ", x + 1, y - 3, 3, BROUGE, faux);
	lignelettre1(" ", x + 1, y - 4, 3, BROUGE, faux);

}

void innPropriete(void) {

	cls();
	initpaysp();
	Dessinpanneau();

	cadre("*", 0, 12, 80, 13, BBLEU);

	Animejoueur();
	sleep(.5);
	box(BVERT, 40, 1, 35, 8);

	affiche_nom("PROP", 47, 3, BNOIR, faux);

}
void innGare(void) {
	initpaysp();
	cadre("*", 0, 12, 80, 13, BGRIS | BBLANC);
	box(BGRIS, 31, 1, 24, 8);
	Animejoueur();

	box(BGRIS, 31, 1, 24, 8);
	sleep(.5);
	Animetrain();
}

void Animetrain(void) {
	int a;

	for (a = 48; a <= 85; a++) {
		box(BBLEUC, 55, 3, 25, 8);
		Dessintrain(a, 4);

		box(BGRIS, 31, 1, 24, 8);
		lignelettre1(" ", 0, 11, 80, BGRIS, faux);
		lignelettre1(" ", 0, 10, 80, BGRIS, faux);
		sleep(0.05);

	}

}

void innComp(void) {
	initpaysp();
	cadre("*", 0, 12, 80, 13, BROUGE | FBLANC);
	box(BBLANC, 31, 1, 24, 8);
	affiche_nom("CIE", 35, 3, FNOIR | BGRIS, faux);
	Animejoueur();
}

void innVisiteprison(void) {
	initpaysg();

	Dessinprison();
	Animegeantjoueur1();
	sleep(.25);
	locate("VISITE", 40, 19);
	sleep(.25);
	Traversejoueurprison2();

}
void Animegeantjoueur1(void) {
	int a;

	for (a = -5; a <= 15; a++) {
		box(BBLEUC, 0, 0, 25, 23);
		Dessinpion(a, 23);

		sleep(0.07);
	}
}

void dessinBarreaux(int x, int y) {

	lignelettre1(" ", x, y, 7, BNOIR, faux);
	lignelettre1(" ", x, y + 4, 7, BNOIR, faux);
	colonnelettre1(" ", x, y, 5, BNOIR, faux);
	colonnelettre1(" ", x + 2, y, 5, BNOIR, faux);
	colonnelettre1(" ", x + 4, y, 5, BNOIR, faux);
	colonnelettre1(" ", x + 6, y, 5, BNOIR, faux);

}

void Traversejoueurprison2(void) {
	int a;

	for (a = 15; a <= 85; a++) {

		initpaysg();
		Dessinprison();
		locate("VISITE", 40, 19);
		Dessinpion(a, 23);
		sleep(0.05);
	}

}

void Dessinprison(void) {
	box(BGRIS, 31, 0, 24, 23);
	dessinBarreaux(34, 3);
	dessinBarreaux(46, 3);
	dessinBarreaux(34, 13);
	dessinBarreaux(46, 13);
	dessinBarreaux(34, 13);
	dessinBarreaux(46, 13);

	locate("PRISON", 40, 1);

}

void Dessinjoueurinprison(void) {
	box(BGRIS, 31, 0, 24, 23);
	dessinBarreaux(34, 3);
	dessinBarreaux(46, 3);
	dessinBarreaux(34, 13);
	dessinBarreaux(46, 13);
	dessinBarreaux(34, 13);
	dessinBarreaux(46, 13);

	locate("PRISON", 40, 1);
	Dessinpion(35, 17);
	dessinBarreaux(34, 13);
}

void innPrison(void) {
	initpaysg();
	Dessinprison();
	Animegeantjoueur1();
	sleep(.25);
	box(BNOIR, 40, 19, 5, 4);
	locate("EN PRISON!!!", 40, 18);
	sleep(.25);
	Traversejoueurprison1();

}

void Traversejoueurprison1(void) {
	int a;

	for (a = 15; a <= 50; a++) {
		if (a % 2 == 0) {
			box(BBLANC, 0, 0, 80, 23);
		} else {
			box(BROUGE, 0, 0, 80, 23);
		}
		if (a >= 47) {
			box(BBLEUC, 0, 0, 80, 23);
		}

		lignelettre1(" ", 0, 25, 80, BGRIS, faux);
		lignelettre1(" ", 0, 24, 80, BGRIS, faux);
		lignelettre1(" ", 75, 0, 5, BJAUNE, faux);
		lignelettre1(" ", 75, 1, 5, BJAUNE, faux);
		lignelettre1(" ", 75, 2, 5, BJAUNE, faux);
		lignelettre1(" ", 75, 3, 5, BJAUNE, faux);
		Dessinprison();
		box(BNOIR, 40, 19, 5, 4);
		locate("EN PRISON!!!", 40, 18);
		Dessinpion(a, 23);
		box(BGRIS, 46, 19, 9, 4);
		sleep(0.1);
	}

	Dessinjoueurinprison();
}
void outjoueurprison(void) {
	int a;

	initpaysg();
	Dessinjoueurinprison();
	sleep(.5);
	box(BNOIR, 40, 19, 5, 4);
	locate("SORTIE!", 40, 18);
	sleep(.5);

	for (a = 31; a < 85; a++) {
		initpaysg();
		Dessinprison();
		box(BNOIR, 40, 19, 5, 4);
		locate("SORTIE!", 40, 18);
		Dessinpion(a, 23);
		box(BGRIS, 31, 19, 8, 8);
		sleep(0.05);
	}
}

void psgeDep(void) {
	int a;
	initpaysg();

	Animegeantjoueur1();
	affiche_nom_joli("CASE DEPART", 5, 1, faux);
	for (a = 100; a >= 30; a = a - 1) {
		locate("      ", a + 6, 12);
		box(BBLEUC, 30, 6, 50, 17);
		box(BVERT, a, 10, 20, 5);
		locate("+20000", a + 5, 12);
		box(FBLEUC | BBLEUC, 0, 6, 10, 10);
		sleep(.05);

	}
	for (a = 15; a < 85; a++) {

		box(BBLEUC, 0, 18, 80, 5);
		Dessinpion(a, 23);
		sleep(0.01);
	}
}

void innParc(void) {
	int a;
	initpaysg();
	box(BVERT, 30, 20, 25, 3);
	Animegeantjoueur1();
	sleep(.5);
	affiche_nom_joli("PARC LIBRE", 5, 5, faux);

	for (a = 15; a < 85; a++) {

		box(BBLEUC, 0, 18, 80, 5);
		Dessinpion(a, 23);
		box(BVERT, 30, 20, 25, 3);
		sleep(0.01);
	}

}

void CaisseC(void) {
	int a;
	initpaysp();
	cadre("*", 0, 12, 80, 13, BBLEU | FBLEUC);
	box(BBLEU, 35, 6, 5, 3);
	lignelettre1(" ", 37, 6, 2, BBLANC, faux);
	lignelettre1(" ", 37, 7, 2, BBLANC, faux);
	locate("Caisse de Communaute", 35, 2);
	Animejoueur();
	sleep(.5);
	//ici tu dois faire ce qu'il faut pr ce type de case

	for (a = 15; a < 85; a++) {
		initpaysp();
		box(BBLEU, 35, 6, 5, 3);
		lignelettre1(" ", 37, 6, 2, BBLANC, faux);
		lignelettre1(" ", 37, 7, 2, BBLANC, faux);

		Dessinpion(a, 9);
		sleep(0.01);
	}

}
void CarteCh(void) {
	int a;
	initpaysp();
	cadre("*", 0, 12, 80, 13, BBLEU | FBLEUC);
	box(BROUGE, 35, 6, 5, 3);
	lignelettre1(" ", 37, 6, 2, BBLANC, faux);
	lignelettre1(" ", 37, 7, 2, BBLANC, faux);
	locate("Carte Chance", 35, 2);
	Animejoueur();
	sleep(.5);
	//ici tu dois faire ce qu'il faut pr ce type de case

	for (a = 15; a < 85; a++) {
		initpaysp();
		box(BROUGE, 35, 6, 5, 3);
		lignelettre1(" ", 37, 6, 2, BBLANC, faux);
		lignelettre1(" ", 37, 7, 2, BBLANC, faux);
		Dessinpion(a, 9);

		sleep(0.01);
	}

}
void innimpotRev(void) {
	int a;
	initpaysg();
	Animegeantjoueur1();
	affiche_nom_joli("IMPOT", 15, 1, faux);
	locate("sur le revenu", 45, 5);
	for (a = 100; a >= 30; a = a - 1) {
		locate("      ", a + 6, 12);
		box(BBLEUC, 30, 6, 50, 17);
		box(BROUGE, a, 10, 20, 5);
		locate("-20000", a + 5, 12);
		box(FBLEUC | BBLEUC, 0, 6, 10, 10);
		sleep(.05);

	}
	for (a = 15; a < 85; a++) {

		box(BBLEUC, 0, 18, 80, 5);
		Dessinpion(a, 23);
		sleep(0.01);
	}

}

void inntaxeLux(void) {
	int a;
	initpaysg();
	Animegeantjoueur1();
	affiche_nom_joli("TAXE", 15, 1, faux);
	locate("de luxe", 45, 5);
	for (a = 100; a >= 30; a = a - 1) {
		locate("      ", a + 6, 12);
		box(BBLEUC, 30, 6, 50, 17);
		box(BROUGE, a, 10, 20, 5);
		locate("-10000", a + 5, 12);
		box(FBLEUC | BBLEUC, 0, 6, 10, 10);
		sleep(.05);

	}
	for (a = 15; a < 85; a++) {

		box(BBLEUC, 0, 18, 80, 5);
		Dessinpion(a, 23);
		sleep(0.01);
	}

}

void gagne(void) {
	initpaysg();
	Animegeantjoueur1();

}
void perdu(void) {
	int a;
	initpaysp();
	box(BGRIS, 44, 4, 6, 5);
	box(BNOIR, 45, 5, 4, 4);
	Animejoueur();
	for (a = 15; a < 46; a++) {

		initpaysp();
		box(BGRIS, 44, 4, 6, 5);
		box(BNOIR, 45, 5, 4, 4);
		Dessinpion(a, 9);
		sleep(0.05);
	}
	for (a = 9; a < 30; a++) {

		initpaysp();
		box(BGRIS, 44, 4, 6, 5);
		box(BNOIR, 45, 5, 4, 4);
		box(BNOIR, 0, 12, 80, 13);
		Dessinpion(45, a);
		sleep(0.05);
	}
	cadre("*", 0, 12, 80, 13, colorLettreHasard());
	affiche_nom_joli("PERDU@@@@", 15, 17, vrai);

}
